#include<iostream>
#include<vector>

using namespace std;

void findCombinations(int start,vector<int> &current,vector<vector<int>> &results,int target,int k){

    if(current.size() == k){

        if(target == 0){
            results.push_back(current);
        }
        return ;   
    }

    for(int i=start;i<=9;i++){

        if(i > target) break;

        current.push_back(i);
        findCombinations(i+1,current,results,target - i,k);
        current.pop_back();

    }

}
 

int main(){

    int target = 9;
    int k=3;

    vector<vector<int>> results;
    vector<int> current;
    
    findCombinations(1,current,results,target,k);

    for (const auto &row : results) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}