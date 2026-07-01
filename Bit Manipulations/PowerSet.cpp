#include <iostream>
#include<vector>
using namespace std;

int main() {
    
    vector<int> nums={1,2,3};
    vector<vector<int>> results={{}};
    int n = nums.size();
    
   for(int mask=0; mask<(1<<n); mask++)
{
    vector<int> subset;

    for(int i=0; i<n; i++)
    {
        if(mask & (1<<i))
        {
            subset.push_back(nums[i]);
        }
    }

    results.push_back(subset);
}
    
    for(auto &row:results){
        for(auto &vals:row){
            cout<<vals << " ";
        }
        cout<<endl;
    }
    
    return 0;
}