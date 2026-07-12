#include <iostream>
#include <vector>

using namespace std;

int maxScore_brute(vector<int>& cardPoints, int k) {

    int n = cardPoints.size();
    int maxSum = 0;

    for (int left = 0; left <= k; left++) {

        int right = k - left;

        int sum = 0;

        // Take from left
        for (int i = 0; i < left; i++)
            sum += cardPoints[i];

        // Take from right
        for (int i = 0; i < right; i++)
            sum += cardPoints[n - right + i];

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int maxScore_optimal(vector<int>& cards,int k){

    int maxLen = 0;
    int n=cards.size();

    int leftSum=0;

    for(int i=0;i<k;i++){
        leftSum+=cards[i];
    }

    maxLen = leftSum;
    int rightIndex = n-1;
    int rightSum=0;

    for(int i=k-1 ; i>=0;i--){

        leftSum -= cards[i];
        rightSum += cards[rightIndex];
        rightIndex--;

        maxLen = max(maxLen,rightSum + leftSum);
    }

    return maxLen;
}

int main() {

    vector<int> cards = {1,2,3,4,5,6,1};
    int k = 3;

    cout << maxScore_optimal(cards, k);

    return 0;
}