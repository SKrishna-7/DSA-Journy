#include<iostream>
#include<vector>

using namespace std;

  void solver(int n,string &current ,vector<string> &result,int opened,int closed){

        if(current.length() == 2*n){
            result.push_back(current);
            return ;
        }

        if(opened < n){

        current.push_back('(');
        solver(n,current,result,opened+1,closed);
        current.pop_back();
        }

        if(closed < opened){
            current.push_back(')');
            solver(n,current,result,opened,closed+1);
            current.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {

        vector<string> result;

        if(n == 0) return result;

        string current="";

        solver(n,current,result,0,0);
        return result;   
    }

int main(){

    int n=2;

    for(auto &s : generateParenthesis(n)){
        cout<<s<<endl;

    }
    return 0;
}