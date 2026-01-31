#include<iostream>
#include<vector>

using namespace std;

// >= x 
int lowerBound(vector<int> nums,int n,int x){

    int low=0;
    int high=n-1;
    int lb=n;

    while(low<=high){

        int mid=low+(high-low) /2;

        if (nums[mid] >= x) {
            lb=mid; 
            high=mid-1;
        }

        else if(nums[mid] > x) high=mid-1;

        else low=mid+1;
    }

    return lb;
}
// > x 
int upperBound(vector<int> nums,int n,int x){

    int low=0;
    int high=n-1;
    int ub=n;

    while(low<=high){

        int mid=low+(high-low) /2;

        if (nums[mid] > x) {
            ub=mid; 
            high=mid-1;
        }

        else if(nums[mid] > x) high=mid-1;

        else low=mid+1;
    }

    return ub;
}

int main(){

    vector<int> nums={2,3,4,5,5,5,6,7,9}; 
    int n=nums.size();
    int x=5;
    cout<<"Lower Bound : " << lowerBound(nums,n,x) << endl;
    cout<<"Upper Bound : " <<upperBound(nums,n,x);

    return 0;
}

// n => O(n) / 