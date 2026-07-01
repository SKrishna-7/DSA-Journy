#include<iostream>
#include<vector>

using namespace std;

void solve(string &nums,int target,vector<string> &results,string path,int index,int runningTotal,int previousNum){

        if(index == nums.size()){

            if(runningTotal == target){
                results.push_back(path);
            }

            return ;
        }

        for(int i=index;i< nums.size();i++){

            string digit = nums.substr(index,i - index +1);
            
            if(digit.length() > 1 && digit[0] == '0') break;

            long long currentNum = stoll(digit);

            if(index == 0){

                solve(nums,target,results,digit,i+1,currentNum,currentNum);
                continue;
            }


            solve(nums,target,results,path + "+" + digit,i+1,runningTotal + currentNum,currentNum);
            
            solve(nums,target,results,path + "-" + digit,i+1,runningTotal - currentNum,-currentNum);
            
            long long newTotal = runningTotal - previousNum +(previousNum * currentNum);
            solve(nums,target,results,path + "*" + digit,i+1,newTotal,previousNum * currentNum);

            

        }
}

int main(){

    string nums="123";
    int target = 6;

    vector<string> results;
    string path;

    solve(nums,target,results,path,0,0,0);

    for(auto r:results){
        cout<< r << endl;

    }
    return 0;
}