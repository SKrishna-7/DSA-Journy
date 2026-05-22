#include<iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next=nullptr;
    Node* back=nullptr;

    Node(int data,Node* next,Node* back){

        this-> data= data;
        this-> next= next;
        this-> back= back;
    }
    
    Node(int data){
        this->data = data;
    }


};


Node* convertArrToDoublyLL(int arr [], int size ){

    Node* head = new Node(arr[0]);
    Node* prev=head;


    for(int i=1;i<size;i++){

        Node* newNode=new Node(arr[i]);
        prev->next = newNode;

        newNode->back = prev;

        prev=newNode;


    }
    return head;
}

void PrintDLL(Node* head){

    Node* temp = head;

    while(temp!=nullptr){

        cout<< temp->data << endl;
        temp=temp->next;
    }   
}


Node* deleteHead(Node* head){

    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* prev=head;

    head= head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;


}

Node* deleteTail(Node* head){

    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* tail=head;

    while(tail->next != nullptr){

        tail = tail->next;
       
    }


    Node* prev=tail->back;
    tail->back = nullptr;
    prev->next=nullptr;

    delete tail;
    delete prev;


    return head;


}


Node* deleteNodeAtK(Node* head , int k){

    if(head == nullptr){
        return nullptr;
    }
    if(k==1){
        Node* temp=head;
        head= head->next;

        if(head->back != nullptr){

            head->back = nullptr;
        }
        
        temp->next = nullptr;

        delete temp;
        return head;
    }

    Node* temp=head;
    int cnt=0;

    while(temp != nullptr){

        cnt++;
        if(cnt == k) break;
        temp=temp->next;
    }
    if (temp == nullptr) {
        return head; 
    }

    Node* prev= temp->back;
    Node* front= temp->next;

    if(front == nullptr){
        prev->next= nullptr;
        temp->back = nullptr;   
        delete temp;

        return head;

    }
    prev->next=front;
    front->back = prev;

    temp->back = nullptr;
    temp->next = nullptr;

    delete temp;

    return head;

}

void deleteNode(Node* node){

    Node* prev=node->back;
    Node* front=node->next;


    if(front == nullptr){

        prev->next = nullptr;
        node->back = nullptr;

        delete node;
        return;
    }


    prev->next = front;
    front->back = prev;

    node->back=nullptr;
    node->next=nullptr;

    delete node;

    return;


}


// Insertion

Node* InsertHead(Node* head ,int val){

    Node* newNode = new Node(val,head,nullptr);

    head->back = newNode;
    return newNode;


}

Node* InsertTail(Node* head ,int val){

    Node* newNode = new Node(val,nullptr,nullptr);

    if(head == nullptr){
        return newNode;
    }
    Node* temp=head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->back = temp;


    return head;


}

Node* InsertAtK(Node* head ,int val,int k){

    Node* newNode = new Node(val,nullptr,nullptr);

    if(head == nullptr){
        return newNode;
    }

    if(k==1){
        Node* temp=head;
        head= newNode;

        head->next = temp;
        return head;
    }


    Node* temp=head;
    int cnt=0;

    while(temp->next != nullptr){
        cnt++;

        if(cnt == k) break;
        temp = temp->next;

    }

    Node* prev=temp->back;

    temp->back = newNode;
    newNode->next = temp;

    prev->next= newNode;
    newNode->back = prev;

    


    return head;


}


int main(){

    int arr[] = {10,20,30,40,50};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head= convertArrToDoublyLL(arr,size);

    // cout<<head->next->data << endl;
    // cout<<head->next->back->next->data;

    // head = deleteHead(head);
    // head = deleteTail(head);

    // head=deleteNodeAtK(head,3);

    // deleteNode(head->next->next->next->next);
    // PrintDLL(head);

    // Insertion

    // head=InsertHead(head,0);
    // head=InsertTail(head,0);

    head=InsertAtK(head,0,1);
    PrintDLL(head);

    return 0;
}