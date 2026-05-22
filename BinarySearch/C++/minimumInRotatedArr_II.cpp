#include<iostream>
#include<vector>
using namespace std;

// BruteForce => Linear Search

//Optimal

int searchInRotatedArray_I(vector<int> nums,int n,int x){

    int low=0;
    int high=n-1;
    int ans=INT_MAX;

    while(low<=high){

        int mid=low+(high-low) / 2;

        
        if (nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++;
            high--;
            continue;
        }
        if(nums[low] <= nums[mid]){
          ans=min(ans,nums[low]);
          low = mid+1;
        }
        else{
            ans=min(ans,nums[mid]);
             
            high = mid-1;
        }
    }
    return ans;
}


int main(){

    // vector<int> nums={2, 5, 6, 0, 0, 1, 2};
    vector<int> nums={1,3,5};
    int n=nums.size();
    int x=7;
    
    cout<<searchInRotatedArray_I(nums,n,x);
    return 0;
}