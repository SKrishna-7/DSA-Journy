#include<iostream>
#include<vector>
using namespace std;

// BruteForce => Linear Search

//Optimal

int minimumInRotatedArray_I_approach1(vector<int> nums,int n){

    int low=0;
    int high=n-1;

    int ans=INT_MAX;
    
    while(low<=high){

        int mid=low+(high-low) / 2;

        if(nums[low]<= nums[high]){
            ans=min(ans,nums[low]);
            break;
        }

        if(nums[low] <= nums[mid]){
            ans=min(ans,nums[low]);
            low=mid+1;
            
        }
        else{
            ans=min(ans,nums[mid]);
             
            high = mid-1;
        }
    }
    return ans;
}


int minimumInRotatedArray_I_approach2(vector<int> nums,int n){

    int low=0;
    int high=n-1;
    
    while(low<=high){

        int mid=low+(high-low) / 2;

        

        if(nums[low] <= nums[mid]){
            low=mid+1;
        }
        else{             
            high = mid-1;
        }
    }
    return nums[low];
}


int main(){

    vector<int> nums={4,5,6,7,1,2};
    int n=nums.size();
    int x=0;
    
    // cout<<minimumInRotatedArray_I_approach1(nums,n);
    cout<<minimumInRotatedArray_I_approach2(nums,n);
    return 0;
}