#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervalsBrute(vector<vector<int>> &intervals) {
    
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin(),intervals.end());

    for(int i=0;i<n;i++){

        int start=intervals[i][0];
        int end=intervals[i][1];

        if(!ans.empty() && end<= ans.back()[1]){
            continue;
        }

        for(int j=i+1;j<n;j++){

            if(end>=intervals[j][0]){
                end=max(end,intervals[j][1]);
            }else{
                break;
            }

        }
        ans.push_back({start,end});

    }



    return ans;
}


vector<vector<int>> mergeIntervalsOptimal(vector<vector<int>> &intervals) {

    int n=intervals.size();

    sort(intervals.begin(),intervals.end());

    vector<vector<int>> ans;

    ans.push_back(intervals[0]);

    for(int i=0;i<n;i++){

        if(ans.empty() || intervals[i][0]<=ans.back()[1]){
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);  
        }
        else{
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> arr = {{1, 3},{2,6},{8,9},{9,11},{8, 10}, {16,17},{2, 4}, {15, 18}};
    
    // vector<vector<int>> ans = mergeIntervalsBrute(arr);

    vector<vector<int>> ans = mergeIntervalsOptimal(arr);

    cout << "Merged Intervals: \n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}