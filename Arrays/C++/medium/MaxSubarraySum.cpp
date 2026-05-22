#include<iostream>
#include<vector>

using namespace std;

// BruteForce -> use 3 loops like longest subarray problem , but find sum instead len of subarray
// Better -> use 2 (j=i+1) loops like longest subarray problem , but find sum instead len of subarray

// Optimal
// Kadene's Algorithm


int maxSubarraySum(vector<int> &nums){
        
    int n=nums.size();

    int sum=0;
    int max_sum=INT_MIN;

    for(int i=0;i<n;i++){

        sum+=nums[i];

        if(sum > max_sum) max_sum = sum;

        if(sum < 0) sum=0;

    }


    return max_sum;
}



int main(){


    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};

    cout<<maxSubarraySum(nums);


    return 0;
}