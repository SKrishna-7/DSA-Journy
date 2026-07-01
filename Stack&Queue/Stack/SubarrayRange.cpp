#include <iostream>
#include<climits>
#include<vector>
#include<stack>

using namespace std;

int sumOfsubarrayRange_brute(vector<int> &nums,int n){
      int result = 0;
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for(int k=i;k<=j;k++){
                maxi=max(maxi,nums[k]);
                mini=min(mini,nums[k]);
            }
            result+=maxi - mini;        
        }
    }
    
   return result;
}

int sumOfsubarrayRange_better(vector<int> &nums,int n){
      int result = 0;
    
    for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            int mini=INT_MAX;

        for(int j=i;j<n;j++){
                maxi=max(maxi,nums[j]);
                mini=min(mini,nums[j]);
                result+=maxi - mini;        
        }
    }
    
   return result;
}

// Optimal


vector<int> NSE(vector<int> &nums,int n){
    
    vector<int> nextSmallestElement(n);
    stack<int> st;
    
    for(int i=n-1 ;i>=0;i--){
        
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        
        if(st.empty()) {
            nextSmallestElement[i] = n;
            
        }
        else{
            nextSmallestElement[i] = st.top();
        }
        
        st.push(i);
    }
    
    return nextSmallestElement;
}

vector<int> PSE(vector<int> &nums,int n){
    
    vector<int> previousSmallestElement(n);
    stack<int> st;
    
    for(int i=0 ;i<n;i++){
        
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        
        if(st.empty()) {
            previousSmallestElement[i] = -1;
            
        }
        else{
            previousSmallestElement[i] = st.top();
        }
        
        st.push(i);
    }
    
    return previousSmallestElement;
}

vector<int> NGE(vector<int> &nums,int n){
    
    vector<int> nextGreaterElement(n);
    stack<int> st;
    
    for(int i=n-1 ;i>=0;i--){
        
        while(!st.empty() && nums[st.top()] <= nums[i]){
            st.pop();
        }
        
        if(st.empty()) {
            nextGreaterElement[i] = n;
            
        }
        else{
            nextGreaterElement[i] = st.top();
        }
        
        st.push(i);
    }
    
    return nextGreaterElement;
}


vector<int> PGE(vector<int> &nums,int n){
    
    vector<int> previousGreaterElement(n);
    stack<int> st;
    
    for(int i=0;i<n;i++){
        
        while(!st.empty() && nums[st.top()] < nums[i]){
            st.pop();
        }
        
        if(st.empty()) {
            previousGreaterElement[i] = -1;
            
        }
        else{
            previousGreaterElement[i] = st.top();
        }
        
        st.push(i);
    }
    
    return previousGreaterElement;
}

int sumOfsubarrayRange_optimal(vector<int> &nums,int n){

     vector<int> nse = NSE(nums,n);
    vector<int> pse = PSE(nums,n);
    
    vector<int> nge = NGE(nums,n);
    vector<int> pge = PGE(nums,n);
    
    int ans=0;
    for(int i=0;i<n;i++){
        
        int leftMin = i - pse[i];
        int rightMin = nse[i] - i;
        
        int minCount = leftMin * rightMin;
        // cout<<"min count : "<<minCount <<endl;
        int leftMax = i - pge[i];
        int rightMax = nge[i] - i;
        
        int maxCount = leftMax * rightMax;
        // cout<<"max count : "<<minCount << endl;
        
        ans += (maxCount*nums[i]) - (minCount * nums[i]);
    }
    
    return ans;
}

int main() {
    
    vector<int> nums={4,-2,-3,4,1};
    int n=nums.size();
    
    // cout<<sumOfsubarrayRange_better(nums,n);
    cout<<sumOfsubarrayRange_optimal(nums,n);

    return 0;
}