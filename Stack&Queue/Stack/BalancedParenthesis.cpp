#include<iostream>
#include<stack>

using namespace std;


 bool isBalanced(string& s) {
        // code here
        stack<char> st;
        
        for(char &c:s){
            
            if(c == '(' || c == '[' || c == '{') st.push(c);
            
            else{
                
                if(st.empty()) return false;
                
                char ch = st.top();
                st.pop();
                
                if((c == ')' && ch == '(')
                || (c == ']' && ch == '[')
                || (c == '}' && ch == '{')){
                    continue;
                }
                else return false;
            }
        }
        
        return st.empty();
    }