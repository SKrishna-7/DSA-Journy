#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>

using namespace std;

bool canPlaceCow(vector<int> stalls,int dist,int cows){
    
    int lastPlacedCow=stalls[0];
    int cowsPlaced=1;

    for(int i=1;i<stalls.size();i++){

        if(stalls[i] - lastPlacedCow >= dist){
            cowsPlaced++;
            lastPlacedCow=stalls[i];
        }

    }
        if(cowsPlaced >= cows){
                return true;
        }

    return false;
        
}

//BruteForce

int aggressiveCow_Brute(vector<int> &stalls, int cows){

    int n=stalls.size();
    int high=stalls[n-1] - stalls[0];
    int ans=0;

    for(int i=1;i<=high;i++){
        if(canPlaceCow(stalls,i,cows)==true) ans=i;
    }

    return ans;
}

int aggressiveCow_optimal(vector<int> &stalls, int cows){

    int n=stalls.size();
    int low=1;
    int high=stalls[n-1] - stalls[0];
    int ans=0;

    while(low<=high){
        int mid=low+(high - low) / 2;

        if(canPlaceCow(stalls,mid,cows)){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

int main()
{

    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    sort(stalls.begin(),stalls.end());

    // cout<<aggressiveCow_Brute(stalls,cows);
    cout<<aggressiveCow_optimal(stalls,cows);

    return 0;
}