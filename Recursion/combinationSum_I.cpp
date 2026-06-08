#include<iostream>
#include<vector>

using namespace std;

void findCombinations(int  i,vector<int> nums,vector<int> &current,vector<vector<int>> &results,int target){

    if(target == 0){

        results.push_back(current);
        return ;
    }

    if(i == nums.size() || target < 0) return ;

    if(nums[i] <= target){

        current.push_back(nums[i]);
        findCombinations(i,nums,current,results,target - nums[i]);
        current.pop_back();
        
    }
    findCombinations(i+1,nums,current,results,target);


}
 

int main(){

    vector<int> nums={1,2,3};
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