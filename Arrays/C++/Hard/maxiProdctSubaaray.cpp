#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumProd_brute(vector<int> nums, int n)
{

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            int prod = 1;

            for (int k = 0; k < j; k++)
            {
                prod = prod * nums[k];
            }

            maxi = max(maxi, prod);
        }
    }

    return maxi;
}

int maximumProd_better(vector<int> nums, int n)
{

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        for (int j = i; j < n; j++)
        {

            prod *= nums[j];

            maxi = max(maxi, prod);
        }
    }

    return maxi;
}


int maximumProd_optimal(vector<int> nums, int n){

    int prefix=1;
    int suffix=1;
    int maxi=INT_MIN;

    for(int i=0;i<n;i++){

        prefix=prefix*nums[i];
        suffix=suffix*nums[n-i-1];

        maxi=max(maxi,max(prefix,suffix));

    }

    return maxi;

}

int main()
{

    // vector<int>  nums = {2,3,-2,3};
    // vector<int> nums = {-2, 0, -1};
    vector<int> nums = {2,3,4,0,8,4,3};
    int n = nums.size();

    // cout << maximumProd_brute(nums, n);
    // cout << maximumProd_better(nums, n);

    cout<<maximumProd_optimal(nums,n);
    return 0;
}
