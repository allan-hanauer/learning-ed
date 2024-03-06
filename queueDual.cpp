
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
    Node* previous = nullptr;
};

struct Queue {
    Node* first = nullptr;
    Node* last = nullptr;

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        if (isEmpty()) {
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            newNode->previous = last;
            last = newNode;
        }
    }

    bool dequeue() {
        if (isEmpty()) {
            return false;
        } else {
            Node* temp = first;
            first = first->next;
            if (first)
                first->previous = nullptr;
            delete temp;
            return true;
        }
    }

    void print() {
        if (isEmpty()) {
            cout << "[]" << endl;
        } else {
            cout << "[";
            Node* current = first;
            while (current != nullptr) {
                if (current->next == nullptr)
                    cout << current->value << "]" << endl;
                else
                    cout << current->value << ", ";
                current = current->next;
            }
        }
    }

    bool isEmpty() {
        return (first == nullptr);
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
    a1.~Queue();
    a1.print();
    return 0;
}
