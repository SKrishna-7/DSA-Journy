#include<iostream>
#include<vector>

using namespace std;


void arrangeBySign_Brute(vector<int> &nums,int n){

    vector<int> pos;
    vector<int> neg;

    for(auto &i:nums){
        if(i<0){
            neg.push_back(i);
        }
        else{
            pos.push_back(i);
        }
    }

    for(int i=0;i<nums.size()/2;i++){

        nums[2*i] = pos[i];
        nums[2*i+1] = neg[i];
    }
}


void arrangeBySign_Optimal(vector<int> &nums,int n){

    int pos=0;
    int neg=1;
    
    vector<int> ans(n,0);

    for(int i=0;i<n;i++){
        if(nums[i]<0){
            ans[neg]=nums[i];
            neg+=2;
        }
        else{
            ans[pos] =nums[i];
            pos+=2;
        }
    }

    nums=ans;
   
}

void rearrangeBySignInPlace(vector<int> &nums) {
    int n = nums.size();
    int i = 0;
    int j = 1; 

    while (i < n && j < n) {
        while (i < n && nums[i] >= 0) i += 2;

        while (j < n && nums[j] < 0) j += 2;

        if (i < n && j < n) {
            swap(nums[i], nums[j]);
            i += 2;
            j += 2;
        }
    }
}

int main(){

    vector<int> nums={1,2,3,-1,-2,-3,4,-3,-3};
    int n=nums.size();  


    cout<<"Before Arrange : ";
    for(auto &i:nums){
        cout<< i <<" ";
    }

    // arrangeBySign_Brute(nums,n);
    // arrangeBySign_Optimal(nums,n);

    rearrangeBySignInPlace(nums);

    cout<<endl;
    cout<<"After Arrange : ";
    for(auto &i:nums){
        cout<< i <<" ";
    }
    return 0;
}