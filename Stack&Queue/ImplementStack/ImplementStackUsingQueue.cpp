#include<iostream>
#include<queue>

using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {

        
    }
    
    void push(int x) {
        
        int s=q.size();
        q.push(x);
        
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement = q.front();
        q.pop();

        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

int main(){

    return 0;
}