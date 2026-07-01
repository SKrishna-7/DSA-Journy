#include<iostream>
#include<vector>

using namespace std;

bool isValid(vector<vector<string>> &board,int n,int row,int col){

    int dupRow = row;
    int dupCol = col;

    
    row = dupRow-1;
    while(row >= 0){

        if(board[row][col] == "Q"){
            return false;
        }
        row--;
    }

    row=dupRow-1;
    col=dupCol-1;

    while(row >= 0 && col >=0){

    if(board[row][col] == "Q"){
    
        return false;
    }
            row--;
            col--;
    }

    row = dupRow-1;
    col = dupCol+1;

    while(row >= 0 && col<n){

    if(board[row][col] == "Q"){
        
        return false;
    }
           
    row--;
    col++;

        }

        return true;

}

void solve(vector<vector<string>> &board,int n,vector<vector<vector<string>>> &results,int row){

    if(row == n){
        results.push_back(board);
        return ;
    }

    for(int col=0;col<n;col++){

    if(isValid(board,n,row,col)){

        board[row][col] = 'Q';
        solve(board,n,results,row+1);
        board[row][col] = '-';
        
        
    }
    }

}
int main(){

    int n=8;

    vector<vector<string>> board(n,vector<string> (n,"-"));
    vector<vector<vector<string>>> results;

    solve(board,n,results,0);
   
    for (auto &sol : results)
{

    for (auto &row : sol)
    {
        for (auto cell : row)
            cout << cell << " ";

        cout << "\n";
    }

    cout << "\n";
}
    return 0;
}