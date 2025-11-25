#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

void twoSums_brute(vector<int> arr,int target){
    
    int n=arr.size();

    for(int i=0;i<n-1;i++){
        
        if(arr[i] + arr[i+1] == target ){
            cout<< i <<" "<< i+1;
        }
    }

}


void twoSums_better(vector<int> arr,int target){
    
    int n=arr.size();
    unordered_map<int,int> map;

    for(int i=0;i<n;i++){

        int rem=target - arr[i];
        
        if(map.find(rem) != map.end()){

            cout<< map[rem] << " " <<i;
        }

        map[arr[i]]=i;
    
    }

}

#include<algorithm>

void twoSums_optimal(vector<int> arr,int target){


    sort(arr.begin(),arr.end());
    int n=arr.size();
        int l=0;
        int r=n-1;

        while(l<r){
            
            int sum=arr[l] + arr[r];
            
            if(sum==target){
                cout<<l <<" "<<r;
            }
            else if(sum>target){
                r--;
            }else{
                l++;
            }
        }
}


int main(){

    vector<int> arr={2,3,5,1,6,2,6,7,7,0};  
    int n=arr.size();
    int target=6;
    // twoSums_brute(arr,target);
    // twoSums_better(arr,target);
    twoSums_optimal(arr,target);

    return 0;
}
