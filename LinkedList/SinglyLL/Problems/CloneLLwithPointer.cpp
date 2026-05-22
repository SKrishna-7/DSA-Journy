#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Function to convert array to a basic linked list (next pointers only)
Node* convertArrToLL(int arr[], int size) {
    if (size == 0) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for (int i = 1; i < size; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to print the list to verify connections
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "[val: " << temp->val << ", random: ";
        if (temp->random) {
            cout << temp->random->val;
        } else {
            cout << "null";
        }
        cout << "] -> ";
        temp = temp->next;
    }
    cout << "null\n";
}


Node* insertInBtw(Node* head){

        Node* temp = head;

        while(temp != nullptr){
            
            Node *cpyNode = new Node(temp->val);
            cpyNode->next = temp->next;
            temp->next = cpyNode;

            temp=temp->next->next;
        }

        return head;
    }

Node* connectRandomPointers(Node* head){

        Node* temp = head;

        while(temp!=nullptr){

        Node* cpyNode = temp->next;

            if(temp->random){
                cpyNode->random = temp->random->next;
            }
            else{
                cpyNode->random = nullptr;
            }

            temp = temp->next->next;
        }

        return head;
    }

Node* connectNext(Node* head){

        Node* Dummy = new Node(-1);
        Node* current = Dummy;

        Node* temp = head;
        while(temp!=nullptr){

            current->next = temp->next;
            current = temp->next;
            temp->next = temp->next->next;

            temp = temp->next;
        }

        return Dummy->next;
    }


int main() {
    int arr1[] = {2, 4, 7, 8, 9, 0};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    // 1. Create the basic linked list using the array
    Node* head = convertArrToLL(arr1, size1);
    
    // 2. Store node pointers in a vector so we can easily index them
    vector<Node*> nodes;
    Node* temp = head;
    while (temp != nullptr) {
        nodes.push_back(temp);
        temp = temp->next;
    }
    
    // 3. Manually assign random pointers using the vector indices
    // Example setup:
    // Node 2 (index 0) -> random points to Node 8 (index 3)
    nodes[0]->random = nodes[3];
    
    // Node 4 (index 1) -> random points to Node 0 (index 5)
    nodes[1]->random = nodes[5];
    
    // Node 7 (index 2) -> random points to Node 2 (index 0)
    nodes[2]->random = nodes[0];
    
    // Node 8 (index 3) -> random points to Node 7 (index 2)
    nodes[3]->random = nodes[2];
    
    // Node 9 (index 4) -> random points to null (already null by default)
    nodes[4]->random = nullptr; 
    
    // Node 0 (index 5) -> random points to Node 4 (index 1)
    nodes[5]->random = nodes[1];


    insertInBtw(head);
    connectRandomPointers(head);
    
    printList(connectNext(head));
    
    
    
        
    return 0;
}