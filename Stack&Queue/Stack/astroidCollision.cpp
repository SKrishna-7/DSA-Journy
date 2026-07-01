#include <iostream>
#include<climits>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    
    vector<int> nums={3,5,-6,2,-1,4};
    stack<int> st;
    int n=nums.size();
    
    for(int i=0;i<n;i++){
    
        if(nums[i] > 0) st.push(nums[i]);
        else{
            
            while(!st.empty() && st.top() > 0 && st.top() < abs(nums[i])){
                st.pop();
            }
            
            if(!st.empty() && st.top() == abs(nums[i])) st.pop();
            else if(st.empty() || st.top() < 0){
                st.push(nums[i]);
            }
        }
    }
    
    vector<int> ans;
    while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
}

reverse(ans.begin(),ans.end());
   
for (int x : ans) {
    cout << x << " ";
}
    return 0;
}