#include <iostream>
#include<climits>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int largestRectangleInHistogram_brute(vector<int> &nums,int n){
    int result=0;
    
    for(int i=0;i<n;i++){
      
      int width = 1;
      int left = i-1;
      
      while(left >= 0 && nums[left] >= nums[i]){
          width++;
          left--;
      }
        
    int right=i+1;
    while(right < n && nums[right] >= nums[i] ){
        width++;
        right++;
    }
    
    result = max(result , nums[i] * width);
    }
    
    return result;
}

// Better
#include <iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int> NSE(vector<int> &nums,int n){
    
    stack<int> st;
    vector<int>nse(n);
    
    for(int i=n-1;i>=0;i--){
        
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        if(st.empty()) nse[i] = n;
        else{
            nse[i] = st.top();
        }
        
        st.push(i);
    }
    return nse;
}

vector<int> PSE(vector<int> &nums,int n){

    stack<int> st;
    vector<int>pse(n);
    
    for(int i=0;i<n;i++){
        
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        if(st.empty()) pse[i] = -1;
        else{
            pse[i] = st.top();
        }
        
        st.push(i);
    }
    return pse;
}

int largestRectangleInHistogram_better(vector<int> &nums,int n){
    
    vector<int> nse = NSE(nums,n);
    vector<int> pse = PSE(nums,n);
    int result=0;
    
    for(int i=0;i<n;i++){
        
        int width = nse[i] - pse[i] - 1;
        result = max(result,width * nums[i]);
        
    }
    
    return result;
}
//optimal

int largestRectangleInHistogram_Optimal(vector<int> &heights , int n){

        stack<int> st;
        int maxArea=0;

        for(int i=0;i<=n;i++){

            int currHeight = (i==n) ? 0 : heights[i];

            while(!st.empty() && heights[st.top()] > currHeight){

                int height = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                int width = right - left - 1;

                maxArea = max(maxArea,width * height);
            }

            st.push(i);
        }

        return maxArea;
    }

int main(){
    
    vector<int> nums={2,1,5,6,2,3};
    int n=nums.size();
    
    
    cout<<largestRectangleInHistogram_brute(nums,n);
    
    return 0;
}