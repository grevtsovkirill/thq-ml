void run(string name="tHq", string comp="a"){
  TChain *ch=new TChain("nominal");
  string choose_tag="";
  if(comp.find("a")!= std::string::npos) choose_tag="9364"; 
  else if(comp.find("d")!= std::string::npos) choose_tag="10201";
  else if(comp.find("e")!= std::string::npos) choose_tag="10724";

  cout<< "comp= "<<comp<<", tag= "<< choose_tag<< endl;

  //ch->Add("../../Files/user.cescobar.mc16_13TeV.346230.aMcPy8_tHjb125_4fl_lep.SGTOP1.e7318_a875_r10201_p3714.ll.v28_out.root/*.root");
  string path="/nfs/dust/atlas/group/top/tHq_ML/Files/"+name+"/user.cescobar.mc16_13TeV.346230.aMcPy8_tHjb125_4fl_lep.SGTOP1.e7318_a875_r10201_p3714.ll.v28_out.root/*.root";
  //string path="/nfs/dust/atlas/group/top/tHq_ML/Files/"+name+"/user.*_r"+choose_tag+"_p3714.ll.v28_out.root/*.root";
  cout << "path = " << path<< endl;

  ch->Add(path.c_str());
  cout << ch->GetNtrees()<< ", entr: "<< ch->GetEntries()<< endl;
  //eventually, start Proof Lite on cores
  //TProof::Open("workers=4");
  //ch->SetProof();
  ch->Process("tH_analysis.C+",name.c_str());
}
