#include<iostream>
#include<unordered_set>
#include<unordered_map>


using namespace std;

int substringWithAllThreeChar_brute(string &s,int n){

    int result=0;

    for(int i=0;i<n;i++){
        
        unordered_set<char> st;

        for(int j=i;j<n;j++){
            
            st.insert(s[j]);

            if(st.size() == 3) result++;
        }
    }

    return result;
}

int numberOfSubstrings_optimal(string s) {

    int n = s.size();

    int left = 0;
    int right = 0;
    int result = 0;

    unordered_map<char, int> freq;

    while (right < n) {

        // Expand the window
        freq[s[right]]++;

        // While window contains a, b and c
        while (freq['a'] > 0 &&
               freq['b'] > 0 &&
               freq['c'] > 0) {

            // Every extension of this window is also valid
            result += (n - right);

            // Shrink the window
            freq[s[left]]--;
            left++;
        }

        right++;
    }

    return result;
}

int main(){

    string s= "abcabc";
    int n=s.length();

    cout<<substringWithAllThreeChar_brute(s,n);

    return 0;
}