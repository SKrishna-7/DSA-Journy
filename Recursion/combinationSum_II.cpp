#include<iostream>
#include<vector>

using namespace std;

void findCombinations(int index,vector<int> nums,vector<int> &current,vector<vector<int>> &results,int target){

    if(target == 0){

        results.push_back(current);
        return ;
    }


    for(int i=0;i<nums.size();i++){

        
        if(i > index && nums[i] == nums[i-1]) continue;

        if(nums[i] > target) break;

        current.push_back(nums[i]);
        findCombinations(index+1,nums,current,results,target - nums[i]);
        current.pop_back();
        
    }
}
 

int main(){

    vector<int> nums={2,5,2,1,2};
    int target = 5;

    vector<vector<int>> results;
    vector<int> current;
    
    findCombinations(0,nums,current,results,target);

    for (const auto &row : results) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}