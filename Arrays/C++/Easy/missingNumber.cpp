#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int missingNumber_Brute(vector<int> arr,int n){

    for(int i=1;i<=n;i++){

        int flag=0;
        for(int j=0;j<n-1;j++){

            if(arr[j] == i){
                flag=1;
                break;    //If NO break - inner loop keeps scanning the ENTIRE array even AFTER finding the value.
            }
        }
        if(flag==0) return i;
    }

    return 0;

    //TC -  worse case - O(n x n) 
    // SC - O(1)

}
int missingNumber_Better(vector<int> &arr,int n){

    vector<int> hash(n+1);

    for(auto &i:arr){
        hash[i]=1;
    }

   for(int i=1;i<n;i++){
    if (hash[i] == 0){
        return i;
    }
   }
    return -1;
    
}


int missingNumber_Optimal_1(vector<int> &arr,int n){

    int sum=(n*(n+1)) / 2;

    int actual=0;

    for(auto &i:arr){
        actual+=i;
    }
    
    return sum-actual;

}

int missingNumber_Optimal_2(vector<int> &arr,int n){

    
    int xor1=0;
    int xor2=0;

    for(int i=1;i<=n;i++){
        xor1^=i;
    }

    for(int i=0;i<n-1;i++){
        xor2^=arr[i];
    }

    return xor1 ^ xor2;

}

int missingNumber_Optimal_3(vector<int> &arr,int n){

    
    int xor1=0;
    int xor2=0;

    
    for(int i=0;i<n-1;i++){
        
        xor2^=arr[i];
        xor1^=i+1;
    }

    xor1^=n;

    return xor1 ^ xor2;

}


int main(){

    vector <int> arr={1,2,4,5};
    int n=5;

    // cout<<missingNumber_Brute(arr,n);      //O(n*n)
    // cout<<missingNumber_Better(arr,n);      //O(2n)
    // cout<<missingNumber_Optimal_1(arr,n);   //O(n)
    // cout<<missingNumber_Optimal_2(arr,n);  // O(2n)
    cout<<missingNumber_Optimal_3(arr,n);  // O(n)

    return 0;
}