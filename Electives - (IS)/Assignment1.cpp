#include<bits/stdc++.h>
using namespace std;
 
int main()
{ 

    string s;
    cout<<"Enter the string ";
    cin>>s;

    cout<<"Original String: "<<s<<endl;
    cout<<"Key:  127"<<endl;

    cout<<"AND operation: ";
    for(auto c: s){
        cout<<(c&127);
    }cout<<endl;

    cout<<"OR operation: ";
    for(auto c: s){
        cout<<(c||127);
    }cout<<endl;

    cout<<"XOR operation: ";
    for(auto c: s){
        cout<<(c^127);
    }cout<<endl;

   return 0;
}