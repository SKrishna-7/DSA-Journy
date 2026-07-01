#include<iostream>
using namespace std;

class StackUsingArr{

        int maxSize=100;
        int arr[100];
        int top;


public:

    StackUsingArr(){
        
        top=-1;
    }
    
    void push(int element){
    
        if(top == maxSize - 1){
             cout << "Stack Overflow";
             return;
        }
        top++;
        arr[top] = element;
    }

    void pop(){
        
        if(top == -1) {

            cout<<"Stack Underflow"<<endl;
            return ;
        }

        top--;
    }

    int peek(){

        if(top==-1){
            return -1;
        }

        return arr[top];
    }

    int size(){
        return top+1;
    }

    bool isempty(){
        return top==-1;
    }
};
int main(){

    StackUsingArr st;

    st.push(20);
    cout<<st.peek();
    st.push(30);
    cout<<st.peek();


    return 0;
}