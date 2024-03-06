#include <iostream>
using namespace std;
struct Value{
    int price;
};
struct Node{
    string key;
    Value* price=nullptr;
    Node* next=nullptr;
};

struct HashTable{
    Node* First=nullptr;
    void insertKey(string key){
        Node* newNode = new Node();
        newNode->key = key;
        if(First == nullptr){
            cout << "Sucesso" << endl;
            First = newNode;
        }else{
        Node* current = First;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
        }
    }
};

int main(void){
    HashTable a1;
    a1.insertKey("Banana");
    a1.insertKey("Maça");
    cout << a1.First->key << endl;
    cout << a1.First->next->key;
    return 0;
}
