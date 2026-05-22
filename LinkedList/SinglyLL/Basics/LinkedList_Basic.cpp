#include<iostream>
#include<vector>

using namespace std;

struct Node{      // data , next

    int data;
    Node* next;

    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }

};


int main(){

    int arr[5] = {1,2,3,4,5};

    Node n1(10,nullptr);

    Node *n2=new Node(20,nullptr);
   
  
    cout<<n1.data << endl;
    cout<<n2->data;
   
    delete n2;
    return 0;
}