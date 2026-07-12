#include <iostream>
#include <vector>
#include<stack>

using namespace std;

vector<int> onlineStockSpan_brute(vector<int> &nums, int n)
{

    vector<int> result(n);

    for (int i = 0; i < n; i++)
    {

        int current = nums[i];
        int cnt = 0;
        for (int j = i; j >= 0; j--)
        {
            if (current >= nums[j])
            {
                cnt++;
            }
            else
                break;
        }

        result[i] = cnt;
    }

    return result;
}

vector<int> onlineStockSpan_optimal(vector<int> &nums, int n){
    
    vector<int> result(n);
    
    stack<int> st;
    int span=0;
    for(int i=0;i<n;i++){
        
        while(!st.empty() && nums[st.top()] <= nums[i]){
            st.pop();
        }
        
        if(st.empty()){
            span = i + 1;
        }else{
            span = i - st.top();
        }
        
        result[i] = span;
        // cout<<span;
        
        st.push(i);
    }

    return result;

}
int main()
{

    vector<int> nums = {100, 80, 60, 70, 60, 75, 85};
    int n = nums.size();

    return 0;
}