#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

string sortCharByFreq_brute(string str){

    vector<pair<int,char>> freqMap(256);
    
    for(int i = 0; i < 256; i++){
        freqMap[i]={0,(char)i};
    }

    for(char c:str){
        freqMap[(unsigned char)c].first++;
    }

    sort(freqMap.begin(),freqMap.end(),greater<pair<int,char>>());

   

    string result="";

    for(auto &freq:freqMap){

        if(freq.first==0) break;
        result.append(freq.first,freq.second);
    }

        return result;
    
    }



void sortCharByFreq_optimal(string str){
    
    unordered_map<char,int> freqMap;

    for(char &c:str){
        freqMap[c]++;
    }

    vector<string> bucket(str.length() + 1,"");

    for(auto &p:freqMap){
        bucket[p.second] += p.first;
    }

    string res="";

    for(int i=str.length();i>=1;i--){
        for(char c :bucket[i])
        res.append(i,c);
    }

    cout<<res;

}
int main(){

    string str="tree";

    // cout<<sortCharByFreq_brute(str);
    
    sortCharByFreq_optimal(str);


    return 0;
}