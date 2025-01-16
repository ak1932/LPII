#include <bits/stdc++.h>
using namespace std;

// int X_MAX = 1000;
// int Y_MAX = 500;
// int X_STEP = 20;
// int Y_STEP = 20;

struct Node {
    int x;
    int y;
    int X;  
    int Y;
    float gcost;
    float hcost;
    float fcost;

    bool operator<(const Node& other) const {
        return fcost > other.fcost; 
    }
};

bool isValid(int x, int y, const vector<vector<int>>& grid) {
    return !(x < 0 || y < 0 || x >= 7 || y >= 8 || grid[x][y] == 1);
}

bool isDestination(int x, int y, Node dest) {
    return x == dest.x && y == dest.y;
}

// Euclidean Distance
double CalculateH(int x, int y, Node dest) {
    return sqrt((x - dest.x) * (x - dest.x) + (y - dest.y) * (y - dest.y));
}

vector<Node> Astar(Node start, Node dest, const vector<vector<int>>& grid) {
    vector<vector<Node>> nodemap(7, vector<Node>(8));
    vector<vector<bool>> visited(7, vector<bool>(8, false));

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            nodemap[i][j].fcost = FLT_MAX;
            nodemap[i][j].gcost = FLT_MAX;
            nodemap[i][j].hcost = FLT_MAX;
            nodemap[i][j].X = -1;
            nodemap[i][j].Y = -1;
        }
    }

    int x = start.x, y = start.y;
    nodemap[x][y].x = x;
    nodemap[x][y].y = y;
    nodemap[x][y].fcost = 0.0;
    nodemap[x][y].gcost = 0.0;
    nodemap[x][y].hcost = 0.0;
    nodemap[x][y].X = x;
    nodemap[x][y].Y = y;

    priority_queue<Node> pq;
    pq.push(nodemap[x][y]);

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        
        x = current.x;
        y = current.y;
        if (visited[x][y]) {
            continue;
        }

        cout<<"Visited --> ("<<x<<","<<y<<")"<<endl;

        visited[x][y] = true;

        if (isDestination(x, y, dest)) {
            vector<Node> path;
            while (!(current.x == start.x && current.y == start.y)) {
                path.push_back(current);
                int temp_X = current.X;
                int temp_Y = current.Y;
                current = nodemap[temp_X][temp_Y];
            }
            path.push_back(start);
            reverse(path.begin(), path.end()); 
            return path;
        }
         cout<<"Choices ---> ";
        for (int i = 0; i < 8; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (isValid(new_x, new_y, grid) && !visited[new_x][new_y]) {
                float g = current.gcost + (sqrt(dx[i]*dx[i] + dy[i]*dy[i]));
                float h = CalculateH(new_x, new_y, dest);
                float f = g + h;

                if (nodemap[new_x][new_y].fcost > f) {
                    nodemap[new_x][new_y].x = new_x;
                    nodemap[new_x][new_y].y = new_y;
                    nodemap[new_x][new_y].fcost = f;
                    nodemap[new_x][new_y].gcost = g;
                    nodemap[new_x][new_y].hcost = h;
                    nodemap[new_x][new_y].X = x;
                    nodemap[new_x][new_y].Y = y;
                    cout<<"("<<nodemap[new_x][new_y].x<<","<<nodemap[new_x][new_y].y<<") (H value "<<nodemap[new_x][new_y].hcost<<") (F value "<<nodemap[new_x][new_y].fcost<<")";
                    pq.push(nodemap[new_x][new_y]);
                }
            }
        }cout<<endl;
    }

    return {};
}


void TimeComplexity(int n){
    cout<<"Time Complexity = O("<<n<<")"<<endl;
}

int main() {
    Node start{0, 0, -1, -1, 0.0, 0.0, 0.0};
    Node dest{6, 7, -1, -1, FLT_MAX, FLT_MAX, FLT_MAX};

    vector<vector<int>> grid(7, vector<int>(8, 0));

    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[4][2] = 1;
    grid[6][1] = 1;
    grid[2][4] = 1;
    grid[4][4] = 1;
    grid[2][5] = 1;
    grid[3][5] = 1;
    grid[4][5] = 1;

    vector<Node> path = Astar(start, dest, grid);

    for(auto it : path){
        cout<<" ----> ( "<<it.x<<","<<it.y<<" )";
    }
    cout<<endl;

    int n = path.size();
     
    TimeComplexity(n);

    return 0;
}