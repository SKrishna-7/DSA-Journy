#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int index , vector<int> &nums,vector<vector<int>> &results){

    if(index == nums.size()){

        results.push_back(nums);
        return ;
    }

    for(int i=index;i<nums.size();i++){

        swap(nums[index] , nums[i]);
        generatePermutations(index+1,nums,results);
        swap(nums[i] , nums[index]);

    }
}

int main(){

    vector<int> nums={1,2,3};
    int n=nums.size();

    vector<vector<int>> results;
    generatePermutations(0,nums,results);

    for(auto &res:results){
        for(auto &row : res){
            cout<< row  << " ";
        }
        cout<<endl;
    }
    return 0;
}