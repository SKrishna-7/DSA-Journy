#include<iostream>
#include <vector>

using namespace std;

vector<int> leader_brute(vector<int> nums,int n) {

    vector<int> result;

    for(int i=0;i<n;i++){
        bool leader=true;
        for(int j=i+1;j<n;j++){
            if (nums[i] < nums[j]){
                leader=false;
                break;
            }
        }
        if(leader){
            result.push_back(nums[i]);
        }
    }


    return result;
}

vector<int> leader_optimal(vector<int> nums,int n) {

    int max=INT_MIN;
    vector<int> result;
    int leader=n-1;

    for(int i=n-1;i>0;i--){

        if(nums[i] > max){
            max=nums[i];
            result.push_back(nums[i]);
        }
    }

    return result;
}

int main(){

    vector<int> nums={10,24,12,0,3,5,6};
    int n=nums.size();

//    for (auto &i:leader_brute(nums,n)){
//     cout<< i <<" ";
//    }

   for (auto &i:leader_optimal(nums,n)){
    cout<< i <<" ";
   }

    return 0;
}