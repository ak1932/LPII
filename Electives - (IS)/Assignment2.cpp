#include <bits/stdc++.h>
using namespace std;


string RFT_ENCRY(string word){
    int n = word.length();
    string s;
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            s += word[i];
        }
    }

    for(int i=0; i<n; i++){
        if(i%2 != 0){
            s += word[i];
        }
    }

    return s;
}

string RFT_DECRY(string word){
    int n = word.length();
    vector<vector<char>> v (2, vector<char> (n));
    
   
    int k = 0;
    for(int j=0; j<n; j++){
        if(j%2 == 0){
            v[0][j] = word[k];
            k++;
        }
    }
 
    for(int j=0; j<n; j++){
        if(j%2 != 0){
            v[1][j] = word[k];
            k++;
        }
    }

    string s;
        
 
        for(int j=0; j<n; j++){
            if(j%2 == 0){
                s += v[0][j];
            }
            else{
                s += v[1][j];
            }     
        }


        return s;
    
}



string SingleTransposition1(string key, string word){
        int n = key.length();
    int m = word.length(); 
    int row;

    
    if (m % n == 0) {
        row = m / n;
    } else {
        row = (m / n) + 1;
    }

   
    vector<vector<char>> v(row + 1, vector<char>(n, '_'));
    
    
    for (int i = 0; i < n; i++) {
        v[0][i] = key[i];
    }

    
    int k = 0;
    for (int i = 1; i <= row; i++) {
        for (int j = 0; j < n && k < m; j++) {
            v[i][j] = word[k++];
        }
    }
    
    vector<char> post;
    
    for(int i=0; i<n; i++){
       post.push_back(key[i]);
    }
    sort(post.begin(), post.end());
    
    string s;
    
    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){
            if(v[0][j] == post[i]){
                v[0][j] = '*';
                int col = j;
                for(int r = 1; r <= row; r++){
                    s += v[r][col];
                }
            }
        }
    }
    return s;
}


string SingleTransposition2(string key, string word){

    int n = key.length();
    int m = word.length();
    vector<char> post;
    int row;

    if(m%n == 0){
        row = m/n;
    }
    else{
        row = (m/n) + 1;
    }
    for(int i=0; i<n; i++){
        post.push_back(key[i]);
    }


    sort(post.begin(), post.end());
    
    vector<vector<char>> v(row+1, vector<char> (n, ' '));
    
    for(int i=0; i<n; i++){
        v[0][i] = key[i];
    }
    
    int k = 0;
    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){
            if(v[0][j] == post[i]){
                v[0][j] = '*';
                int col = j;
                for(int r = 1; r <= row; r++){
                    v[r][col] =  word[k];
                    k++; 
                }
            }
        }
    }
    cout<<"Decryption of Transpose: ";
    string s;
    for(int i=1; i<=row; i++){
        for(int j=0; j<n; j++){
            s += v[i][j];
        }
    }

    return s;
}


string DoubleTransposition1(string key, string word){
    int n = key.length();
    int m = word.length(); 
    int row;

    
    if (m % n == 0) {
        row = m / n;
    } else {
        row = (m / n) + 1;
    }

   
    vector<vector<char>> v(row + 1, vector<char>(n, '_'));
    
    
    for (int i = 0; i < n; i++) {
        v[0][i] = key[i];
    }

    
    int k = 0;
    for (int i = 1; i <= row; i++) {
        for (int j = 0; j < n && k < m; j++) {
            v[i][j] = word[k++];
        }
    }
    
    vector<char> post;
    
    for(int i=0; i<n; i++){
       post.push_back(key[i]);
    }
    sort(post.begin(), post.end());
    
    string s;
    
    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){
            if(v[0][j] == post[i]){
                v[0][j] = '*';
                int col = j;
                for(int r = 1; r <= row; r++){
                    s += v[r][col];
                }
            }
        }
    }
    return s;
}



int main(){
    string rft_enry =  RFT_ENCRY("Hello Arinjay How are you?");
    cout<<"Encrypted using RFT: "<<rft_enry<<endl;

    string rft_decry = RFT_DECRY(rft_enry);

    cout<<"Decrypted using RFT: "<<rft_decry<<endl;


    string st_encry = SingleTransposition1("heaven", "we are the best");
    cout<<"Encryption using single transposition: "<<st_encry<<endl;
    string st_decry = SingleTransposition2("heaven", st_encry);
    while(st_decry.back() == '_'){
          st_decry.pop_back();
    }
    cout<<"Decryption: "<<st_decry<<endl;

    string dt_encry = DoubleTransposition1("another", st_encry);
    cout<<"Encryption using double transposition: "<<dt_encry<<endl;

    string dt_decry1 = SingleTransposition2("another", dt_encry);
    while(dt_decry1.back() == '_'){
          dt_decry1.pop_back();
    }
    cout<<"Decryption level 1: "<<dt_decry1<<endl;

    

    string dt_decry2 = SingleTransposition2("heaven", dt_decry1);
    while(dt_decry2.back() == '_'){
          dt_decry2.pop_back();
    }
    cout<<"Decryption level 2: "<<dt_decry2<<endl;

}