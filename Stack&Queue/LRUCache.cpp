#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Node{
  
  public:
    int key;
    int val;
    Node *next;
    Node *prev;
    
    Node(int key,int val){
        this->key = key;
        this->val = val;
        next=nullptr;
        prev=nullptr;
    }
    
};


class LRU{
  
  public:
  
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> m;
    
    LRU(int capacity){
        
    this->capacity=capacity;
    
    head = new Node(-1,-1);
    tail = new Node(-1,-1);
    
    head->next = tail;
    tail->prev = head;
    
    }
    
void addNode(Node* newNode){
    
    Node* first = head->next;
    
    head->next = newNode;
    first->prev = newNode;
    newNode->next = first;
    newNode->prev = head;
}

void deleteNode(Node* nodeToDel){
        Node* back = nodeToDel->prev;
        Node* front = nodeToDel->next;
        
        back->next = front;
        front->prev= back;
        
}
void put(int key,int val){
    
    if(m.find(key) != m.end()){
      
        Node* existingNode = m[key];
        existingNode -> val = val;
        
        deleteNode(existingNode);
        addNode(existingNode);
        m[key] = head->next;
        
    }else {
        if(m.size() == capacity){
        
        cout<<"\n Capacity full \n";
        Node* toDel = tail->prev;
        cout<<"\n Deleted :  "<< toDel->key << endl;
        deleteNode(toDel);
        m.erase(toDel->key);
        delete toDel;
        
    }
    
    Node* newNode= new Node(key,val);
    addNode(newNode);
    m[key] = head->next;
    
        
    }
}

int get(int key){
    
    if(m.find(key) != m.end()){
        
        Node* accessedNode = m[key];
        
        deleteNode(accessedNode);
        addNode(accessedNode);
        
        m[key] = head->next;
        return accessedNode->val;
    }
    
    return -1;
}
};
int main() {
    
    LRU lruCache(4);
    // lruCache.put(3,5);
    // lruCache.put(2,4);
    // lruCache.put(1,1);
    lruCache.put(7,0);
    lruCache.put(6,9);
    lruCache.put(87,4);
    

    cout<<lruCache.get(87);


    cout<<endl;
    

   
    return 0;
}