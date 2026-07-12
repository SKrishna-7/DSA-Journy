#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>

using namespace std;

string minWindowSubstring_brute(string &s,string &t){

    int n = s.size();
    int m = t.size();

    if(m > n) return "";


    int minLen = INT_MAX;
    int startIndex = 0;
    
    
    
    for(int i=0;i<n;i++){

        vector<int> hash(256,0);
        int count=0;
        
        for(int j=0;j<m;j++) hash[t[j] - 'A']++;

        for(int j=i;j<n;j++){

            if(hash[s[j] - 'A'] > 0) count++;
            hash[s[j] - 'A']--;

            if(count == m){

                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    startIndex = i;
                    break;
                }
            }
        }
        }

    string res = s.substr(startIndex,minLen);

    return res;
}

//Think of hash not as the characters you have, but as the characters you still need.

string minWindowSubstring_optimal(string &s,string &t){

    int n = s.size();
    int m = t.size();

    if(m > n) return "";


    int minLen = INT_MAX;
    int startIndex = 0;
    
    int l=0,r=0;

    vector<int> hash(256,0);
    int charCount=0;
        
    for(int j=0;j<m;j++) hash[t[j]]++;

    while(r < n){

        if(hash[s[r]] > 0) charCount++;
        hash[s[r]]--;
    
        while(charCount == m){

            if(r-l+1 < minLen){    
                minLen=r-l+1;
                startIndex=l;
        }
            hash[s[l]]++;
            if(hash[s[l]] > 0) charCount--;
            l++;
            
        }
        
        r++;

    }

    string res= s.substr(startIndex,minLen);
    return res;

}

int main(){

    string s="ADOBECODEBANC";
    string t="ABC";

    cout<<endl;
   
    // cout<<minWindowSubstring_brute(s,t);
    cout<<minWindowSubstring_optimal(s,t);


    cout<<endl;

    return 0;
}