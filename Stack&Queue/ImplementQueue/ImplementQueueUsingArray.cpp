#include<iostream>
using namespace std;

class QueueUsingArr{

    int front;
    int rear;
    int arr[100];
    int maxSize=100;

    public:

        QueueUsingArr(){
            front=-1;
            rear=-1;
        }
        
    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (rear + 1) % maxSize == front;
    }

    void enqueue(int element){

        if(isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        if(front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxSize;
        }

        arr[rear] = element;
    }
    
    void dequeue(){

     if(isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % maxSize;
        }
}   
    
    int peek()
    {
        if(isEmpty())
        {
            cout << "Queue Empty" << endl;
            return -1;
        }

        return arr[front];
    }

    int size()
    {
        if(isEmpty())
            return 0;

        return ((rear - front + maxSize) % maxSize) + 1;
    }

    int size(){
        return rear - front + 1;
    }
};

int main(){


    return 0;
}


// In a circular queue, rear moves circularly. 
// The queue is full when the next position of rear is already occupied by front. 
// Therefore, if (rear + 1) % maxSize == front, there is no free slot left and the queue is full.