#include<iostream>
#include<unordered_map>

using namespace std;



class Node{

    public:

    int key;
    int value;
    int freq;

    Node *next;
    Node *prev;

    Node(int key,int value){

       this->key = key;
       this->value = value;
       freq=1;
       next = nullptr;
       prev = nullptr;

    }

};


class List{

public: 
    int size;
    Node *head;
    Node *tail;
    

public:

    List(){

            head = new Node(-1,-1);
            tail = new Node(-1,-1);

            head->next = tail;
            tail->prev = head;
            int size=0;

        }
    
    void removeNode(Node* temp){

        Node* front = temp->next;
        Node* back = temp->prev;

        back->next = front;
        front->prev = back;

        size--;
    }

    void addFront(Node* temp){

        Node* front = head->next;
            
        head->next = temp;
        front->prev = temp;
                
        temp->next = front;
        temp->prev = head;
        size++;
            
    }
   
   
};

class LFU{

    public:

        int capacity;
        int minFreq;

        unordered_map<int,Node*> keyNodeMap;
        unordered_map<int,List*> freqMap;


    void updateFreq(Node* node){

        int currFreq = node->freq;

        List* currList = freqMap[currFreq];

        currList->removeNode(node);

        if(currFreq == minFreq && currList->size == 0){
            minFreq++;
        }

        node->freq++;

        if(freqMap.find(node->freq) == freqMap.end()){

            freqMap[node->freq] = new List();
        }

        freqMap[node->freq]->addFront(node);

        
    }


    LFU(int capacity){

        this->capacity = capacity;
        minFreq=0;
    }

    int get(int key){

        if(keyNodeMap.find(key) != keyNodeMap.end()){

            Node* node = keyNodeMap[key];

            updateFreq(node);

            return node->value;
        }
        return 0;
    }

    void put(int key,int value){

        if(keyNodeMap.find(key) != keyNodeMap.end()){

            Node* existingNode = keyNodeMap[key];
            existingNode->value = value;

            updateFreq(existingNode);

        }else if(keyNodeMap.size() == capacity){

            List* minList = freqMap[minFreq];

            Node* toDel = minList->tail->prev;
            keyNodeMap.erase(toDel->key);

            minList->removeNode(toDel);
            delete toDel;
            
        }else{

            Node* newNode = new Node(key,value);
            keyNodeMap[key] = newNode;

            
            minFreq = 1;

            if(freqMap.find(minFreq) == freqMap.end()){

                freqMap[minFreq] = new List();
            }
            freqMap[minFreq]->addFront(newNode);


        }
    }

};

int main() {
    cout << "Initializing LFU Cache with Capacity 2" << endl;
    LFU* lfu = new LFU(2);
    
    lfu->put(1, 1); // cache=[1], freq(1)=1
    cout << "Put (1, 1)" << endl;
    
    lfu->put(2, 2); // cache=[1, 2], freq(1)=1, freq(2)=1
    cout << "Put (2, 2)" << endl;
    
    cout << "Get (1): " << lfu->get(1) << " // returns 1. Freq of 1 becomes 2." << endl;
    
    // Cache is full. Freqs: key 1 (freq 2), key 2 (freq 1). 
    // Key 2 is the LFU, so it gets evicted.
    lfu->put(3, 3); 
    cout << "Put (3, 3) -> Evicts 2 (LFU)" << endl;
    
    cout << "Get (2): " << lfu->get(2) << " // returns -1 (evicted)" << endl;
    cout << "Get (3): " << lfu->get(3) << " // returns 3. Freq of 3 becomes 2." << endl;
    
    // Freqs: key 1 (freq 2), key 3 (freq 2). 
    // Both have same freq. Tie-breaker: LRU. 
    // Key 1 was accessed older than Key 3, so Key 1 is evicted.
    lfu->put(4, 4);
    cout << "Put (4, 4) -> Evicts 1 (Tie-breaker LRU)" << endl;
    
    cout << "Get (1): " << lfu->get(1) << " // returns -1 (evicted)" << endl;
    cout << "Get (3): " << lfu->get(3) << " // returns 3" << endl;
    cout << "Get (4): " << lfu->get(4) << " // returns 4" << endl;
    
    delete lfu;
    return 0;

}