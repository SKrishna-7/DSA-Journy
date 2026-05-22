#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;


bool isIsomorphic_brute(string s ,string t){

    if(s.length() != t.length()) return false;

    unordered_map<char,char> mappings; //This is our dictionary. It stores the relationship s[i] -> t[i]. (e.g., 'a' translates to 'x').

    unordered_set<char> usedT; // This is a "No-Entry" list. Once a character from string t is mapped to something in s, we add it here so no other character from s can claim it.


    for(int i=0;i<s.length();i++){

        char charS=s[i];
        char charT=t[i];

        if(mappings.find(charS) != mappings.end()){

            if(mappings[charS] != charT) return false;

            else{

    //The Problem: What if s = "ab" and t = "cc"? 
    //When we are at 'b', we haven't seen 'b' before. 
    //But 'c' is already "taken" by 'a'.

                if(usedT.find(charT) != usedT.end()) return false;
                mappings[charS] = charT;
                usedT.insert(charT);
            }
        }
    }

    return true;

}


bool isIsomorphic_optimal(string s ,string t){

    int m1[256]={0};
    int m2[256]={0};

    for(int i=0;i<s.length();i++){

        if(m1[s[i]] != m2[t[i]]) return false;

        m1[s[i]] = i+1;
        m2[t[i]] = i+1;
    }

    return true;
}

int main(){

    string s="egg";
    string t="add";

    // cout<< boolalpha << isIsomorphic_brute(s,t);
    cout<< boolalpha << isIsomorphic_optimal(s,t);

    return 0;
}