#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

string reverseWordsInString_brute(string &s){

    vector<string> words;  // O(n)
    string word;
    int n=s.length();

    for(int i=0;i<n;i++){
        if(s[i] != ' '){
            word+=s[i];
        }else{
           if(word != "") words.push_back(word);
           word="";
        }
    }  // O(n)

    if(!word.empty()) words.push_back(word);

    string res="";

    for(int i=words.size()-1;i>=0;i--){

        res+=words[i];
        if(i!=0) res+=" ";
    }

    
    return res;
}

string reverseWordsInString_better(string &s){

    stack<string> words;  // O(n)
    string word;
    int n=s.length();

    for(int i=0;i<n;i++){
        if(s[i] != ' '){
            word+=s[i];
        }else{
           if(word != "") words.push(word);
           word="";
        }
    }  // O(n)

    if(!word.empty()) words.push(word);

    string result="";

    while(!words.empty()){

        result+=words.top();
        words.pop();

        if(!words.empty()) result+=" ";

    }

    
    return result;
}


void reverseWordsInString_Optimal(string &s){

  
    reverse(s.begin(),s.end());

    int n=s.length();
    int writer=0;

    for(int i=0;i<n;i++){
        
        if(s[i] != ' '){
            
            if(writer !=0) s[writer++] = ' ';

            int start=writer;
            
            while(i<n && s[i] != ' '){
                s[writer++] = s[i++] ;
            }

            reverse(s.begin() + start , s.begin() + writer);
        }

    }

    s.resize(writer);
        
}

int main(){
    
    string s="My name is Krishna";

    // cout<<reverseWordsInString_brute(s); // TC -> O(n)  SC-> O(n)
    // cout<<reverseWordsInString_better(s); // TC -> O(n)  SC-> O(n)
    reverseWordsInString_Optimal(s); // TC -> O(n)  SC-> O(n)

    cout<<s;




    return 0;
}