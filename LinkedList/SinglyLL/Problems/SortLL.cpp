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

Node* findMiddle(Node* head){

    Node* slow = head;
    Node* fast = head->next;

    while(fast != nullptr && fast->next != nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;

}
Node* mergeLL(Node* list1 , Node* list2){

    Node* Dummy = new Node(-1);
    Node* current = Dummy;

    while(list1 != nullptr && list2 != nullptr){

        if(list1->data < list2->data){
            
            current->next = list1;
            current = list1;
            list1 = list1->next;

        }else{

            current->next = list2;
            current = list2;
            list2 = list2->next;

        }
    }

    if(list1 != nullptr) current->next = list1;
    else current->next = list2;

    Node* mergeHead = Dummy->next;
    delete Dummy;

    return mergeHead;

}

Node* SortLL(Node *head){

    if(head == nullptr || head->next == nullptr ) return head;

    Node* midNode = findMiddle(head);
    Node* leftLL = head; 
    Node* rightLL = midNode->next;
    midNode->next = nullptr;

    Node* leftHead = SortLL(leftLL);
    Node* rightHead = SortLL(rightLL);

    return mergeLL(leftHead,rightHead);

}

int main() {
    
    int arr1[] = {2,4,7,8,9,0};
    int size1=sizeof(arr1) / sizeof(arr1[0]);
    
    int k=2;
    
    Node* head = convertArrToLL(arr1,size1);
    
    traverse(SortLL(head));    
    cout<<endl;
   
        
    return 0;
}