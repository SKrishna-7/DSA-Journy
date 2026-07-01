#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(vector<int> &nums,vector<int> &current,vector<bool> &visited,vector<vector<int>> &results){

    if(current.size() == nums.size()){

        results.push_back(current);
        return ;
    }

    for(int i=0;i<nums.size();i++){

        if(visited[i]) continue;
        
        visited[i] = true; 
        current.push_back(nums[i]);
        generatePermutations(nums,current,visited,results);
        current.pop_back();
        visited[i] = false;
    }
}

int main(){

    vector<int> nums={1,2,3};
    int n=nums.size();

    vector<bool> visited(n,false);

    vector<vector<int>> results;
    vector<int> current;
    generatePermutations(nums,current,visited,results);

    for(auto &res:results){
        for(auto &row : res){
            cout<< row  << " ";
        }
        cout<<endl;
    }
    return 0;
}