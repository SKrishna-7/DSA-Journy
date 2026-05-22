#include<iostream>

using namespace std;

struct Node{

    int data;
    Node* next=nullptr;

    Node(int data,Node* next){
        this->data = data;
        this->next = next;
    }

    Node(int data){
        this->data=data;
    }
};

Node* InsertArrtoLL(int arr[],int size){


    Node* head=new Node(arr[0],nullptr);

    Node *mover = head;

    for(int i=1;i<size;i++){

        mover->next =new Node(arr[i],nullptr);
        mover = mover->next;
    }

    return head;
}

void printLL(Node* head){

    Node* temp = head;
    while (temp != nullptr)
    {
        cout<<temp->data << endl;
        temp=temp->next;
    }
}




Node *deleteHead(Node* head){

    Node* temp=head;
    
    head=temp->next;
    
    delete temp;
    return head;
}

Node *deleteTail(Node* head){

    Node* temp=head;
    
    if(head == nullptr) return nullptr;

    if(head->next == nullptr){
        delete head;
        return nullptr;
    }

    while(temp->next->next != nullptr){
        temp=temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}


Node* deleteKNode(Node* head,int k){

    if(head == nullptr) return nullptr;

    Node* temp=head;
    if(k==1){
        head=head->next;
        delete temp;
        return head;
    }

    Node* prev=nullptr;
    int cnt=0;

    while(temp != nullptr){

        cnt++;
        if(cnt == k){

            prev->next = prev->next->next;
            delete temp;
            break;
        }

        prev=temp;
        temp = temp->next;

    }

    return head;
}

Node* deleteElement(Node* head,int k){

    if(head == nullptr) return nullptr;

    Node* temp=head;
    if(head->data == k){
        head=head->next;
        delete temp;
        return head;
    }

    Node* prev=nullptr;

    while(temp != nullptr){

        if(temp->data == k){

            prev->next = prev->next->next;
            delete temp;
            break;
        }

        prev=temp;
        temp = temp->next;

    }

    return head;
}




Node *insertAtHead(Node* head,int val){

    head= new Node(val,head);
    return head;
}

Node *insertAtTail(Node* head,int val){

    if(head == nullptr) {
        Node* newNode= new Node(val);
        return newNode;
    }   

    Node* temp = head;
    while(temp->next !=nullptr){
        temp=temp->next;
    }

    temp->next=new Node(val);

    return head;
}


Node* insertAtK(Node* head , int k,int val){

    if(head == nullptr){
        Node* newNode= new Node(val,nullptr);
        return head;
    }

    if(k == 1){
        
        Node *head= new Node(val,head);
        return head;
    }

    Node* temp=head;
    int cnt=0;

    while(temp != nullptr){

        cnt++;

        if(cnt == k-1){

            Node* newNode = new Node(val,temp->next); 

            // newNode->next = temp->next ;
            temp->next = newNode;
            break;
        }

        temp=temp->next;
    }

    return head;

}


Node* insertBeforeX(Node* head , int x,int val){

    if(head == nullptr){
        return nullptr;
    }

    if(x == head->data){
        
        Node *head= new Node(val,head);
        return head;
    }

    Node* temp=head;

    while(temp != nullptr){


        if(temp->next->data == x){

            Node* newNode = new Node(val,temp->next); 

            // newNode->next = temp->next ;
            temp->next = newNode;
            break;
        }

        temp=temp->next;
    }

    return head;

}



int main(){

    int arr[5] = {10,20,30,40,50};
    int size=sizeof(arr) / sizeof(arr[0]);

    // Node n1(10,nullptr);
    // cout<<n1.data;

    Node *head = InsertArrtoLL(arr,size);

    // cout<< n2->next->data;
    // Insert at head;

    // printLL(head);
    
    // cout<<endl;
    printLL(head);
    
    // head = deleteHead(head);
    
    cout<<endl;
    
    // printLL(head);
    // head = deleteTail(head);
    
    // cout<<endl;
    
    int k=3;
    // head=deleteKNode(head,k);
    // head=deleteEelement(head,50);

    // head = insertAtHead(head,0);
    // head = insertAtTail(head,100);

    // head =insertAtK(head,4,80);
    head =insertBeforeX(head,50,60);
    printLL(head);

    return 0;
}