#include <iostream>
using namespace std;

class Node {

public:
    int data;
    Node* next;   
    Node* bottom; 
    
    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

Node* convertArrToVerticalLL(int arr[], int size) {
    if (size == 0) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* temp = head;
    
    for (int i = 1; i < size; i++) {
        temp->bottom = new Node(arr[i]);
        temp = temp->bottom;
    }
    return head;
}

void traverse(Node* head){
    
    Node* temp=head;
    while(temp != nullptr){
        cout<< temp->data << " ->  ";
        temp=temp->bottom;
    }
    cout << "nullptr" << endl;
}


#include<vector>
#include<algorithm>
Node* flatten_brute(Node* head){

    Node* temp = head;
    vector<int> arr;

    while(temp != nullptr){

        Node* t = temp;
        while(t != nullptr){
            
            arr.push_back(t->data);
            t=t->bottom;
        }
        temp = temp->next;
    }
   
    sort(arr.begin(),arr.end());

    Node* DummyNode = new Node(-1);
    Node* current = DummyNode;

    for(int i=0;i<arr.size();i++){

        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        current = current->next;

    }
    head = DummyNode->next;
    delete DummyNode;

    return head;
}

Node* mergeLL(Node* list1 , Node* list2){

    Node* Dummy = new Node(-1);
    Node* current = Dummy;

    while(list1 != nullptr && list2 != nullptr){

        if(list1->data < list2->data){
            
            current->bottom = list1;
            current = list1;
            list1 = list1->bottom;
            
        }
        else{

            current->bottom = list2;
            current = list2;
            list2 = list2->bottom;
        }

        current->next = nullptr;
    }

    if(list1 != nullptr){
            current->bottom = list1;
        }
        
    if(list2 != nullptr){
            current->bottom = list2;
        }

    Node* finalHead = Dummy->bottom;
    delete Dummy;

    return finalHead;

}

Node* flatten_optimal(Node* head){

    if(head == nullptr || head->next == nullptr) return head;

    Node* newHead = flatten_optimal(head->next);

    head= mergeLL(head,newHead);
    return head;
}

int main() {
    int arr1[] = {5, 7, 8, 30};
    int arr2[] = {10, 20};
    int arr3[] = {19, 22, 50};
    int arr4[] = {28, 35, 40, 45};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    
    Node* head1 = convertArrToVerticalLL(arr1, size1);
    Node* head2 = convertArrToVerticalLL(arr2, size2);
    Node* head3 = convertArrToVerticalLL(arr3, size3);
    Node* head4 = convertArrToVerticalLL(arr4, size4);

    head1->next = head2;
    head2->next = head3;
    head3->next = head4;

    
    traverse(flatten_optimal(head1));

    return 0;
}