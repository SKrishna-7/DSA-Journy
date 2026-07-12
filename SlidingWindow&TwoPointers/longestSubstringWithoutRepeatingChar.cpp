#include<iostream>
#include<unordered_map>
#include<unordered_set>


using namespace std;

//Brute
bool isUnique(string &s, int start, int end) {

    unordered_set<char> st;

    for (int i = start; i <= end; i++) {

        if (st.count(s[i]))
            return false;

        st.insert(s[i]);
    }

    return true;
}

int longestSubstringWithoutRepeatingChar_brute(string &s,int n){
    
    int maxLen = 0;

    // Generate all substrings
    for (int start = 0; start < n; start++) {

        for (int end = start; end < n; end++) {

            if (isUnique(s, start, end)) {
                maxLen = max(maxLen, end - start + 1);
            }
        }
    }

    return maxLen;

}
int longestSubstringWithoutRepeatingChar_optimal(string &s,int n){


    int left=0;

    unordered_map<char,int> m;
    int maxLen=0;

    for(int i=0;i<n;i++){

        m[s[i]]++;
        while(m[s[i]] > 1){
            
            m[s[left]]--;
            left++;
        }

        maxLen = max(maxLen ,i - left + 1);

    }

    return maxLen;
}
int main(){

    string s="abcabcbb";
    int n = s.size();
    
    cout<<longestSubstringWithoutRepeatingChar_brute(s,n);
    return 0;

}