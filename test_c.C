
#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"


void test_c(string applyOn){
    std::string tempo = applyOn;
    TString tempoTwo = tempo;

    // This loads the library
    TMVA::Tools::Instance();


    std::ofstream test_cpp("test_cpp");
    //event_scores.open("data_all_arca8_scores.csv",fstream::app);
    //event_scores<<"run"<<" "<<"sub_run"<<" "<<"evt_id"<<" "<<"n_type"<<" "<<"bdt_score"<<std::endl;

    TFile *input;
    if (!gSystem->AccessPathName( applyOn.c_str() )){
        input = TFile::Open(applyOn.c_str() );
        std::cout << "oppening file: "<< applyOn.c_str()<<std::endl;
    }
    TMVA::Reader *reader = new TMVA::Reader( "!Color:!Silent" );
    //TTree * inputTree_data = (TTree*)input->Get("ProcessedEvents_forBDT");
    TTree * inputTree_data = (TTree*)input->Get("ProcessedEvents;1");

    int pseudo_runid,pseudo_subRunid, counter;
    counter = 0;
    float pseudo_livetime,evt_id,evt_num, zenith, jlik, Slen, logbeta0, neutrino_type, cos_zen;

    inputTree_data->SetBranchAddress("pseudo_runid", &pseudo_runid); //(int)
    inputTree_data->SetBranchAddress("pseudo_subRunid", &pseudo_subRunid); //(int)
    inputTree_data->SetBranchAddress("pseudo_livetime", &pseudo_livetime);
    inputTree_data->SetBranchAddress("evt_id", &evt_id);
    inputTree_data->SetBranchAddress("evt_num", &evt_num);
    inputTree_data->SetBranchAddress("zenith", &zenith);
    inputTree_data->SetBranchAddress("jlik", &jlik);
    inputTree_data->SetBranchAddress("Slen", &Slen); 
    inputTree_data->SetBranchAddress("neutrino_type", &neutrino_type);
    inputTree_data->SetBranchAddress("logbeta0", &logbeta0);
    inputTree_data->SetBranchAddress("cos_zen", &cos_zen);
    

    //TH1D Lik ("Lik","; Likelihood", 700,-100,600);

    //TFile* outputFile = new TFile("./../forBDT_processed_mine_forBDT_mine_"+ tempo +".root","RECREATE");
    //std::unique_ptr<TFile> outputFile( TFile::Open("./../forBDT_processed_mine_forBDT_mine_"+ tempoTwo +".root", "RECREATE") );
    
    //TH1D CosZen ("CosZen","; Cos(reco_zenith)",100,-1,1);
    //TH1D f1 ("f1","; example",100,-1,1);
    //TFile* file = new TFile(applyOn, "READ");
    //TIter next(file->GetListOfKeys());
    //TKey* key;




   //auto cnt_r_h = new TH1F("count_rate", "Count Rate;N_{Counts};# occurencies",  100, // Number of Bins
   // 80, // Lower X Boundary
   // 180); // Upper X Boundary
   for (int i=0;i<inputTree_data->GetEntries();i++){
        inputTree_data->GetEntry(i);
        if((pseudo_runid == 10000 && neutrino_type == -14 && ((evt_id == 580) || (evt_id == 586) || (evt_id == 430) || (evt_id == 692))) ||
        (pseudo_runid == 9707 && neutrino_type == -14 && ((evt_id == 540) || (evt_id == 510) || (evt_id == 520) || (evt_id == 530)))){
                test_cpp << evt_id << " " << pseudo_runid << " " << cos_zen << " " << jlik << " " << Slen << ' '<< logbeta0 << '\n'; 
        }
        //if(pseudo_runid == 10000 && jlik > 50 && Slen > 100 && neutrino_type == -14 && logbeta0 < -1.5) cnt_r_h->Fill(zenith);

    }

   //auto c  = new TCanvas();
   //cnt_r_h->Draw();
    //TTree* outputTree_data = new TTree("ProcessedEvents_forBDT","");
    //outputTree_data->SetDirectory(outputFile);

    /*
    outputTree_data->Branch("pseudo_runid", &pseudo_runid, "run_number/I"); //(int)
    outputTree_data->Branch("pseudo_subRunid", &pseudo_subRunid, "run_subNumber/I"); //(int)
    outputTree_data->Branch("pseudo_livetime", &pseudo_livetime, "pseudo_livetime/F"); 
    outputTree_data->Branch("evt_id", &evt_id, "evt_id/F"); 
    outputTree_data->Branch("evt_num", &evt_num, "evt_num/F"); 

    double bdt_score;
    int counter=0;*/
  //Start the event loop
    //for( int i=0 ; i<inputTree_data->GetEntries(); i++ ){
    /*
        inputTree_data->GetEntry(i);

        bdt_score = reader->EvaluateMVA( "BDT method" );
        event_scores<<pseudo_runid<<" "<<pseudo_subRunid<<" "<<evt_id<<" "<<std::endl;

        if(logEreco > 2.7 && jlik >50.0 && TrLengthIT_2 >100.0 && logbeta0 <-1.5 && float_num_triggered_doms>=5){
        if(zenith > 90){
        counter++;
        outputTree_data->Fill();
        }}
        if(zenith > 90){
	      counter++;
          outputTree_data->Fill();
        f1.Fill(counter);
	        
       }
    }
    f1.Draw();*/
    //outputFile->WriteObject(&outputTree_data, "outputTree_data");
    
    //end of event loop
    //printf(zenith,"%d");
  //event_scores.close();
  //outputFile->Write();
  //outputFile->Close();
//  read_from_file();

}
