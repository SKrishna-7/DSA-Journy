#include<iostream>

using namespace std;

bool reverse_string(string s,int i){
    
    if(i >= s.size() / 2){
        return true;
    }

    if(s[i] != s[s.size() - i - 1]) return false;

    return reverse_string(s,i+1);
}

    
int main(){

    string s="malayalam";

   if (reverse_string(s,0) == 1 ) cout <<"Given String is Palindrome";
   else cout <<"Given String is Not Palindrome";

    return 0;
}