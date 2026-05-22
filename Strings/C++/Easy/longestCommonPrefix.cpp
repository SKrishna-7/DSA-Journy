#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string longestPrefix(vector<string> strs){

    int n=strs.size();
    int indx=0;
    for(int i=0;i<strs[0].length();i++){   
        
        char first=strs[0][i];

        for(int j=1;j<n;j++){
            if(i >= strs[j].length() || strs[j][i] != first) {
                    return strs[0].substr(0,i);
            }  
        }
    }
    return strs[0];
}


string longestPrefix_optimal(vector<string> strs){

    int n=strs.size();
    
    sort(strs.begin(),strs.end());

    string first=strs[0];
    string last=strs.back();

    string res="";

    for(int i=0;i<min(first.size(),last.size());i++){
        if(first[i] == last[i]) res+=first[i];
        else break;
    }


    return res;
}

int main(){

    vector<string> strs={"flower","flow","flood"};
    
    cout<<longestPrefix_optimal(strs);


    return 0;
}