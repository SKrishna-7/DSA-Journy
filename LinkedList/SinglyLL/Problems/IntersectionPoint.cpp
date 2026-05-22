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

Node* intersectionPoint_brute(Node* head1,Node* head2){

    
    while(head1 != nullptr){
        Node* temp=head2;
        while(temp != nullptr){

            if(temp == head1){
                return temp;
            }
            temp=temp->next;
        }

        head1 = head1->next;

    }

    return nullptr;
}
#include<unordered_set>

Node* intersectionPoint_better(Node* head1,Node* head2){

    unordered_set<Node*> hmap;

    Node* temp = head1;

    while(temp != nullptr){
        hmap.insert(temp);
        temp=temp->next;
    }

    temp=head2;

    while(temp != nullptr){
        if(hmap.find(temp) != hmap.end()){
            return temp;
        }

        temp = temp->next;
    }

    return nullptr;

}

int findLength(Node* head){
    
    Node* temp=head;
    int len = 0;
    while(temp!=nullptr){
        len++;
        temp = temp->next;
    }

    return len;
}

Node* intersectionPoint_optimal_1(Node* head1,Node* head2){

    int l1 = findLength(head1);
    int l2 = findLength(head2);

    Node* temp1 = head1;
    Node* temp2 = head2;

    if(l1>l2){
        int diff = l1-l2;

        while(diff > 0 ){
            temp1 = temp1->next;
            diff--;
        }
    }

    else if(l2>l1){
        int diff = l2-l1;

        while(diff > 0){
            temp2 = temp2->next;
            diff--;
        }
    }


    while(temp1 != nullptr && temp2 != nullptr){
        
        if(temp1 == temp2) return temp1;

        temp1=temp1->next;
        temp2= temp2->next;
    }

    return nullptr;


}

Node* intersectionPoint_optimal_2(Node* head1,Node* head2){


        if(head1 ==nullptr || head2 == nullptr) return nullptr;
        
        Node* temp1 = head1;
        Node* temp2 = head2;

        while(temp1 != temp2){

            temp1 = (temp1 == nullptr) ? head2 : temp1=temp1->next;
            temp2 = (temp2 == nullptr) ? head1 : temp2=temp2->next;

            if(temp1 == temp2) return temp1;
        }

        return temp1;
}

int main() {
    
    int arr1[] = {1,2};
    int arr2[] = {1,2,3};
    int arr3[] = {4,5,6,7};



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
    tail1->next = head3;


    Node* tail2 = head2;
    while (tail2->next != nullptr) {
        tail2 = tail2->next;
    }
    tail2->next = head3;
    
    // traverse(head1);    
    // cout<<endl;
    // traverse(head2);
    
    Node* intersectionPoint = intersectionPoint_optimal_2(head1,head2);

    cout<<intersectionPoint->data << endl;
    return 0;
}