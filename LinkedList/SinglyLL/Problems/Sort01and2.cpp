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

Node* Sort01and2_brute(Node* head){

    int cnt_0=0;
    int cnt_1=0;
    int cnt_2=0;

    Node* temp = head;

    while(temp!=nullptr){

        if(temp->data == 0 ) cnt_0++;
        else if(temp->data == 1) cnt_1++;
        else cnt_2++;

        temp=temp->next;
    }

    temp=head;

    while(temp!=nullptr){

        if(cnt_0) {
            temp->data = 0;
            cnt_0--;
        }
        else if(cnt_1){
            temp->data = 1;
            cnt_1--;
        }

        else{
            temp->data = 2;
            cnt_2--;
        }

        temp=temp->next;

    }

    return head;

}

Node* Sort01and2_optimal(Node* head){

    Node* ZeroNode = new Node(-1);
    Node* OneNode = new Node(-1);
    Node* TwoNode = new Node(-1);

    Node* Zero = ZeroNode;
    Node* One = OneNode;
    Node* Two = TwoNode;

    Node* temp = head;

    while(temp != nullptr){

        if(temp->data == 0){
            Zero->next = temp;
            Zero = Zero->next;
        }
        else if(temp->data == 1){
            One->next = temp;
            One = One->next;
        }
        else{
            Two->next = temp;
            Two = Two->next;
        }

        temp=temp->next;
    }

    Zero->next = (OneNode->next) ? OneNode->next : TwoNode->next;
    One->next = TwoNode->next ;
    Two->next = nullptr;

    Node* newHead = ZeroNode->next;
    delete ZeroNode;
    delete OneNode;
    delete TwoNode;

    return newHead;

}

int main() {
    
    int arr[] = {1,0,2,1,2,0,0,1,2};

    int size1=sizeof(arr) / sizeof(arr[0]);
    
    Node* head = convertArrToLL(arr,size1);
    
    // Node* newhead = Sort01and2_brute(head);
    Node* newhead = Sort01and2_optimal(head);

    traverse(newhead);
   
    
    return 0;
}