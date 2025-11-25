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

#include<unordered_map>

void longestSubArray_Better(vector<int> &arr,int n,int k){

    unordered_map<int,int> prefix_map;

    int sum=0;
    int maxlen=0;

    for(int i=0;i<n;i++){

        sum+=arr[i];
        if(sum == k){
            maxlen=max(maxlen,i+1);
        }

        int rem=sum-k;

        if(prefix_map.find(rem) != prefix_map.end()){
            maxlen=max(maxlen,i-prefix_map[rem]);
        }

     if(prefix_map.find(sum) == prefix_map.end())
     {
         prefix_map[sum] = i;
     }   
    }

   
    cout<<maxlen;
    

    return ;
}   // O(n*n)


void longestSubArray_Optimal(vector<int> &arr,int n,int k){

    int sum=0;
    int pointer=0;
    int maxi=0;
    for(int i=0;i<n;i++){

        sum+=arr[i];

        while(sum>k && pointer < i){
            sum-=arr[pointer];
            pointer++;
        }

        if(sum == k){
            maxi=max(maxi,i-pointer+1);
        }

    }

    cout<<maxi;

}
int main(){

    // vector<int> arr={1,2,3,1,1,1,1,4,2,3};
    vector<int> arr={2,5,1,3,1,1,1};
    int n=arr.size();

    int k=6;

    // cout<<longestSubArray_Brute_1(arr,n,k);
    // cout<<longestSubArray_Brute_2(arr,n,k);
    
    // longestSubArray_Better(arr,n,k);
    longestSubArray_Optimal(arr,n,k); // only for positive // O(2n) in worse case

    return 0;
}