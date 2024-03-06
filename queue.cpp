#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

struct Queue {
    Node* first = nullptr;
    Node* last = nullptr;

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        if (isEmpty()) {
            first = newNode;
        } else {
            last->next = newNode;
        }
        last = newNode;
    }

    bool dequeue() {
        if (isEmpty()) {
            return false;
        } else {
            Node* temp = first;
            first = first->next;
            delete temp;
            if (!first)
                last = nullptr;
            return true;
        }
    }

    void print() {
        if (isEmpty()) {
            cout << "[]" << endl;
        } else {
            cout << "[";
            for (Node* current = first; current != nullptr; current = current->next) {
                cout << current->value;
                if (current->next != nullptr)
                    cout << ", ";
            }
            cout << "]" << endl;
        }
    }

    bool isEmpty() {
        return first == nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue a1;
    a1.enqueue(10);
    a1.enqueue(20);
    a1.print();
    a1.dequeue();
    a1.print();
    a1.enqueue(30);
    a1.print();
    a1.dequeue();
    a1.print();
    return 0;
}
