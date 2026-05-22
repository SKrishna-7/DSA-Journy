#include<iostream>
#include<vector>

using namespace std;

// >= x 
int floor(vector<int> nums,int n,int x){

    int low=0;
    int high=n-1;
    int floor=-1;

    while(low<=high){

        int mid=low+(high-low) /2;

        if (nums[mid] <= x) {
            floor=mid; 
            low=mid+1;
        }

        else high=mid-1;

    }

    return floor;
}
// > x 
int ceil(vector<int> nums,int n,int x){

    int low=0;
    int high=n-1;
    int ceil=-1;

    while(low<=high){

        int mid=low+(high-low) /2;

        if (nums[mid] >= x) {
            ceil=mid; 
            high=mid-1;
        }

        else if(nums[mid] > x) high=mid-1;

        else low=mid+1;
    }

    return ceil;
}

int main(){

    vector<int> nums={2,3,4,5,5,5,6,7,9}; 
    int n=nums.size();
    int x=8;
    cout<<"Floor : " << floor(nums,n,x) << endl;
    cout<<"Ceil : " <<ceil(nums,n,x);

    return 0;
}

// n => O(n) / 