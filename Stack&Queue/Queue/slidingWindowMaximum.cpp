#include <iostream>
#include<stack>
#include<vector>
#include<climits>

using namespace std;

vector<int> slidingWindowMax_brute(vector<int> &nums,int n,int k){
    
    int l=0;
    int i=k-1;
    int winSize=(n-k) +1;
    vector<int> maxWindow(winSize);
    while(i<n){
        
        int maxi=INT_MIN;
        for(int j=l;j<=i;j++){
            maxi= max(maxi,nums[j]);
            maxWindow[l] = maxi;
        }
        l++;
        i++;
    }
    
    return maxWindow;
} 


vector<int> slidingWindowMax_Optimal(vector<int>& nums, int k) {
    
    if(k==1) return nums;
    int n=nums.size();
    
    vector<int> maxWindow;

    deque<int> dq;

    for(int i=0;i<n;i++){

        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }

        while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
        
        dq.push_back(i);

        if(i>=k-1) maxWindow.push_back(nums[dq.front()]);
    }
    
    
    
    return maxWindow;
    }
int main() {
    
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int n=nums.size();
    int k=3;
    
    
    return 0;
}