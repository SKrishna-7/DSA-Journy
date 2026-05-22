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

Node* RemoveFrmLast_brute(Node* head ,int N){

    int len=0;
    Node* temp=head;

    
    while(temp != nullptr){
        len++;
        temp = temp->next ;
    }

    
    if(len == N){
        Node *toDelete = head;
        head=head->next;
        delete toDelete;
        return head;
    }

    int target = len - N;
    temp=head;

    while(temp != nullptr){

        target--;
        if(target == 0){
            break;
        }
        temp=temp->next;
    }
    
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    return head;
}

Node* RemoveFrmLast_optimal(Node* head , int N){
    
    Node* fast=head;
    for(int i=0;i<N;i++){
        fast=fast->next;
    }

    Node* slow=head;

    if(fast == nullptr) return head->next;


    while(fast->next != nullptr){

        fast=fast->next;
        slow=slow->next;
    }

    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return head;
}

int main() {
    
    int arr1[] = {2,4,3,5,6};

    int size1=sizeof(arr1) / sizeof(arr1[0]);
    
    Node* head = convertArrToLL(arr1,size1);

    Node* newNode = RemoveFrmLast_optimal(head , 5);
    traverse(newNode);
   
    
    return 0;
}