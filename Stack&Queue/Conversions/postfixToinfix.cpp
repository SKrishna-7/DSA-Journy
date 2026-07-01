
#include <iostream>
#include<stack>
#include<algorithm>

using namespace std;

string postfixToinfix(string &s){
        
    int n=s.length();
    stack<string> st;
    
    int i=0;
    while(i < n){
        
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                
                st.push(string(1,s[i]));
        } 
        else{
            
            string c2 = st.top(); st.pop();
            string c1 = st.top(); st.pop();
            
            string expression = '(' +c1 + s[i] + c2 + ')';
            st.push(expression);
            
        }
        i++;
    }
       return st.top();
}

int main() {
    
    string s="abcd^e-*+";
    
    cout<<postfixToinfix(s);
    


    return 0;
}