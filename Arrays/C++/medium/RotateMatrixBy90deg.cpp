#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>> rotateMatrix_brute(vector<vector<int>> &matrix){
  
    int n=matrix.size();       // Row length
    int m=matrix[0].size();     // Col length

    vector<vector<int>> res(n,vector<int>(m));


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            res[j][(n-1)-i] = matrix[i][j];
        }
    }


    return res;
}


void rotateMatrix_optimal(vector<vector<int>> &matrix){
  
    int n=matrix.size();       // Row length
    int m=matrix[0].size();     // Col length



    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){

            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }



   
}



int main(){

    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};

    // Actual matrix
    cout<<"Original Matrix : \n";
    for(auto &i:matrix){
        for(auto &val:i){
            cout<< val << " ";
        }
        cout<<endl;
    }

    
   
    cout<<"\n\n";
    // cout<<"Rotated Matrix : \n";
    // // Rotated matrix
    // for(auto &i:rotateMatrix_brute(matrix)){
    //     for(auto &val:i){
    //         cout<< val << " ";
    //     }
    //     cout<<endl;
    // }
    
    rotateMatrix_optimal(matrix);

    cout<<"Rotated Matrix : \n";
    // Rotated matrix
    for(auto &i:matrix){
        for(auto &val:i){
            cout<< val << " ";
        }
        cout<<endl;
    }
    return 0;
}