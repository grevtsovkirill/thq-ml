{// set up a TChain
  TChain *ch=new TChain("nominal");
  ch->Add("../../Files/user.cescobar.mc16_13TeV.346230.aMcPy8_tHjb125_4fl_lep.SGTOP1.e7318_a875_r10201_p3714.ll.v28_out.root/*.root");
  cout << ch->GetNtrees()<< ", entr: "<< ch->GetEntries()<< endl;
  // eventually, start Proof Lite on cores
  //TProof::Open("workers=4");
  //ch->SetProof();
  ch->Process("tH_analysis.C+");
}
