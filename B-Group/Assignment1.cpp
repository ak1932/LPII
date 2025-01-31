#include<bits/stdc++.h>
using namespace std;




bool fits(int row, int col,vector<vector<string>> board,  int n ){
    for (int i = 0; i < n; i++) {
    if (board[row][i] == " [Q] " || board[i][col] == " [Q] ") return false;
  }

  int i= row, j= col;

  while(i>=0 && j>=0){
      if(board[i][j]== " [Q] " )  return false;
      i--;
      j--;
  }

  i= row, j= col;

  while(i<n && j<n){
      if(board[i][j]== " [Q] " )  return false;
      i++;
      j++;
  }

  i= row, j= col;

  while(i>=0 && j<n){
      if(board[i][j]== " [Q] " )  return false;
      i--;
      j++;
  }

  i= row, j= col;

  while(i<n && j>=0){
      if(board[i][j]== " [Q] " )  return false;
      i++;
      j--;
  }


  return true;
}

bool fits2(int row, int col, vector<vector<string>>& board, int n, vector<bool>& rows, vector<bool>& diag1, vector<bool>& diag2) {
    if (rows[row] || diag1[row + col] || diag2[row - col + (n - 1)]) {
        return false;
    }
    return true;
}


void Backtracking(vector<vector<string>> board, int col, int n, int &count){
       if(col>=n){
          count++;
          for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }cout<<endl;
          }cout<<endl;
        //   found = true;
          return;
       }

       for(int i=0; i<n; i++){
           if(fits(i,col, board, n)){
              board[i][col] = " [Q] ";
            
              Backtracking(board, col+1, n, count);
            //    if(found) return;
              board[i][col] = " [ ] ";

           }
       }

}


void BB(vector<vector<string>> board, int col, int n, int &count, vector<bool> &row, vector<bool> &diag1, vector<bool> &diag2){
      if(col>=n){
        count++;
          for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }cout<<endl;
          }cout<<endl;
        //   found = true;
          return;
       }
       
       for(int i=0; i<n; i++){
           if(fits2(i,col, board, n, row, diag1, diag2)){
              board[i][col] = " [Q] ";
              row[i] = true;
              diag1[i+col] = true;
              diag2[i - col + (n - 1)] = true;
              BB(board, col+1, n, count, row, diag1, diag2);
            //    if(found) return;
              row[i] = false;
              diag1[i+col] = false;
              diag2[i - col + (n - 1)] = false;
              board[i][col] = " [ ] ";

           }
       }

}

int main(){
      int n;
      cout<<"Enter the size of board: ";
      cin>>n;
      vector<vector<string>> board(n,vector<string>(n," [ ] "));

      int ch = -1;

      while(true){
        
         cout<<"1. Backtracking "<<endl;
         cout<<"2. Branch and Bound "<<endl;
         
         cout<<"Enter a choice : ";
         cin>>ch;

         if(ch == 1){
             int count1 = 0;
            Backtracking(board, 0, n, count1);
            cout<<"No of solution possible is : "<<count1<<endl;
         }
         else if(ch == 2){
             vector<bool> row(n, false);
            vector<bool> diag1(2*n+1, false);
            vector<bool> diag2(2*n+1, false);
            int count2 = 0;
            BB(board, 0, n , count2 , row, diag1, diag2);
             cout<<"No of solution possible is : "<<count2<<endl;
         }
         else{
            break;
         }

      }
      
    
}