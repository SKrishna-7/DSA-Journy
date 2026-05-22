#include <iostream>
#include<vector>

using namespace std;

class Node{
    
public: 
    int data;
    Node *next = nullptr;
    
    Node(int data , Node* next){
        this->data = data;
        this->next = next;
    }
    
    Node(int data){
        this->data = data;
    }
};

Node* convertArrToLL(int arr[],int n){
    
    Node* head = new Node(arr[0]);
    Node* temp = head;
    
    for(int i=1;i<n;i++){
        temp->next = new Node(arr[i],nullptr);
        temp = temp->next;
    }
    
    return head;
}
void traverse(Node* head){
    
    Node* temp=head;
    while(temp != nullptr){
        cout<< temp->data << endl;
        temp=temp->next;
    }
}

#include<stack>

Node* reverse_brute(Node* head){

    stack<int> st;

    Node* temp = head;

    while(temp!=nullptr){

        st.push(temp->data);
        temp=temp->next;

    }

    temp=head;

    while(temp != nullptr){

        temp->data= st.top();
        st.pop();
        temp=temp->next;
    }

    return head;

}

Node *reverse_iterative(Node* head){


    Node* temp = head;
    Node* prev = nullptr;
    Node* front = nullptr;

    while(temp != nullptr){
        
        front = temp->next;
        temp->next = prev;
    
        prev=temp;
        temp = front;
    
    }

    return prev;
}

Node *reverse_recursive(Node* head){

    if(head == nullptr || head->next == nullptr) return head;

    Node* newHead = reverse_recursive(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;

}
int main() {
    
    int arr1[] = {2,4,3,5,6};

    int size1=sizeof(arr1) / sizeof(arr1[0]);
    
    Node* head = convertArrToLL(arr1,size1);

    Node* newNode = reverse_recursive(head);
    traverse(newNode);


   
    
    return 0;
}