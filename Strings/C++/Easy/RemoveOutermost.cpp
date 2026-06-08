#include<iostream>
#include<stack>

using namespace std;

string removeOuter_brute(string &s , int n){
    
    string res="";
    stack<char> st;

    for(int i=0;i<n;i++){

        if(s[i] == '('){
            
            if(!st.empty()){
                res+=s[i];
            }

            st.push(s[i]);
        }
        else{

            st.pop();            
            if(!st.empty()){
                res +=s[i];
            }
        }
    }

    return res;
}

string removeOuter_optimal(string &s , int n){

    string res="";
    int cnt=0;

    for(int i= 0;i<n;i++){

        if(s[i] == '('){

            if(cnt  > 0) res+=s[i];
            cnt++;
        }else{
            if(cnt > 0) res+=s[i];
            cnt--;
        }
    }

    return res;

}

int main(){

    string s  = "(()())(())";
    int n = s.size();
    
    cout<<removeOuter_optimal(s,n);


    return 0;
}