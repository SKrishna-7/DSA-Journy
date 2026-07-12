#include <iostream>
#include <vector>

using namespace std;

// -------------------- Brute Force --------------------

int binarySubarraySum_brute(vector<int> &nums, int goal, int n) {

    int result = 0;

    for (int i = 0; i < n; i++) {

        int sum = 0;

        for (int j = i; j < n; j++) {

            sum += nums[j];

            if (sum == goal)
                result++;
        }
    }

    return result;
}

// -------------------- At Most --------------------

int atMost(vector<int> &nums, int goal, int n) {

    if (goal < 0)
        return 0;

    int result = 0;

    int left = 0;
    int sum = 0;

    for (int right = 0; right < n; right++) {

        sum += nums[right];

        while (sum > goal) {
            sum -= nums[left];
            left++;
        }

        result += (right - left + 1);
    }

    return result;
}

// -------------------- Optimal --------------------

int binarySubarraySum_optimal(vector<int> &nums, int goal, int n) {

    return atMost(nums, goal, n) - atMost(nums, goal - 1, n);
}

// -------------------- Driver --------------------

int main() {

    vector<int> nums = {0, 0, 0, 0, 0};
    int goal = 0;

    int n = nums.size();

    cout << "Brute Force : "
         << binarySubarraySum_brute(nums, goal, n) << endl;

    cout << "Optimal     : "
         << binarySubarraySum_optimal(nums, goal, n) << endl;

    return 0;
}