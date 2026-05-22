#include<iostream>
#include<vector>

using namespace std;

// >= x ==> Lower bound
int searchInsertPosition(vector<int> nums,int n,int x){

    int low=0;
    int high=n-1;
    int ans=n;

    while(low<=high){

        int mid=low+(high-low) /2;

        if (nums[mid] >= x) {
            ans=mid; 
            high=mid-1;
        }

        else if(nums[mid] > x) high=mid-1;

        else low=mid+1;
    }

    return ans;
}


int main(){

    vector<int> nums={1,2,4,7}; 
    int n=nums.size();
    int x=6;
    cout<<"Insert Position : " << searchInsertPosition(nums,n,x) << endl;
  
    return 0;
}

// n => O(n) / 