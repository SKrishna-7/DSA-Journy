#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


string longestPalindromicSubstr_brute(string s){

    int n=s.length();
    string max_str=s.substr(0,1);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            string sub=s.substr(i,j);

            string rev=sub;

            reverse(rev.begin(),rev.end());

            if(sub == rev && sub.length() > max_str.length()){
               
                    max_str=sub;
               
            }
        }
    }

    return max_str;
}
int main(){

    string s="babaad";

    cout<<longestPalindromicSubstr_brute(s);

    return 0;
}