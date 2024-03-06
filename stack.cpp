#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

struct Stack {
    Node* top = nullptr;

    void push(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = top;
        top = newNode;
    }

    void print() {
        if (top == nullptr) {
            cout << "[]";
            return;
        }
        Node* current = top;
        cout << "[";
        while (current != nullptr) {
            if (current->next == nullptr) {
                cout << current->value << "]";
            } else {
                cout << current->value << ",";
            }
            current = current->next;
        }
    }

    bool pop() {
        if (top == nullptr) {
            return false;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        return true;
    }

    int findValue(int value) {
        Node* current = top;
        int index = 0;
        while (current == nullptr) {
            if (current->value == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.print();
    cout << endl;

    stack.push(20);
    stack.print();
    cout << endl;

    stack.push(25);
    stack.push(31);
    stack.print();
    cout << endl;

    cout << "Index do numero 10: " << stack.findValue(10) << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.print();
    cout << endl;

    return 0;
}
