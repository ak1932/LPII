#include <bits/stdc++.h>
using namespace std;


void CheckDisease(unordered_set<string> symptom, vector<pair<string, vector<string>>> disease){
    vector<string> answers;
    vector<string> dumAnswer;
    
    for(auto it : disease){
        bool flag = false;
        for(auto dis : it.second){
            if(symptom.find(dis) == symptom.end()){
                 flag = true;
                 break;
            }
            else{
                dumAnswer.push_back(it.first);
            }
        }

        if(flag == false){
            answers.push_back(it.first);
        }
    }

    if(answers.empty()){
        cout<<"No specific disease predicted but you might have symptoms of this specific diseases according to your inputs: ";
        for(int i=0; i<dumAnswer.size(); i++){
            cout<<dumAnswer[i]<<" ";
        }
        cout<<endl;
        return;
    }


    cout<<"The disease you might have according to your symtoms: ";
    for(int i=0; i<answers.size(); i++){
            cout<<answers[i]<<" ";
    }
    cout<<endl;
    
}

int main(){

    vector<pair<string, vector<string>>> disease = {
        {"Influenza", {"fever", "cough", "fatigue"}},
        {"Common Cold", {"sneezing", "runny nose", "sore throat"}},
        {"COVID-19", {"fever", "cough", "loss of taste or smell"}},
        {"Pneumonia", {"fever", "cough", "chest pain"}},
        {"Asthma", {"shortness of breath", "wheezing", "chest tightness"}},
        {"Tuberculosis", {"persistent cough", "weight loss", "night sweats"}},
        {"Migraine", {"severe headache", "nausea", "sensitivity to light"}},
        {"Hypertension", {"frequent headaches", "dizziness", "blurred vision"}},
        {"Diabetes", {"excessive thirst", "frequent urination", "fatigue"}},
        {"Anemia", {"fatigue", "pale skin", "dizziness"}},
        {"Food Poisoning", {"nausea", "vomiting", "diarrhea"}},
        {"Appendicitis", {"severe abdominal pain", "nausea", "vomiting"}},
        {"Kidney Stones", {"severe flank pain", "blood in urine", "nausea"}},
        {"Heart Attack", {"chest pain", "shortness of breath", "left arm pain"}},
        {"Stroke", {"sudden weakness", "slurred speech", "face drooping"}},
        {"Depression", {"persistent sadness", "loss of interest", "fatigue"}},
        {"Anxiety Disorder", {"excessive worry", "restlessness", "rapid heartbeat"}}
    };

    
    cout<<"Out of the list of the following disease please check which disease you have:  fever, cough, fatigue,  sneezing, runny nose, sore throat, chest pain, shortness of breath, wheezing, chest tightness, persistent cough, diarrhea, vomiting, nausea "<<endl;

    cout<<"Please enter the number of symptoms you have: ";
    int n;
    cin>>n;

    unordered_set<string> symptom;

    for(int i=0; i<n; i++){
        string input;
        cout<<"Symptom: ";
        getline(cin, input);
        symptom.insert(input);
    }

   
   CheckDisease(symptom, disease);
    



    return 0;
}