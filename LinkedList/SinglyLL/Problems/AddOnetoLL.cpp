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

Node* reverse(Node * head){

    if(head == nullptr || head->next == nullptr) return head;

    Node* newHead = reverse(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;

}

Node* AddOneToLL_brute(Node *head){

    Node* newHead = reverse(head);

    int carry = 1;

    Node* temp=newHead;
    Node* prev = nullptr;

    while(temp != nullptr){

        temp->data = temp->data + carry;

        if(temp->data == 10){
            temp->data = 0;
            carry=1;
        }else{
            carry = 0;
            break;
        }


        prev = temp;
        temp = temp->next;
    }

    if(carry == 1){

        prev->next = new Node(1);

    }
    head = reverse(newHead);
    return head;

}   

int helper(Node* head){
    

    Node* temp = head;
    if(temp == nullptr) return 1;
    

    int carry = helper(temp->next);

    temp->data += carry;
    if(temp->data < 10){
        return 0;
    } 

    temp->data = 0;
    return 1;

}
Node* AddOneToLL_Optimal(Node *head){

    int carry = helper(head);

    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }

    return head;
}

int main() {
    
    int arr1[] = {9,9,9,9};


    int size1=sizeof(arr1) / sizeof(arr1[0]);
    
    Node* head = convertArrToLL(arr1,size1);
    
    Node* newHead = AddOneToLL_Optimal(head);
    traverse(newHead);
    cout<<endl;
    
    return 0;
}