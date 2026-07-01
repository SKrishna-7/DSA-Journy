#include<iostream>
using namespace std;

class Node{

public:
    int data=0;
    Node* next=nullptr;

    Node(int data){
        this->data = data;
    }

};
class Stack{

public:
    Node* top;
    int crntSize;

    Stack()
    {
        top = nullptr;
        crntSize = 0;
    }
    void push(int element){

        Node* newNode = new Node(element);
        newNode->next = top;

        top = newNode;
        
        crntSize+=1;

    }

    void pop(){

        if(top == nullptr)
    {
        cout << "Stack Underflow\n";
        return;
    }

    Node* temp = top;
    top = temp->next;

    delete temp;
    crntSize--;
    }

    int peek(){
        return top->data;
    }

    int size(){
        return crntSize;
    }

};

int main(){

    Stack st;

    cout<<endl;
    cout<<st.peek();
    cout<<endl;

    st.push(20);
    st.push(30);
    st.push(50);

    cout<<st.peek() << endl;
    cout<<st.size() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.size() << endl;

    return 0;
}