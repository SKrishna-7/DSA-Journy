#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int clebrity_brute(vector<vector<int>> &matrix , int n){
    
    //assuming Iam the Celebrity
    // me [j] , others [i] , [j][i]
    vector<int> Iknow(n);
    // [i][j]
    vector<int> knowsMe(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && matrix[i][j] == 1){
                knowsMe[j]++;
                Iknow[i]++;
            }
        }
    }
    
   for(int i=0; i < n; i++) {
            
            // Return the index of celebrity
            if(knowsMe[i] == n-1 && Iknow[i] == 0) {
                return i;  
            }
        }
        
    return -1;
}


int clebrity_better(vector<vector<int>> &matrix , int n){
    
   
    
    for(int i=0;i<n;i++){ // consider i is the celeb and 
        
        bool iKnow=true;
        bool knowsMe=true;
        
        for(int j=0;j<n;j++){  // checking everyone knows i.
        
            if(i!=j && matrix[i][j] == 1){ 
                iKnow=false;
                break;
                
            }
        }
        for(int j=0;j<n;j++){   // checking i knows everyone.
            if(i!=j && matrix[j][i] == 0){
                knowsMe=false;
                break;
                
            }
        }
        
        if(iKnow && knowsMe) return i;
    }
       
    return -1;
}
int main() {
    
    vector<vector<int>> matrix={
        {0, 1, 1, 0}, 
        {0, 0, 0, 0}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 0}
    };
    
    int n=matrix.size();
  cout<<  clebrity_brute(matrix,n);
    
    return 0;
}