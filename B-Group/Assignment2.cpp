#include<bits/stdc++.h>
using namespace std;


string toLower(string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s; 
}

bool isFound(vector<string> v, string input){
    for(auto word : v){
        if(input.find(word) != std::string::npos){
             return true;
        }
    }
    return false;
}

void getResponse(string input){
    string lowerInput = toLower(input);

    vector<pair<vector<string>, string>> responses = {
    {{"math", "algebra", "calculus", "geometry", "trigonometry", "statistics"}, 
     "Mathematics is a vast field! Algebra helps with equations, Calculus studies change and motion, Geometry deals with shapes, Trigonometry focuses on angles, and Statistics analyzes data. What specific topic do you need help with?"},

    {{"physics", "newton", "motion", "electricity", "magnetism", "optics", "quantum"}, 
     "Physics explains the laws of nature! Newton's laws govern motion, Electricity and Magnetism power technology, Optics studies light, and Quantum Mechanics explores the subatomic world. Which area interests you?"},

    {{"computer", "programming", "c++", "python", "java", "javascript", "algorithms", "data structures"}, 
     "Programming is an essential skill! C++ is great for systems and game development, Python is widely used in AI and automation, Java powers enterprise applications, and JavaScript is key for web development. Do you need help with a specific language or topic?"},

    {{"history", "past", "war", "ancient", "medieval", "modern", "world war", "revolution"}, 
     "History teaches us valuable lessons! Ancient history covers early civilizations, Medieval history explores feudal societies, Modern history includes industrialization and globalization, and World Wars shaped the 20th century. Which era are you interested in?"},

    {{"biology", "cells", "genetics", "evolution", "ecology", "microbiology"}, 
     "Biology is the study of life! Cells are the building blocks of life, Genetics explains inheritance, Evolution describes species changes, Ecology studies ecosystems, and Microbiology explores microscopic life. What would you like to learn?"},

    {{"chemistry", "atoms", "molecules", "organic", "inorganic", "periodic table"}, 
     "Chemistry explains matter and its interactions! Atoms and molecules form substances, Organic chemistry studies carbon compounds, Inorganic chemistry covers minerals and metals, and the Periodic Table organizes elements. Need help with a concept?"},

    {{"science", "astronomy", "geology", "environment", "space", "earth"}, 
     "Science helps us understand the universe! Astronomy studies celestial bodies, Geology examines Earth's structure, Environmental science focuses on sustainability, and Space exploration uncovers the unknown. What topic intrigues you?"},

    {{"study tips", "focus", "concentration", "memory", "productivity", "learning strategies"}, 
     "Effective study techniques can enhance learning! The Pomodoro technique manages time, Active Recall improves retention, Mind Mapping visualizes ideas, and Spaced Repetition strengthens memory. Need specific study advice?"},

    {{"career", "job", "future", "internship", "resume", "skills", "networking"}, 
     "Career planning is important! Tech fields include cybersecurity and AI, Healthcare offers roles in medicine and research, and Business covers finance and entrepreneurship. Would you like advice on job hunting or skill-building?"},

    {{"language", "english", "grammar", "vocabulary", "writing", "speaking"}, 
     "Language skills are crucial! Grammar builds sentence structure, Vocabulary enhances expression, Writing develops communication, and Speaking boosts fluency. Do you need help with a specific area?"},

    {{"philosophy", "ethics", "logic", "existence", "human nature"}, 
     "Philosophy explores deep questions! Ethics studies morality, Logic examines reasoning, Existence questions reality, and Human Nature investigates behavior. What philosophical topic interests you?"},

    {{"psychology", "mind", "behavior", "cognition", "mental health"}, 
     "Psychology helps us understand thoughts and behavior! Cognition studies how we learn, Behavior explores human actions, and Mental Health is vital for well-being. Do you have a specific area in mind?"},

    {{"technology", "AI", "cybersecurity", "blockchain", "cloud computing", "big data"}, 
     "Technology is evolving rapidly! AI powers automation, Cybersecurity protects data, Blockchain secures transactions, Cloud Computing scales businesses, and Big Data drives insights. What would you like to learn more about?"},

    {{"health", "fitness", "nutrition", "mental health", "sleep", "stress"}, 
     "Health is the key to well-being! Exercise boosts energy, Nutrition fuels the body, Sleep improves brain function, and Stress management is crucial. Need any wellness tips?"},

    {{"economics", "finance", "investing", "markets", "trade", "inflation"}, 
     "Economics and finance shape the world! Investing grows wealth, Markets drive trade, and Inflation affects purchasing power. Need help with financial concepts?"},

    {{"bye", "exit", "quit", "goodbye", "see you", "farewell"}, 
     "Goodbye! Keep learning, stay curious, and come back anytime for more knowledge!"}
};
    vector<string> answers;
    for(auto it : responses){
        if(isFound(it.first, lowerInput)){
            answers.push_back(it.second);
        }
    }

    if(!answers.empty()){{
        for(auto word : answers){
            cout<<word<<endl;
        }
        return;
    }}

    cout<<"I'm not sure about that. Could you specify your question?"<<endl;
}

int main(){
    cout<<"Welcome to Study ChatBot to answer your education related questions"<<endl;

    string userInput;

    while(true){
        cout << "You: ";
        getline(cin, userInput);

        if (toLower(userInput) == "bye") {
            cout << "Chatbot: Goodbye! Keep learning!" << endl;
            break;
        }

        cout << "Chatbot: "<<endl;
        getResponse(userInput);
    }
    return 0;
}