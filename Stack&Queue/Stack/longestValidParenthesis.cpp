#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main(){

    cout<<endl;

    string s="()()";
    stack<int> st;

    int ans=0;

    int n=s.length();

    for(int i=0;i<n;i++){

        if(st.empty()) st.push(-1);

        if(s[i] == '(') st.push(i);
        else{

            st.pop();
            
            if(st.empty()){
                st.push(i);
            }
            else{
                ans=max(ans,i-st.top());
            }
        }
    }

    cout<<ans;


    cout<<endl;

    
    return 0;

}
