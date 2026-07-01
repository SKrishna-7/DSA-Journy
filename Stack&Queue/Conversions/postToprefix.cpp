
#include <iostream>
#include<stack>
#include<algorithm>

using namespace std;

string postToprefix(string &s){
        
    int n=s.length();
    stack<string> st;
    
    for(int i=0;i <n ;i++){
        
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                
                st.push(string(1,s[i]));
        } 
        else{
            
            string c1 = st.top(); st.pop();
            string c2 = st.top(); st.pop();
            
            string expression = s[i] + c1 + c2;
            st.push(expression);
            
        }
    }
       return st.top();
}

int main() {
    
    string s="ABC*+";
    
    cout<<postToprefix(s);
    


    return 0;
}