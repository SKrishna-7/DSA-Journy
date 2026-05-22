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

Node* middleElement_brute(Node* head){


    int n=0;
    Node* temp =head;
    while(temp != nullptr){
        n++;
        temp=temp->next;
    }

    temp = head;

    int mid = (n / 2) +1;

    while(temp != nullptr){

        mid--;
        if(mid == 0) break;
        temp=temp->next;

    }

    return temp;

}

Node* middleElement_optimal(Node* head){

    Node* slow = head;
    Node* fast = head;

    while(fast->next == nullptr && fast != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}   
int main() {
    
    int arr1[] = {2,1,2,2,1,2};


    int size1=sizeof(arr1) / sizeof(arr1[0]);
    
    Node* head = convertArrToLL(arr1,size1);
    
    Node* midEle = middleElement_optimal(head);
    cout<<midEle->data << endl;;
   
    
    return 0;
}