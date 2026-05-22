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

#include<stack>

bool Palindrome_brute(Node* head){

    stack<int> st;

    Node* temp = head;

    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    
    while(temp != nullptr){
        
        if(temp->data != st.top()) return false;
        st.pop();
        temp=temp->next;
    }
    return true;

}

Node* reverse(Node * head){

    if(head == nullptr || head->next == nullptr) return head;

    Node* newHead = reverse(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;

}

bool Palindrome_optimal(Node* head){


    Node* slow=head;
    Node* fast=head;

    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast ->next->next;
    }

    Node* secondHead = reverse(slow->next);
    Node* first = head;
    Node* second = secondHead;

    bool isPalindrome=true;

    while(second != nullptr){

        if(first->data != second->data) {
            isPalindrome = false;
            break;
        }

        first = first->next;
        second = second->next;
    }

    slow->next = reverse(secondHead);

    return isPalindrome;


}


    
int main() {
    
    int arr1[] = {1,2,3,2,1};


    int size1=sizeof(arr1) / sizeof(arr1[0]);
    
    Node* head = convertArrToLL(arr1,size1);
    
    cout<< boolalpha << Palindrome_optimal(head) << endl;
    traverse(head);
    cout<<endl;
    
    return 0;
}