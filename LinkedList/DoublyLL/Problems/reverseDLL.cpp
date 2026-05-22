#include<iostream>
#include<stack>

using namespace std;

struct Node{

    int data;
    Node* next=nullptr;
    Node* back=nullptr;

    Node(int data,Node* next,Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }
    Node(int data){
        this->data= data;
    }

};


Node* arrToDll(int arr[],int size){

    Node* head=new Node(arr[0]);

    Node* prev=head;

    for(int i=1;i<size;i++){   

        Node* temp=new Node(arr[i]);
        
        prev->next = temp;
        temp->back = prev;
        prev=temp;
        
    }

    return head;
    
}

void printDll(Node *head){

    Node* temp=head;

    while(temp!=nullptr){
        cout<<temp->data << endl;
        temp=temp->next;
    }
}


Node* reverseDll_brute(Node* head){

    stack<int> st;

    Node* temp=head;

    while(temp!=nullptr){

        st.push(temp->data);
        temp=temp->next;
    }

    Node* temp1=head;

    while(temp1!=nullptr){

        temp1->data = st.top();
        st.pop();
        temp1=temp1->next;
    }

    return head;
}

Node* reverseDll_optimal(Node* head){


    Node* crnt=head;
    Node* prev=nullptr;

    while(crnt != nullptr){

        prev=crnt->back;
        crnt->back = crnt->next;
        crnt->next = prev;

        crnt = crnt->back;

    }

    return prev->back;

}
int main(){

    int arr[] = {1,2,3,4,5};

    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head=arrToDll(arr,size);
    printDll(head);
    cout<<endl;
    
    // head=reverseDll_brute(head);
    head=reverseDll_optimal(head);
    printDll(head);
    

    return 0;
}