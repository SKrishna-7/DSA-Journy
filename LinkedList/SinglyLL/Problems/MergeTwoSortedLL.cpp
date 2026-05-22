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

Node* mergeLL(Node* head1 , Node* head2){

    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* DummyNode = new Node(-1);
    Node* current = DummyNode;

    while(temp1 != nullptr && temp2 != nullptr){

        if(temp1->data <= temp2->data){
            current->next = temp1;
            temp1 = temp1->next;
        }

        else{
            current->next = temp2;
            temp2 = temp2->next;
        }

            current = current->next;

    }

    if(temp1 != nullptr){
        current->next = temp1;
    }

    if(temp2 != nullptr){
        current->next = temp2;
    }

    Node* mergedHead = DummyNode->next;
    delete DummyNode;
    
    return mergedHead;

}

int main() {
    
    int arr1[] = {2,4,7,8};
    int arr2[] = {1,2,3,5};

    
    
    int size1=sizeof(arr1) / sizeof(arr1[0]);
    int size2=sizeof(arr2) / sizeof(arr2[0]);
    
    Node* head1 = convertArrToLL(arr1,size1);
    Node* head2 = convertArrToLL(arr2,size2);



    
    // traverse(head);    
    cout<<endl;
   
        
    // cout<< kthNode->data << endl;
    traverse(mergeLL(head1,head2));

    return 0;
}