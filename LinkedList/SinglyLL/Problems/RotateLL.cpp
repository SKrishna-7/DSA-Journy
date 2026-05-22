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

Node* rotateLL(Node* head , int k){

    Node* tail = head;
    int len = 1;

    while(tail->next != nullptr){
        len++;
        tail = tail->next;
    }

    tail->next = head;

    k = k % len;

    if(k == 0) return head;

    int steps = len - k ;

    Node *temp = head;
    int cnt=0;

    while(temp != nullptr){
        cnt++;
        if(cnt == steps) break;
        temp = temp->next;
    }

    head = temp->next;
    temp->next = nullptr;

    return head;
}

int main() {
    
    int arr1[] = {2,4,7,8,9,0};
    int size1=sizeof(arr1) / sizeof(arr1[0]);
    
    int k=2;
    
    Node* head = convertArrToLL(arr1,size1);
    
    traverse(rotateLL(head , k));    
    cout<<endl;
   
        
    return 0;
}