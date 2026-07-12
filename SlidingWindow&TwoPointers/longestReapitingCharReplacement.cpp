#include<iostream>
#include<vector>

using namespace std;


int longestCharReplacement_brute(string &s,int n,int k){

    int maxLen = 0;

    
    for(int i=0;i<n;i++){
        
        vector<int> hash(26,0);
        int maxFreq = 0;

        for(int j=i;j<n;j++){

            hash[s[j] - 'A']++;

            int maxFreq = max(maxLen , hash[s[i]]);
            int changes = (j-i+1) - maxFreq;

            if(changes <= k){
                maxLen = max(maxLen , j-i+1);
            }else break;
        }
        

        
    }
        return maxLen;
}

#include<unordered_map>

int longestCharReplacement_better(string &s,int k){

    int r=0,l=0;
    unordered_map<char,int> m;
    int maxLen=0;
    int maxFreq = 0;
    int n=s.size();

    while(r<n){

        m[s[r]]++;

        maxFreq = max(maxFreq,m[s[r]]);
        
        int length = r-l+1;
        int changes = maxFreq - length;
        
        while(changes > k){
            m[s[l]]--;

            l++;
        }
        if(changes <= k){
            maxLen = max(maxLen,(r-l+1));
        }
        r++;
    }

    return maxLen;

}


int longestCharReplacement_optimal(string &s,int k){

    int r=0,l=0;
    vector<int> m(26,0);
    int maxLen=0;
    int maxFreq = 0;
    int n=s.size();

    while(r<n){

        m[s[r]]++;

        maxFreq = max(maxFreq,m[s[r] - 'A']);
        
        int length = r-l+1;
        int changes = maxFreq - length;
        
        if(changes > k){
            m[s[l]-'A']--;

            l++;
        }
        if(changes <= k){
            maxLen = max(maxLen,(r-l+1));
        }
        r++;
    }

    return maxLen;

}
int main(){

    string s  = "ABAB";
    int k=2;
    int n=s.length();

    cout<<longestCharReplacement_optimal(s,k);
    
    return 0;
}