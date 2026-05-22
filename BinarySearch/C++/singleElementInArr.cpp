#include <iostream>
#include <vector>
using namespace std;

int singleElement_Brute(vector<int> nums, int n)
{

    if(n==1) return nums[0];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (nums[i] != nums[i + 1])
                return nums[0];
        }
        else if (i == n - 1)
        {
            if (nums[i] != nums[i - 1])
                return nums[i];
        }
        
        else if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            return nums[i];
    }

    return -1;
}



int singleElement_Better(vector<int> nums, int n)
{
    int ans=0;
    if(n==1) return nums[0];
    
    for(int i=0;i<n;i++) ans^=nums[i];

    return ans;
}

int singleElement_optimal(vector<int> nums, int n)
{   
    int low=0;
    int high=n-1;

    // if(n==1) return nums[0];
    // if(nums[0] != nums[1]) return nums[0];
    // if(nums[n-1] != nums[n-2]) return nums[n-1];
    
    while(low<high){

        int mid=low+(high-low) /2;

        if (mid%2==1) mid--;

        if(nums[mid] == nums[mid+1]) low=mid+2;

        else high=mid;
    }

    return nums[low];
    
}

int main()
{

    vector<int> nums = {1, 1, 2, 2, 3,3, 4, 4, 5, 5};

    // cout << singleElement_Brute(nums, nums.size()); 
    // cout << singleElement_Better(nums, nums.size());
    cout << singleElement_optimal(nums, nums.size());
    return 0;
}