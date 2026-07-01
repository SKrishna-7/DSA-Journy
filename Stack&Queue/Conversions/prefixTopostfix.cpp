
#include <iostream>
#include<stack>
#include<algorithm>

using namespace std;

string prefixToinfix(string &s){
        
    int n=s.length();
    stack<string> st;
    
    for(int i=n-1;i >=0 ;i--){
        
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                
                st.push(string(1,s[i]));
        } 
        else{
            
            string c1 = st.top(); st.pop();
            string c2 = st.top(); st.pop();
            
            string expression = c1 + c2 + s[i];
            st.push(expression);
            
        }
    }
       return st.top();
}

int main() {
    
    string s="+A*BC";
    
    cout<<prefixToinfix(s);
    


    return 0;
}