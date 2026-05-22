#include<iostream>
#include<vector>

using namespace std;


int binarySearch(vector<int> nums,int n,int x){

    int low=0;
    int high=n-1;

    while(low<=high){

        int mid=low+(high-low) /2;

        if (nums[mid] == x) return mid;

        else if(nums[mid] > x) high=mid-1;

        else low=mid+1;
    }

    return -1;
}

int main(){

    vector<int> nums={2,3,4,5,6,7,8,9};
    int n=nums.size();
    int x=2;
    cout<<binarySearch(nums,n,x);

    return 0;
}