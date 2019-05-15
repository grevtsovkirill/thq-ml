//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Apr 24 14:33:40 2019 by ROOT version 6.14/04
// from TTree nominal/tree
// found on file: ../../Files/user.cescobar.mc16_13TeV.346230.aMcPy8_tHjb125_4fl_lep.SGTOP1.e7318_a875_r10201_p3714.ll.v28_out.root/user.cescobar.17603245._000001.out.root
//////////////////////////////////////////////////////////

#ifndef tH_analysis_h
#define tH_analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class tH_analysis : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   int nJet;
   int nEl;
   int nMu;
   Double_t weight_tot;

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderArray<float> mc_generator_weights = {fReader, "mc_generator_weights"};
   TTreeReaderValue<Float_t> weight_mc = {fReader, "weight_mc"};
   TTreeReaderValue<Float_t> weight_pileup = {fReader, "weight_pileup"};
   TTreeReaderValue<Float_t> weight_leptonSF = {fReader, "weight_leptonSF"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF = {fReader, "weight_globalLeptonTriggerSF"};
   TTreeReaderValue<Float_t> weight_oldTriggerSF = {fReader, "weight_oldTriggerSF"};
   TTreeReaderValue<Float_t> weight_bTagSF_MV2c10_Continuous = {fReader, "weight_bTagSF_MV2c10_Continuous"};
   TTreeReaderValue<Float_t> weight_jvt = {fReader, "weight_jvt"};
   TTreeReaderValue<Float_t> weight_pileup_UP = {fReader, "weight_pileup_UP"};
   TTreeReaderValue<Float_t> weight_pileup_DOWN = {fReader, "weight_pileup_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Trigger_UP = {fReader, "weight_leptonSF_EL_SF_Trigger_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Trigger_DOWN = {fReader, "weight_leptonSF_EL_SF_Trigger_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Reco_UP = {fReader, "weight_leptonSF_EL_SF_Reco_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Reco_DOWN = {fReader, "weight_leptonSF_EL_SF_Reco_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_ID_UP = {fReader, "weight_leptonSF_EL_SF_ID_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_ID_DOWN = {fReader, "weight_leptonSF_EL_SF_ID_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Isol_UP = {fReader, "weight_leptonSF_EL_SF_Isol_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Isol_DOWN = {fReader, "weight_leptonSF_EL_SF_Isol_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Trigger_STAT_UP = {fReader, "weight_leptonSF_MU_SF_Trigger_STAT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Trigger_STAT_DOWN = {fReader, "weight_leptonSF_MU_SF_Trigger_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Trigger_SYST_UP = {fReader, "weight_leptonSF_MU_SF_Trigger_SYST_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Trigger_SYST_DOWN = {fReader, "weight_leptonSF_MU_SF_Trigger_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_STAT_UP = {fReader, "weight_leptonSF_MU_SF_ID_STAT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_STAT_DOWN = {fReader, "weight_leptonSF_MU_SF_ID_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_SYST_UP = {fReader, "weight_leptonSF_MU_SF_ID_SYST_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_SYST_DOWN = {fReader, "weight_leptonSF_MU_SF_ID_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP = {fReader, "weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN = {fReader, "weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP = {fReader, "weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN = {fReader, "weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Isol_STAT_UP = {fReader, "weight_leptonSF_MU_SF_Isol_STAT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Isol_STAT_DOWN = {fReader, "weight_leptonSF_MU_SF_Isol_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Isol_SYST_UP = {fReader, "weight_leptonSF_MU_SF_Isol_SYST_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Isol_SYST_DOWN = {fReader, "weight_leptonSF_MU_SF_Isol_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_TTVA_STAT_UP = {fReader, "weight_leptonSF_MU_SF_TTVA_STAT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_TTVA_STAT_DOWN = {fReader, "weight_leptonSF_MU_SF_TTVA_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_TTVA_SYST_UP = {fReader, "weight_leptonSF_MU_SF_TTVA_SYST_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_TTVA_SYST_DOWN = {fReader, "weight_leptonSF_MU_SF_TTVA_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_EL_Trigger_UP = {fReader, "weight_globalLeptonTriggerSF_EL_Trigger_UP"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_EL_Trigger_DOWN = {fReader, "weight_globalLeptonTriggerSF_EL_Trigger_DOWN"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP = {fReader, "weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN = {fReader, "weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP = {fReader, "weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN = {fReader, "weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_jvt_UP = {fReader, "weight_jvt_UP"};
   TTreeReaderValue<Float_t> weight_jvt_DOWN = {fReader, "weight_jvt_DOWN"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_Continuous_eigenvars_B_up = {fReader, "weight_bTagSF_MV2c10_Continuous_eigenvars_B_up"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_Continuous_eigenvars_C_up = {fReader, "weight_bTagSF_MV2c10_Continuous_eigenvars_C_up"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_Continuous_eigenvars_Light_up = {fReader, "weight_bTagSF_MV2c10_Continuous_eigenvars_Light_up"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_Continuous_eigenvars_B_down = {fReader, "weight_bTagSF_MV2c10_Continuous_eigenvars_B_down"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_Continuous_eigenvars_C_down = {fReader, "weight_bTagSF_MV2c10_Continuous_eigenvars_C_down"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_Continuous_eigenvars_Light_down = {fReader, "weight_bTagSF_MV2c10_Continuous_eigenvars_Light_down"};
   TTreeReaderValue<ULong64_t> eventNumber = {fReader, "eventNumber"};
   TTreeReaderValue<UInt_t> runNumber = {fReader, "runNumber"};
   TTreeReaderValue<UInt_t> randomRunNumber = {fReader, "randomRunNumber"};
   TTreeReaderValue<UInt_t> mcChannelNumber = {fReader, "mcChannelNumber"};
   TTreeReaderValue<Float_t> mu = {fReader, "mu"};
   TTreeReaderValue<UInt_t> backgroundFlags = {fReader, "backgroundFlags"};
   TTreeReaderValue<UInt_t> hasBadMuon = {fReader, "hasBadMuon"};
   TTreeReaderArray<float> el_pt = {fReader, "el_pt"};
   TTreeReaderArray<float> el_eta = {fReader, "el_eta"};
   TTreeReaderArray<float> el_cl_eta = {fReader, "el_cl_eta"};
   TTreeReaderArray<float> el_phi = {fReader, "el_phi"};
   TTreeReaderArray<float> el_e = {fReader, "el_e"};
   TTreeReaderArray<float> el_charge = {fReader, "el_charge"};
   TTreeReaderArray<char> el_CF = {fReader, "el_CF"};
   TTreeReaderArray<int> el_true_type = {fReader, "el_true_type"};
   TTreeReaderArray<int> el_true_origin = {fReader, "el_true_origin"};
   TTreeReaderArray<int> el_true_firstEgMotherTruthType = {fReader, "el_true_firstEgMotherTruthType"};
   TTreeReaderArray<int> el_true_firstEgMotherTruthOrigin = {fReader, "el_true_firstEgMotherTruthOrigin"};
   TTreeReaderArray<int> el_true_firstEgMotherPdgId = {fReader, "el_true_firstEgMotherPdgId"};
   TTreeReaderArray<char> el_true_isPrompt = {fReader, "el_true_isPrompt"};
   TTreeReaderArray<char> el_true_isChargeFl = {fReader, "el_true_isChargeFl"};
   TTreeReaderArray<float> mu_pt = {fReader, "mu_pt"};
   TTreeReaderArray<float> mu_eta = {fReader, "mu_eta"};
   TTreeReaderArray<float> mu_phi = {fReader, "mu_phi"};
   TTreeReaderArray<float> mu_e = {fReader, "mu_e"};
   TTreeReaderArray<float> mu_charge = {fReader, "mu_charge"};
   TTreeReaderArray<float> mu_ptvarcone30 = {fReader, "mu_ptvarcone30"};
   TTreeReaderArray<int> mu_true_type = {fReader, "mu_true_type"};
   TTreeReaderArray<int> mu_true_origin = {fReader, "mu_true_origin"};
   TTreeReaderArray<char> mu_true_isPrompt = {fReader, "mu_true_isPrompt"};
   TTreeReaderArray<float> jet_pt = {fReader, "jet_pt"};
   TTreeReaderArray<float> jet_eta = {fReader, "jet_eta"};
   TTreeReaderArray<float> jet_phi = {fReader, "jet_phi"};
   TTreeReaderArray<float> jet_e = {fReader, "jet_e"};
   TTreeReaderArray<float> jet_mv2c10 = {fReader, "jet_mv2c10"};
   TTreeReaderArray<char> jet_passfjvt = {fReader, "jet_passfjvt"};
   TTreeReaderArray<int> jet_truthflav = {fReader, "jet_truthflav"};
   TTreeReaderArray<int> jet_truthPartonLabel = {fReader, "jet_truthPartonLabel"};
   TTreeReaderArray<char> jet_isTrueHS = {fReader, "jet_isTrueHS"};
   TTreeReaderArray<int> jet_truthflavExtended = {fReader, "jet_truthflavExtended"};
   TTreeReaderArray<int> jet_tagWeightBin_MV2c10_Continuous = {fReader, "jet_tagWeightBin_MV2c10_Continuous"};
   TTreeReaderValue<Float_t> met_met = {fReader, "met_met"};
   TTreeReaderValue<Float_t> met_phi = {fReader, "met_phi"};
   TTreeReaderValue<UInt_t> lbn = {fReader, "lbn"};
   TTreeReaderValue<Float_t> Vtxz = {fReader, "Vtxz"};
   TTreeReaderValue<UInt_t> npVtx = {fReader, "npVtx"};
   TTreeReaderArray<char> el_tight = {fReader, "el_tight"};
   TTreeReaderArray<int> el_true_pdg = {fReader, "el_true_pdg"};
   TTreeReaderArray<float> el_true_pt = {fReader, "el_true_pt"};
   TTreeReaderArray<float> el_true_eta = {fReader, "el_true_eta"};
   TTreeReaderArray<char> mu_tight = {fReader, "mu_tight"};
   TTreeReaderArray<int> mu_true_pdg = {fReader, "mu_true_pdg"};
   TTreeReaderArray<float> mu_true_pt = {fReader, "mu_true_pt"};
   TTreeReaderArray<float> mu_true_eta = {fReader, "mu_true_eta"};
   TTreeReaderArray<float> jet_m = {fReader, "jet_m"};
   TTreeReaderValue<Float_t> met_px = {fReader, "met_px"};
   TTreeReaderValue<Float_t> met_py = {fReader, "met_py"};
   TTreeReaderValue<Float_t> met_sumet = {fReader, "met_sumet"};


   tH_analysis(TTree * /*tree*/ =0) { }
   virtual ~tH_analysis() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(tH_analysis,0);

};

#endif

#ifdef tH_analysis_cxx
void tH_analysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t tH_analysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef tH_analysis_cxx
