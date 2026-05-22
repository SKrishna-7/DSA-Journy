#include <iostream>
#include <vector>
using namespace std;

// BruteForce => Linear Search

// Optimal

int numberOfTimesArrRotated(vector<int> nums, int n)
{

    int low = 0;
    int high = n - 1;

    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[high])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            break;
        }

        if (nums[low] <= nums[mid])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            high = mid - 1;

            if (nums[mid] < ans)
            {
                ans = nums[mid];
                index = mid;
            }
        }
    }
    return index;
}

int main()
{

    vector<int> nums = {4, 5, 6, 7, 1};
    int n = nums.size();

    cout << numberOfTimesArrRotated(nums, n);
    return 0;
}