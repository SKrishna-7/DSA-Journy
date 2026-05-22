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

Node* reverse(Node* head){


    if(head == nullptr || head->next == nullptr) return head;

    Node* newHead = reverse(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
    

}

Node* findKthNode(Node* head , int k){

        k-=1;
        while(k > 0){
            k--;
            head=head->next;

        }

        return head;
}
Node* reverseKgroup(Node* head , int k){

    Node* temp = head;
    Node* kNode = nullptr;
    Node* prevNode = nullptr;
   
        
        
    while(temp != nullptr){

        kNode = findKthNode(temp , k);

        if(kNode == nullptr){

            if(prevNode != nullptr ){

                prevNode->next = temp;
            }
            break;
        }
        Node* front = kNode->next;

        kNode->next = nullptr;

        reverse(temp);

        if(temp == head){
            head = kNode;
        }else{
            prevNode->next = kNode;
        }

        prevNode = temp;

        temp = front;

    }

    return head;

}


int main() {
    
    int arr1[] = {1,2,3,4,5};
    int k=2;
    
    int size1=sizeof(arr1) / sizeof(arr1[0]);
    
    Node* head = convertArrToLL(arr1,size1);
    
    // traverse(head);    
    cout<<endl;
   
    Node* kthNode = reverseKgroup(head,k);

    
    // cout<< kthNode->data << endl;
    traverse(kthNode);

    return 0;
}