#include<iostream>
#include<vector>

using namespace std;

struct Node{      // data , next

    int data;
    Node* next;
    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }
};

//arr -> LL

Node* convertArrToLL(int arr[],int size){

    Node* head= new Node(arr[0],nullptr);
    Node* mover=head;

    for(int i=1;i<size;i++){

        Node *temp = new Node(arr[i],nullptr);
        mover->next = temp;
        mover=temp;      

    }
    return head;
}

void printLL(Node* head){

    Node* temp=head;
    int cnt=0;

    while(temp != nullptr){
        cout<<temp->data << endl;
        temp = temp->next;
        cnt++;
    }
    // cout<<"nullptr";
}

// Len of LL
int lengthOfLL(Node* head){
  Node* temp=head;
    int cnt=0;

    while(temp != nullptr){
        temp = temp->next;
        cnt++;
    }

    return cnt;
  
}

//Search at LL
bool checkValInLL(Node* head , int val){

    Node* temp=head;
    while(temp != nullptr){
        if(temp->data == val) return true;
        temp=temp->next;

    }

    return false;
}



int main(){

    int arr[5] = {1,2,3,4,5};

    int size=sizeof(arr) / sizeof(arr[0]);

    Node *head = convertArrToLL(arr,size);

    // cout<<head->data << endl;
    // cout<<head->next->data<<endl;
    // cout<<head->next->next->data;

    printLL(head);
    cout << lengthOfLL(head)<<endl;

    cout << boolalpha <<checkValInLL(head,5);
    
    
    return 0;
}