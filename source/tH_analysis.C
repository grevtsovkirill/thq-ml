#define tH_analysis_cxx
// The class definition in tH_analysis.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("tH_analysis.C")
// root> T->Process("tH_analysis.C","some options")
// root> T->Process("tH_analysis.C+")
//


#include "tH_analysis.h"
#include <TH2.h>
#include "TMath.h"
#include <TStyle.h>
#include <TCanvas.h>

TH1F *h_Njet[10][10];
TH1F *h_jetPt[10][10];
TH1F *h_cutflow_2l[2];
//vector<string> variables={"N","pt"};
vector<string> jt={"","b","f"};
double b_tag_cut=0.83;

string input_name="";

// vector<double> bins_dr={0, 0.4, 0.8, 1.2, 1.6, 2, 2.4, 2.8, 3.2, 3.6, 4};
// vector<double> bins_n={2,3,4,5,6,7};
// vector<double> bins_pt={25,45,65,85,100,150,200};
// vector<double> bins_eta = {-2.5,-2.25,-1.75, -1.5,-1,-0.75,-0.5,-0.25,0,0.25, 0.5,0.75, 1,1.25, 1.5,1.75, 2,2.25, 2.5};
// vector<vector<double>> vec_range = {bins_n,bins_pt,bins_eta};

void tH_analysis::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   std::cout << "option ="<< option << std::endl;
   input_name=option;

}

void tH_analysis::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   char hname[1000];
   for(int i=0;i<jt.size();i++){
     for(int j=0;j<1;j++){ //variables.size()
       sprintf(hname,"N%sjet",jt[i].c_str()); 
       h_Njet[i][j]=new TH1F(hname,hname,9, -0.5, 8.5);
       sprintf(hname,"%sjet_pT",jt[i].c_str()); //,variables[j].c_str()
       h_jetPt[i][j]=new TH1F(hname,hname,100,0,1000);
     }
   }
   
   //1(mumu) 2(OF) 3(ee) 
   const std::vector<TString> s_cutDescs =
     {  "Preselections","Nleps","tight*/prompt","lepPt>20","lepCentr","SS","jPt","bCentr","qforwE","mm","OF","ee"};
   int Ncuts = s_cutDescs.size();
   h_cutflow_2l[0] = new TH1F("cf2l","cf2l",Ncuts,0,Ncuts);
   h_cutflow_2l[1] = new TH1F("cf2l_raw","cf2l_raw",Ncuts,0,Ncuts);
   for (int bin=1;bin<=Ncuts;++bin){
     h_cutflow_2l[0]->GetXaxis()->SetBinLabel(bin,s_cutDescs[bin-1]);
     h_cutflow_2l[1]->GetXaxis()->SetBinLabel(bin,s_cutDescs[bin-1]);
   }
}

Bool_t tH_analysis::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

  //fReader.SetEntry(entry);
  fReader.SetLocalEntry(entry);
  weight_tot=*weight_mc * *weight_pileup *  *weight_leptonSF *  *weight_globalLeptonTriggerSF * *weight_jvt;
  int cf_counter=0;
  //presel
  h_cutflow_2l[0]->Fill(cf_counter,weight_tot);  h_cutflow_2l[1]->Fill(cf_counter,1);
  cf_counter++;

  nJet = jet_pt.GetSize();
  nEl = el_pt.GetSize();
  nMu = mu_pt.GetSize();
  const int totleptons = nEl+nMu;
  int dilep_type = 1 + nEl;//  1(mumu) 2(OF) 3(ee)
  //Nlep
  if(totleptons!=2) return 0;
  h_cutflow_2l[0]->Fill(cf_counter,weight_tot);  h_cutflow_2l[1]->Fill(cf_counter,1);
  cf_counter++;

  bool lep_tight=true;
  for (int iEl = 0; iEl < nEl; ++iEl) {
    if( el_true_isPrompt[iEl]==0)lep_tight=false;
  }
  for (int iMu = 0; iMu < nMu; ++iMu) {
    if( mu_true_isPrompt[iMu]==0)lep_tight=false;
  }

  if(!lep_tight) return 0;
  h_cutflow_2l[0]->Fill(cf_counter,weight_tot);  h_cutflow_2l[1]->Fill(cf_counter,1);
  cf_counter++;

  //std::cout << "nEl="<<nEl<<", nMu="<<nMu << std::endl;
  float l0_charge,l1_charge;  
  float l0_pt,l1_pt;
  float l0_eta,l1_eta;
  if ( dilep_type==1 ){ 
    l0_charge= mu_charge[0]; l1_charge= mu_charge[1];
    l0_eta= mu_eta[0]; l1_eta= mu_eta[1];
    l0_pt= mu_pt[0]/1e3; l1_pt= mu_pt[1]/1e3;
  }
  if ( dilep_type==3 ){ 
    l0_charge= el_charge[0]; l1_charge= el_charge[1];
    l0_eta= el_eta[0]; l1_eta= el_eta[1];
    l0_pt= el_pt[0]/1e3; l1_pt= el_pt[1]/1e3;
  }
  if ( dilep_type==2 ){ 
    if(mu_pt[0]>el_pt[0]){ 
      l0_charge= mu_charge[0]; l1_charge= el_charge[0];
      l0_eta= mu_eta[0]; l1_eta= el_eta[0];
      l0_pt= mu_pt[0]/1e3; l1_pt= el_pt[0]/1e3;
    }
    else{    
      l1_charge= mu_charge[0]; l0_charge= el_charge[0];
      l1_eta= mu_eta[0]; l0_eta= el_eta[0];
      l1_pt= mu_pt[0]/1e3; l0_pt= el_pt[0]/1e3;
    }
  }

  //lep Pt cuts
  if(l0_pt<20||l1_pt<20) return 0;  
  h_cutflow_2l[0]->Fill(cf_counter,weight_tot);  h_cutflow_2l[1]->Fill(cf_counter,1);
  cf_counter++;

  //lep eta cuts
  if(abs(l0_eta)>2.5||abs(l1_eta)>2.5) return 0;  
  h_cutflow_2l[0]->Fill(cf_counter,weight_tot);  h_cutflow_2l[1]->Fill(cf_counter,1);
  cf_counter++;

  float charges=l0_charge*l1_charge;
  //SS
  if(charges<0) return 0;
  h_cutflow_2l[0]->Fill(cf_counter,weight_tot);  h_cutflow_2l[1]->Fill(cf_counter,1);
  cf_counter++;
  

  int nB=0;
  int nBf=0;
  int nc=0;
  int nf=0;
  int nfE=0;
  bool jetpt_pass=true;
  for (int iJet = 0; iJet < nJet; ++iJet) {
    if(jet_pt[iJet]/1e3<25){
      jetpt_pass=false;
    }

    if(jet_pt[iJet]/1e3>25){
      if(abs(jet_eta[iJet])<2.5){ 
	nc++;
	if(jet_mv2c10[iJet]>b_tag_cut){
	  //Found bjet:
	  nB++;
	}//b	
      }//central
      
      if(abs(jet_eta[iJet])>2.5){ 
	nf++;
	if(jet_pt[iJet]/1e3>40) nfE++;
      }
    }//pt>25
  }

  //jetpt
  if(jetpt_pass==false) return 0;  
  h_cutflow_2l[0]->Fill(cf_counter,weight_tot);  h_cutflow_2l[1]->Fill(cf_counter,1);
  cf_counter++;

  //central b
  if(nB<1) return 0;  
  h_cutflow_2l[0]->Fill(cf_counter,weight_tot);  h_cutflow_2l[1]->Fill(cf_counter,1);
  cf_counter++;

  //std::cout << "nJet="<<nJet<< ", nB="<< nB <<", nBc="<< nBc << ", nf="<< nf << ", nfE="<< nfE << std::endl;
  //energetic forward
  if(nfE<1) return 0;  
  h_cutflow_2l[0]->Fill(cf_counter,weight_tot);  h_cutflow_2l[1]->Fill(cf_counter,1);

  //Flavour
  h_cutflow_2l[0]->Fill(cf_counter+dilep_type,weight_tot);  h_cutflow_2l[1]->Fill(cf_counter+dilep_type,1);
  //cf_counter=cf_counter+4;
  cf_counter++;
  

  h_Njet[0][0]->Fill(nc,weight_tot);
  h_Njet[1][0]->Fill(nB,weight_tot);
  h_Njet[2][0]->Fill(nfE,weight_tot);
  for (int iJet = 0; iJet < nJet; ++iJet) {
      if(abs(jet_eta[iJet])<2.5){ 
	h_jetPt[0][0]->Fill(jet_pt[iJet]/1000.,weight_tot);
	if(jet_mv2c10[iJet]>b_tag_cut){
	  h_jetPt[1][0]->Fill(jet_pt[iJet]/1000.,weight_tot);	  
	}//b	
      }//central
      
      if(abs(jet_eta[iJet])>2.5){ 
	nf++;
	if(jet_pt[iJet]/1e3>40) h_jetPt[2][0]->Fill(jet_pt[iJet]/1000.,weight_tot);
      }
  }
  
   return kTRUE;
}

void tH_analysis::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void tH_analysis::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
  string outname="Res_"+input_name+".root";
  TFile hfile(outname.c_str(),"RECREATE"); //,"tHq"
  h_cutflow_2l[0]->Write(); 
  h_cutflow_2l[1]->Write(); 
  for(int i=0;i<jt.size();i++){  
    h_jetPt[i][0]->Write(); 
    h_Njet[i][0]->Write(); 
  }
  fOutput->Write();

  // //Example to retrieve output from output list
  // TCanvas c_result("cresult","Resistance",100,100,300,300);
  // //h_jet[0][0]->Draw();
  // h_cutflow_2l[0]->Draw();
  // c_result.SaveAs("ResistanceDistribution.png");

}
