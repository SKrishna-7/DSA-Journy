#include<iostream>
using namespace std;

class Node{

public:
    int data;
    Node* next = nullptr;

    Node(int data){
        this->data = data;
    }
};

class Queue{

    Node* front;
    Node* rear;
    int crntSize=0;


public:

    Queue(){
        
        front = nullptr;
        rear = nullptr;

    }

    void enqueue(int element){

        Node* newNode = new Node(element);

        if(front == nullptr){
            
            front = newNode;
            rear = newNode;
            crntSize++;
            return ;
        }

        rear->next = newNode;
        rear= newNode;
        crntSize++;

    }

    void dequeue(){

    if(front == nullptr) {
        cout<<"Queue underflow ";
        return ;
    }

        Node* temp=front;
        front = front->next;
        delete temp;
        crntSize--;

         if(front == nullptr)
    {
        rear = nullptr;
    }
    }

    int peek(){

        
        if(front == nullptr)
    {
        cout << "Queue Empty";
        return -1;
    }

    return front->data;
    }

    int size(){
        return crntSize;
    }
};



int main(){

    Queue q;

    cout<<endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout<<q.size()<<endl;
    cout<<q.peek();
    q.dequeue();
    cout<<q.peek();

    return 0;
}