#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;



int countXorofK_brute(vector<int> nums,int n,int k){

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int xr=0;
            for(int k=i;k<j;k++){
                xr =xr ^ nums[k] ;
            }

            if(xr == k) count++;

        }
    }


    return count + 1;
}


int countXorofK_better(vector<int> nums,int n,int k){

    int count=0;

    for(int i=0;i<n;i++){
        int xr=0;
        for(int j=i;j<n;j++){
          
            xr =xr ^ nums[j] ;
            if(xr == k) count++;

        }
    }


    return count;
}

int countXorofK_optimal(vector<int> nums,int n,int k){

    int prefix_xor=0;

    unordered_map<int,int> hmap;
    hmap[0] = 1;

    int count=0;
    for(int i=0;i<n;i++){

        prefix_xor^=nums[i];

        int need=prefix_xor ^ k;

        if(hmap.find(need) != hmap.end()){
            
            count+=hmap[need];
        }

        hmap[prefix_xor]+=1;

    }

    return count;

}

int main(){


    vector<int> nums= {4, 2, 2, 6, 4} ;
    // vector<int> nums= {5, 6, 7, 8, 9} ;
    
    int k =6;

    int n=nums.size();

    // cout  << countXorofK_brute(nums,n,k);  // O(n^3)
    // cout  << countXorofK_better(nums,n,k);   // O(n^2)  

    cout << countXorofK_optimal(nums,n,k);  

    return 0;

}

