#include<iostream>
#include<vector>

using namespace std;


int maxConsecutiveOnes_brute(vector<int> &arr,int k){

    int n=arr.size();

    
    int maxLen=0;
    for(int i=0;i<n;i++){
        
        int zeros=0;
        
        for(int j=i;j<n;j++){

            if(arr[j] == 0){
                zeros++;
            }
            if(zeros <= k){
                maxLen = max(maxLen,j-i+1);
            }
            
            else break;
            
        }
    }

    return maxLen;
}

int maxConsecutiveOnes_better(vector<int> &arr,int k){

    int n=arr.size();

    int r=0;
    int l=0;
    int zeros=0;
    int maxLen=0;

    while(r < n){

        if(arr[r] == 0) zeros++;

       
        while(zeros > k){

            if(arr[l] == 0) zeros--;
            l++;
        }

        if(zeros <= k) maxLen =max(maxLen, r - l +1);

        r++;
    }

    return maxLen;

}



int maxConsecutiveOnes_optimal(vector<int> &arr,int k){

    int n=arr.size();

    int r=0;
    int l=0;
    int zeros=0;
    int maxLen=0;

    while(r < n){

        if(arr[r] == 0) zeros++;

       
        if(zeros > k){

            if(arr[l] == 0) zeros--;
            l++;
        }

        if(zeros <= k) maxLen =max(maxLen, r - l +1);

        r++;
    }

    return maxLen;

}
int main(){

    cout<<endl;

    vector<int> arr={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;

//    cout<< maxConsecutiveOnes_brute(arr,k);
      cout<< maxConsecutiveOnes_better(arr,k);


    
    cout<<endl;

    return 0;
}