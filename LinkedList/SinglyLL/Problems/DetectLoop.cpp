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

#include<unordered_set>

bool isLooped_brute(Node* head){

    unordered_set<Node*> visited;

    while(head != nullptr){

        if(visited.find(head) != visited.end()){
            return true;
        }

        visited.insert(head);
        head= head->next;
    }

    return false;

}


bool isLooped_optiml(Node* head){

   
    Node* slow=head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){

        slow= slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
   
    return false;

}


int main() {
    
    int arr1[] = {1,2};
    int arr2[] = {4,5,6,7};

    int arr3[] = {1,2,3,4,5,6,7};


    int size1=sizeof(arr1) / sizeof(arr1[0]);
    int size2=sizeof(arr2) / sizeof(arr2[0]);
    int size3=sizeof(arr3) / sizeof(arr3[0]);

    
    Node* head1 = convertArrToLL(arr1,size1);
    Node* head2 = convertArrToLL(arr2,size2);
    
    Node* head3 = convertArrToLL(arr3,size3);

    Node* tail1 = head1;
    while (tail1->next != nullptr) {
        tail1 = tail1->next;
    }
    tail1->next = head2;


    Node* tail2 = head2;
    while (tail2->next != nullptr) {
        tail2 = tail2->next;
    }
    tail2->next = head2;
    
   
    cout<<boolalpha << isLooped_optiml(head1) << endl;
    return 0;
}