#include<iostream>
#include<vector>

using namespace std;

struct Node{      // data , next

    int data;
    Node* next = nullptr;

    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }

    Node(int data){
        this->data = data;
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
        cout<< temp->data << endl;
        temp = temp->next;
        cnt++;
    }
    // cout<<"nullptr";
}



Node* addTwoNumbers_brute(Node* head1,Node* head2){

        Node* t1=head1;
        Node* t2=head2;

        int nums1=0;
        int nums2=0;
        int multiplier1=1;
        int multiplier2=1;

        while(t1!=nullptr || t2 != nullptr ){

        if(t1 != nullptr){

            nums1 += t1->data * multiplier1;
            multiplier1*=10;
            t1 = t1->next;
        }

        if(t2 != nullptr){

            nums2 += t2->data * multiplier2;
            multiplier2*=10;
            t2 = t2->next;
        }
        }

        int total = nums1 + nums2;

        Node* dummyNode=new Node(-1);
        Node* current = dummyNode;

        while(total > 0){

            int last= total%10;

            Node* newNode =new Node(last);

            current->next = newNode;
            current = current->next;

            total/=10;
        }

       Node* realHead = dummyNode->next;
 
  
       return realHead;


}

Node *addTwoNumbers_optimal(Node *head1, Node *head2)
{

    int carry = 0;

    Node *dummyNode = new Node(-1);
    Node *current = dummyNode;

    Node* t1=head1;
    Node* t2=head2;

    while (t1 != nullptr || t2 != nullptr || carry != 0)
    {

        int sum = carry;

        if (t1 != nullptr)
        {
            sum += t1->data;
            t1 = t1->next;
        }

        if (t2 != nullptr)
        {
            sum += t2->data;
            t2 = t2->next;
        }

        current->next = new Node(sum%10);

        current = current->next;
        carry = sum/10;
    }

    

   
    Node *realHead = dummyNode->next;

    return realHead;
}

int main(){

    int arr1[] = {2,4,3};
    int arr2[] = {5,6,4};

    int size1=sizeof(arr1) / sizeof(arr1[0]);
    int size2=sizeof(arr2) / sizeof(arr2[0]);

    Node *head1 = convertArrToLL(arr1,size1);
    Node *head2 = convertArrToLL(arr2,size2);

    
    // Node *newHead = addTwoNumbers_brute(head1,head2);
    Node *newHead = addTwoNumbers_optimal(head1,head2);

    printLL(newHead);
    
    
    return 0;
}