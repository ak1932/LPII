#include<bits/stdc++.h>
using namespace std;


// 1)  Selection Sort   

void selection_sort(){
     int n;
     cout<<"Size of array: ";
     cin>>n;

     vector<int> v(n);
     cout<<"Enter the inputs: ";
     for(int i=0; i<n; i++){
        cin>>v[i];
     }

     for(int i=0; i<n; i++){
        int mini = i;
        for(int j=i+1; j<n; j++){
            if(v[j] < v[mini]){
                mini = j;
        }
    }

        swap(v[i], v[mini]);

     }

    cout<<"Output Array : ";
     for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
     }cout<<endl;


     cout<<"Time Complexity: Best Case : O(1)  Worst Case : O(N^2)"<<endl;
}


// 2) Prims Algorithm

void PrimsAlgorithm (){
   
    vector<vector<int>> edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}};
     int n = edges.size();
    vector<vector<pair<int,int>>> adj(5);
    
    for(int i=0; i<n; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u,w});
    }

    vector<int> vis(5,0);
    vector<pair<int, int>> path;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

    pq.push({0, {0,-1}});
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        if(vis[it.second.first]){
            continue;
        }

        vis[it.second.first] = 1;
        sum += it.first;
        if(it.second.second != -1){
            path.push_back({it.second.second , it.second.first});
        }


        for(auto i : adj[it.second.first]){
            if(!vis[i.first]){
                pq.push({i.second, {i.first, it.second.first}});
            }
        }
    }

    cout<<"Sum of path: "<< sum<<endl;

    cout<<"path: "<<endl;
    for(auto it : path){
        cout<<it.first<<"->"<<it.second<<endl;
    }


    cout<<"Time Complexity: O(E*log(E))  where E is edges"<<endl;
}


// 3) Dijkstra's Algorithm

void DijkstraAlgorithm() {
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    int n = edges.size();
    int num = 5;  
    vector<vector<pair<int, int>>> adj(num); 

    
    for (int i = 0; i < n; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        int w = edges[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(num, INT_MAX);  
    vector<int> parent(num, -1);  

    int s;
    cout << "Enter the source: ";
    cin >> s;
    s -= 1;  
    dist[s] = 0;
    pq.push({0, s});

    
    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        
        if (dis > dist[node]) continue;

        
        for (auto it : adj[node]) {
            int N = it.first;
            int w = it.second;

            
            if (dis + w < dist[N]) {
                dist[N] = dis + w;
                parent[N] = node;
                pq.push({dist[N], N});
            }
        }
    }

    int d;
    cout << "Enter the destination: ";
    cin >> d;
    d -= 1;  

    if (dist[d] == INT_MAX) {
        cout << "No path to the destination" << endl;
    } else {
        cout << "Distance: " << dist[d] << endl;

      
        vector<int> path;
        int i = d;

            while (i != -1) {
        path.push_back(i + 1);  
        i = parent[i];
        }
        
        
        cout << "Path: ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }

    cout<<"Time Complexity: O(N + Elog(N))"<<endl;
}






int main(){
    // selection_sort();
    // PrimsAlgorithm();
    DijkstraAlgorithm();
}
Assignment3.cpp
Displaying Assignment3.cpp.
