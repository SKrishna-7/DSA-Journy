#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
public:
    
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }    

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {

        int topElement = s1.top();
        s1.pop();
        return topElement;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.size() == 0;
    }
};

class MyQueue {
public:
    
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {

       s1.push(x);
    }
    
    int pop() {

        if(!s2.empty()){

             int topElement = s2.top();
        s2.pop();

        return topElement;
        }
        while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

        int topElement = s2.top();
        s2.pop();

        return topElement;
    }
    
    int peek() {
       if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
