#include<iostream>

using namespace std;

class Node{

    public:
        int data;
        Node* next = nullptr;
        Node* back=nullptr;

        Node(int data,Node* next ,Node* back){

            this->data = data;
            this->next = next;
            this->back = back;
        }

        Node(int data){
            this->data = data;
        }

};

Node* convertToDLL(int arr[] , int size){

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1;i<size;i++){

        Node* newNode = new Node(arr[i],nullptr,prev);

        prev->next = newNode;        
        prev = prev->next;
    }

    return head;

}

void traverse(Node* head){

    Node*  temp = head;

    while(temp != nullptr){

        cout<<temp->data << endl;
        temp = temp->next;
    }

}

int main(){

    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = convertToDLL(arr,size);

    traverse(head);

    return 0;
}