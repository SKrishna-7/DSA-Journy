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

Node* oddEven(Node* head){
    
        Node* temp = head;
        
        vector<int> arr ;
        
        while(temp != nullptr && temp->next != nullptr){
            
            arr.push_back(temp->data);
            temp = temp->next->next;
        }
        if(temp){
            arr.push_back(temp->data);
        }
        
        temp = head->next;
        while(temp != nullptr && temp->next != nullptr){
            arr.push_back(temp->data);
            temp=temp->next->next;
        }
        if(temp) arr.push_back(temp->data);
        
        temp=head;
        int i=0;
        
        while(temp!=nullptr){
            
            temp->data = arr[i];
            i++;
            temp = temp->next;
        }
        
       return head;
}

Node* oddEven_optimal(Node* head){
    
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    
    
    while(even != nullptr && even->next!=nullptr){
        
        odd->next = odd->next->next;
        even->next = even->next->next;
        
        odd=odd->next;
        even=even->next;
    }
    
    odd->next = evenHead;
    
    return head;
    
}
int main() {
    
    int arr1[] = {2,4,3,5,6,7,8,9};

    int size1=sizeof(arr1) / sizeof(arr1[0]);
    
    Node* head = convertArrToLL(arr1,size1);
    
   Node* newhead = oddEven_optimal(head);
   traverse(newhead);
   
    
    return 0;
}