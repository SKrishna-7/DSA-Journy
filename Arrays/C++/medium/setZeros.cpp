#include<iostream>
#include<vector>
using namespace std;



void setZeros_brute(vector<vector<int>> &matrix){

    int n=matrix.size();  // Rows
    int m=matrix[0].size();  // Cols

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(matrix[i][j] == 0){
                
                for(int row=0;row<n;row++){
                    if(matrix[row][j] != 0)
                        matrix[row][j] = -1;
                }
                for(int col=0;col<m;col++){
                    if(matrix[i][col] != 0)
                        matrix[i][col] = -1;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }

}



void setZeros_better(vector<vector<int>> &matrix){

    int n=matrix.size();  // Rows
    int m=matrix[0].size();  // Cols

    vector<int> row_marker(n,0);
    vector<int> col_marker(m,0);



    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(matrix[i][j] == 0){
                
               row_marker[i] =1;
               col_marker[j] =1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

           if(row_marker[i] == 1 || col_marker[j] == 1){
            matrix[i][j] = 0;

           }
        }
    }

}



void setZeros_optimal(vector<vector<int>> &matrix){

    int n=matrix.size();
    int m=matrix[0].size();

    int col0=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(matrix[i][j] == 0){

                matrix[i][0] = 0;
                
                if(j!=0){
                    matrix[0][j] = 0;
                }else{
                    col0=0;
                }
            }
        }
    }


     for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            
            if (matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] =0;
            }}}

    if(matrix[0][0] == 0) {
        for(int j=0;j<n;j++) matrix[0][j] =0;
    }
    
    if(col0 == 0) {
        for(int i=0;i<n;i++) matrix[i][0] =0;
    }




}

int main(){

    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};

    // setZeros_brute(matrix);
    
    // setZeros_better(matrix);

    setZeros_optimal(matrix);  

    for(auto row:matrix){
        for(auto col:row){
            cout << col <<" ";
        }

        cout<<endl;
    }
    return 0;
}