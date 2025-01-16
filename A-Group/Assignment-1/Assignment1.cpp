#include<bits/stdc++.h>
using namespace std;


void addEdge (vector<vector<int>> &adj, int s, int t){
    adj[s].push_back(t);
    adj[t].push_back(s);
}


void DFS (vector<vector<int>> &adj, vector<int> &vis, int idx, int s, int &flag){
    cout<<idx<<" ";
    vis[idx] = 1;
    if(idx == s){
        flag = 1;
        return;
   }
    
    // cout<<idx<<" ";
    for(auto it : adj[idx]){
        if(vis[it] == 0){
            if(flag == 1){
                return;
             }
             DFS(adj, vis, it, s, flag);
             
        }
    }
}

void BFS(vector<vector<int>> &adj, vector<int> &vis2, int &element){
     queue<int> q;

        q.push(0);
        
        vis2[0] = 1;

        cout<<" BFS : ";
        while(!q.empty()){
            int e = q.front();
            cout<<e<<" ";
            if(e == element){
                break;
            }
            q.pop();

            for(auto it : adj[e]){
                if(vis2[it] == 0){
                    vis2[it] = 1;
                    q.push(it);
                }
            }
        }
}


int main() {

        int n;
        cout<<"Enter the number of edges: ";
        cin>>n;


        vector<vector<int>> adj(n+1);
        
        cout<<"Start Entering the pairs"<<endl;
        for(int i=0; i<=n; i++){
                cout<<"Enter first number ";
                int s;
                cin>>s;
                cout<<"Enter second number ";
                int t;
                cin>>t;
                addEdge(adj, s, t);
        }

        vector<int> vis1(n+1, 0);
        int flag = 0;
        cout<<"Enter the element to search: ";
        int element1;
        cin>>element1;
        cout<<" DFS : ";
        DFS(adj, vis1, 0, element1 , flag);

        cout<<endl;

        vector<int> vis2(n+1, 0);
        
       cout<<"Enter the element to search: ";
        int element2;
        cin>>element2;
        BFS (adj, vis2, element2);

         

     
}