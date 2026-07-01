
#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestHistogram(vector<int> &heights, int n)
{

    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++)
    {

        int currHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && heights[st.top()] > currHeight)
        {

            int height = heights[st.top()];
            st.pop();

            int right = i;
            int left = st.empty() ? -1 : st.top();

            int width = right - left - 1;

            maxArea = max(maxArea, width * height);
        }

        st.push(i);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{

    if (matrix.empty())
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> height(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }

        maxArea = max(maxArea, largestHistogram(height, m));
    }

    return maxArea;
}


int main(){{

    
    return 0;
}}