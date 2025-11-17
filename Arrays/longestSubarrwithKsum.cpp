#include<iostream>
#include<vector>

using namespace std;

int longestSubArray_Brute_1(vector<int> arr,int n,int k){

    int maxi=0;
    for(int i=0;i<n;i++){

        for(int j=i;j<n;j++){

            int sum=0;
            for(int t=i;t<=j;t++){
                sum+=arr[t];
            }

            if(sum==k){
                
                maxi=max(maxi,j-i+1);
            }
        }
    }


    return maxi;
}   // O(n*n*n) ~~ O(n^3)

int longestSubArray_Brute_2(vector<int> arr,int n,int k){

    int maxi=0;
    for(int i=0;i<n;i++){

        int sum=0;
        for(int j=i;j<n;j++){

            sum+=arr[j];

            if(sum==k){
                
                maxi=max(maxi,j-i+1);
            }
        }
    }


    return maxi;
}   // O(n*n)


int longestSubArray_Better(vector<int> arr,int n,int k){

    

    return ;
}   // O(n*n)

int main(){

    vector<int> arr={1,2,3,1,1,1,1,4,2,3};
    int n=arr.size();

    int k=6;

    // cout<<longestSubArray_Brute_1(arr,n,k);
    cout<<longestSubArray_Brute_2(arr,n,k);

    return 0;
}