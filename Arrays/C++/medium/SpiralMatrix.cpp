#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


int countSubarrySumK_brute(vector<int> nums,int n,int k){

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){

            int sum=0;

            for(int m=i;m<=j;m++){
                sum+=nums[m];
            }
        
        if(sum == k){
            count++;
        }
        }

    }
    return count;


}

int countSubarrySumK_better(vector<int> nums,int n,int k){

    int count=0;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){

            sum+=nums[j];
        
        if(sum == k){
            count++;
        }
        }

    }
    return count;


}


int countSubarrySumK_optimal(vector<int> nums,int n,int k){

    int count=0;
    int sum=0;
    unordered_map<int,int> hmap;

    hmap[0]=1;

    for(int i=0;i<n;i++){
        
        sum+=nums[i];

        int rem=sum-k;

        if(hmap.find(rem) != hmap.end()){
            count+=hmap[rem];
        }

        hmap[sum]+=1;
    }
    
    return count;

}

int main(){

    // vector<int>  nums={3, 1, 2, 4};
    vector<int>  nums= {3,-3,1,1,1};
    int k = 3;

    int n=nums.size();

//    cout<< countSubarrySumK_brute(nums,n,k);

//    cout<< countSubarrySumK_better(nums,n,k);

   cout<< countSubarrySumK_optimal(nums,n,k);
    return 0;

}