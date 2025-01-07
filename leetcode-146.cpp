#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
    public:
        int key, value;
        Node *next, *prev;
        Node(): key(0), value(0) {
            next = nullptr;
            prev = nullptr;
        };
        Node(int k, int v) : key(k), value(v){
            next = nullptr;
            prev = nullptr;
        };
         Node(int k, int v, Node *nNode, Node *pNode) : key(k), value(v){
            next = nNode;
            prev = pNode;
        };
    friend class LRUCache;
};

class LRUCache {
    private:
        int capacity;
        Node *front, *tail, *currentPtr;
        unordered_map<int, Node*>  cacheMap; // {Key, Node}
       
        void moveToFront(Node* node){
           if(node == front) return;

           node->prev->next = node->next; // skip current node, link the previous node's next to current node's next node
           if(node->next) node->next->prev = node->prev; // skip current node, link the next node's prev to current node's prev node
           else tail = node->prev; // if current node's tail node, then update tail pointer to the previous node

           node->next = front; // Insert current node to the front
           node->prev = nullptr;
           front -> prev = node; // Update front pointer
           front = node;
        };

        // Remove the lease recent use entry from the cache
        void removeTail(){
            if(tail==nullptr) return;


            //update cacheMap
            cacheMap.erase(tail->key);
            //updae pointers
            if(tail->prev){
                tail = tail->prev;
                tail->next = nullptr; 
            }
            else{
                front = tail = nullptr;
            }
        };  

    
    public: 
        LRUCache(int cap) : capacity(cap), front(nullptr), tail(nullptr) {};

        int get(int key) {
            if(cacheMap.find(key) != cacheMap.end()){
                Node *node = cacheMap[key];
                //update cache
                moveToFront(node);
                return node->value;
            }
            else return -1;
        }
        
        void put(int key, int value) {
            if(cacheMap.find(key) != cacheMap.end()){
                Node *node = cacheMap[key];
                node->value = value;
                moveToFront(node);
            }
            else{ // Update to cache (1) Check if cache is full (2) add to cache
                Node *newData = new Node(key, value);
                if(cacheMap.size() == capacity){
                    removeTail(); // Remove least recently used node
                }

                if(front==nullptr){
                    front = tail = newData;
                }
                else{
                    newData->next = front;
                    front->prev = newData;
                    front = newData;
                }

                //update cache map
                cacheMap[key] = newData;
            }
        }
};


int main(){

    LRUCache cache(2); // Capacity = 2
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // Returns 1
    cache.put(3, 3);              // Evicts key 2
    cout << cache.get(2) << endl; // Returns -1 (not found)
    cache.put(4, 4);              // Evicts key 1
    cout << cache.get(1) << endl; // Returns -1 (not found)
    cout << cache.get(3) << endl; // Returns 3
    cout << cache.get(4) << endl; // Returns 4

    return 0;
}