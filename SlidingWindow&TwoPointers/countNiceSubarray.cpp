#include <iostream>
#include <vector>

using namespace std;

// -------------------- Brute Force --------------------

int niceSubarray_brute(vector<int> &nums, int k, int n) {

    int result = 0;

    for (int i = 0; i < n; i++) {

        int oddCount = 0;

        for (int j = i; j < n; j++) {

            if (nums[j] % 2 == 1)
                oddCount++;

            if (oddCount == k)
                result++;

            else if (oddCount > k)
                break;
        }
    }

    return result;
}

// -------------------- At Most K Odds --------------------

int atMost(vector<int> &nums, int k, int n) {

    if (k < 0)
        return 0;

    int result = 0;

    int left = 0;
    int oddCount = 0;

    for (int right = 0; right < n; right++) {

        if (nums[right] % 2 == 1)
            oddCount++;

        while (oddCount > k) {

            if (nums[left] % 2 == 1)
                oddCount--;

            left++;
        }

        result += (right - left + 1);
    }

    return result;
}


int niceSubarray_optimal(vector<int> &nums, int k, int n) {

    return atMost(nums, k, n) - atMost(nums, k - 1, n);
}


int main() {

    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int n = nums.size();

    cout << "Brute Force : " << niceSubarray_brute(nums, k, n) << endl;
    cout << "Optimal     : " << niceSubarray_optimal(nums, k, n) << endl;

    return 0;
}