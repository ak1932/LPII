#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int s, int t){
    adj[s].push_back(t);
    adj[t].push_back(s);
}

bool DFS(vector<vector<int>> adj, vector<int> &vis, int idx, int targ, vector<int> &path){
    cout<<idx<<endl;
    vis[idx] = 1;
    path.push_back(idx);

    if(idx == targ){
        return true;
    }

    for(auto i : adj[idx]){
        if(!vis[i]){
            if(DFS(adj, vis, i, targ, path)){
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}


bool BFS(vector<vector<int>> adj, vector<int> &vis, int s, int targ, vector<int> &path){
    vector<int> parent(adj.size(), -1);
    queue<int> q;
   

    q.push(s);

    vis[s] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
                parent[it] = node;
            }
        }
    }


    if(!vis[targ]) return false;


    int i=targ;
    while(i != -1){
        path.push_back(i);
        i = parent[i];
    }

    reverse(path.begin(), path.end());

    return true;
}
 
int main()
{
   
    cout<<"Enter the number of node: ";
    int n;
    cin>>n;
    
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n; i++){
        int s;
        int t;
        cout<<"Enter the first node: ";
        cin>>s;
        cout<<"Enter the second node: ";
        cin>>t;
        addEdge(adj, s, t);
    }

    int ch;
    int d;
    cout<<"Enter the destination node: ";
    cin>>d;
    while(true){
        cout<<"1. DFS"<<endl;
        cout<<"2. BFS"<<endl;
        cout<<"Enter a choice: ";
        cin>>ch;
        vector<int> vis(n+1, 0);
        vector<int> path;
        int s;
        cout<<"Enter start index ";
        cin>>s;
        if(ch == 1){
              if(DFS(adj, vis, s, d, path )){
                cout<<"Path: ";
                for(int i=0; i<path.size(); i++){
                    cout<<path[i]<<" ";
                }cout<<endl;
              }
              else{
                cout<<"No path possible"<<endl;
              }
        }
        else if(ch == 2){
            if(BFS(adj, vis, s , d, path )){
              cout<<"Path: ";
              for(int i=0; i<path.size(); i++){
                  cout<<path[i]<<" ";
              }cout<<endl;
            }
            else{
              cout<<"No path possible"<<endl;
            }
      }
      else{
        break;
      }
    }
   return 0;
}