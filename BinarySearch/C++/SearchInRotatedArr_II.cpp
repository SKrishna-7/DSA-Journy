#include<iostream>
#include<vector>
using namespace std;

// BruteForce => Linear Search

//Optimal

bool searchInRotatedArray_I(vector<int> nums,int n,int x){

    int low=0;
    int high=n-1;

    while(low<=high){

        int mid=low+(high-low) / 2;

        if (nums[mid] == x) return true;
        
        if (nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++;
            high--;
            continue;
        }
        if(nums[low] <= nums[mid]){
            
            if(nums[low] <= x && x < nums[mid]) high = mid-1;
            else low = mid+1;
        }
        else{
             
            if(nums[mid] < x && x <= nums[high]) low = mid+1;
            else high = mid-1;
        }
    }
    return false;
}


int main(){

    vector<int> nums={2, 5, 6, 0, 0, 1, 2};
    int n=nums.size();
    int x=7;
    
    cout<<searchInRotatedArray_I(nums,n,x);
    return 0;
}