#include<iostream>
#include<algorithm>

using namespace std;

bool isAnagram_brute(string s,string t){

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return s == t;
}


bool isAnagram_optimal(string s,string t){

    int freq[256] = {0};

    for(auto &c :s){
        freq[c]++;
    }

    for(auto &t :s){
        freq[t]--;

        if(freq[t] < 0){
            return false;
        }
    }

    return true;

}

int main(){

    string s = "anagram", t = "nagaram";

    cout<< boolalpha << isAnagram_optimal(s,t);
    return 0;
}