#include<iostream>
#include<unordered_set>

using namespace std;

int longestSubstringWithK_brute(string &s , int k){

    int n=s.size();
    int result=0;
    
    for(int i=0;i<n;i++){
        
        unordered_set<char> st;
        for(int j=i;j<n;j++){

            st.insert(s[j]);
            if(st.size() == k){

                result = max(result,j-i+1);

            }else if(st.size() > k) break;
        }
    }
    return result;
}

#include<unordered_map>

int longestSubstringWithK_optimal(string &s , int k){

    int n=s.size();
    int r=0,l=0;

    int maxLen = 0;
    int dist=0;
    unordered_map<char,int> m;

    while(r < n){
     
        m[s[r]]++;
        if(m[s[r]] == 1) dist++;

        while(dist > k){

            m[s[l]]--;

            if(m[s[l]] == 0) dist--;
            l++;
        }

        maxLen = max(maxLen,r-l+1);
        r++;
        }

        return maxLen;

}
int main(){

    string s="aababbcaacc";
    int k=2;

    // cout<<longestSubstringWithK_brute(s,k);

    cout<<longestSubstringWithK_optimal(s,k);


    return 0;
}