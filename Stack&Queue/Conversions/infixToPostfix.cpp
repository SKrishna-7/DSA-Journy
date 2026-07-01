
#include <iostream>
#include<stack>
using namespace std;

int getPrecedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string &s){
    
    stack<char> st;
    int n=s.length();
    int i=0;
    string result="";
    
    while(i < n){
        
        if(
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >='0' && s[i] <= '9') 
            )    
        {
            result+=s[i];
                
        }
        
        else if(s[i] == '('){
            
            st.push(s[i]);
            
        }
        else if(s[i] == ')'){
                
                while(!st.empty() && st.top() != '('){
                    result+=st.top();
                    st.pop();
                }
            if(!st.empty()) st.pop();
        }
        
            else{
                
               while (!st.empty() && st.top() != '(' && 
                  (getPrecedence(st.top()) > getPrecedence(s[i]) || 
                  (getPrecedence(st.top()) == getPrecedence(s[i]) && s[i] != '^'))) {
                result += st.top();
                st.pop();
            }
                
                st.push(s[i]);
            }
        
        i++;
    }
    
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    
    return result;
}

int main() {
    
    string s="a+b*(c^d-e)";
    
    cout<<infixToPostfix(s);
    


    return 0;
}