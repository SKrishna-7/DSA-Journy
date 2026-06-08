#include <iostream>
#include<vector>

using namespace std;

void subset_Recursive(string s,int i,string &current,vector<string> &results){
    
    if(i == s.size()){
        results.push_back(current);
        return ;
    }
    
   
        
    current.push_back(s[i]);
    subset_Recursive(s,i+1,current,results);
    current.pop_back();
    
    subset_Recursive(s,i+1,current,results);

   
}

void subset_brute(string str,vector<string> &results){

   
    for(auto &s:str){
        int currentSize = results.size();
        
        for(int i=0;i<currentSize;i++){
            results.push_back(results[i] + s);
        }
    }
}
int main() {

    string s="abc";
    // vector<string> results;
    string current="";
    vector<string> results={""};

    // subset_Recursive(s,0,current,results);
    subset_brute(s,results);
    
    for(auto &s:results){
        cout<<s << endl;
    }

    return 0;
}