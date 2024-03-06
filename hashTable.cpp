#include <iostream>
using namespace std;

struct Value {
    int price;
};

struct Node {
    string key;
    Value* price = nullptr;
    Node* next = nullptr;
};

struct HashTable {
    Node* First = nullptr;

    void insertKey(string key) {
        Node* current = First;
        while (current != nullptr) {
            if (current->key == key) {
                return;
            }
            current = current->next;
        }

        Node* newNode = new Node();
        newNode->key = key;
        if (First == nullptr) {
            First = newNode;
        } else {
            current = First;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertValue(string key, int value) {
        Value* newValue = new Value();
        newValue->price = value;
        Node* current = First;
        while (current != nullptr) {
            if (current->key == key) {
                current->price = newValue;
                return;
            } else {
                current = current->next;
            }
        }
        return;
    }

    void print() {
        Node* current = First;
        cout << "{" << endl;
        while (current != nullptr) {
            if (current->price != nullptr) {
                cout << current->key << " : " << current->price->price << ", " << endl;
            }
            current = current->next;
        }
        cout << "}" << endl;
    }
};

int main(void) {
    HashTable a1;
    a1.insertKey("Banana");
    a1.insertKey("Maca");
    a1.insertValue("Banana", 10);
    a1.insertKey("Morango");
    a1.insertValue("Morango", 10);
    a1.insertValue("Maca", 20);
    a1.print();
    return 0;
}
