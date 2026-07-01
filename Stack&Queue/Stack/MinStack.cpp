#include<iostream>
#include<stack>

using namespace std;

class MinStack {
public:
    
    long long minEle;
    stack<long long> st;
    
    MinStack() {
        
    }
    
    void push(int value) {
        

        if(st.empty()){
            st.push(value);
            minEle = value;
        }

        else if(value < minEle){
            
           long long encode = 2LL *value - minEle;
           st.push(encode);
           minEle = value;
        }

        else {
            st.push(value);
            }

    }
    
    void pop() {
        
        if(st.top() >= minEle){
            
            st.pop();
        }
    else {

        long long encoded = st.top();
        st.pop();
        minEle = 2*minEle - encoded;
    }
    }
    
    int top() {
        
        if(st.top() >= minEle) return st.top();

        return minEle;
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */