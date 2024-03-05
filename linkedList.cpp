#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next=nullptr;
};
struct Lista{
    Node* head=nullptr;
    Node* tail=nullptr;
};
void inserirInicio(Lista* l,int data){
    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = l->head;
    l->head = newnode;
    if (l->tail == nullptr) {
        l->tail = newnode;
    }
}
void inserirFinal(Lista* l, int data) {
    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = nullptr;

    if (l->head == nullptr) {
        l->head = newnode;
        l->tail = newnode;
    } else {
        l->tail->next = newnode;
        l->tail = newnode;
    }
}
bool deletarElemento(Lista *l, int elemento) {
    if (l->head == nullptr)
        return false;

    Node* current = l->head;
    Node* previous = nullptr;
    if (current->data == elemento) {
        l->head = current->next;
        if (l->head == nullptr) {
            l->tail = nullptr;
        }
        delete current;
        return true;
    }
    while (current != nullptr) {
        if (current->data == elemento) {
            previous->next = current->next;
            if (current->next == nullptr) {
                l->tail = previous;
            }
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }

    return false;
}
void imprimirLista(Lista* l) {
    Node* current = l->head;
    cout << "Lista ligada: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Lista a;
    inserirInicio(&a,30);
    inserirInicio(&a,10);
    inserirInicio(&a,20);
    inserirFinal(&a,10);
    imprimirLista(&a);
    deletarElemento(&a,20);
    deletarElemento(&a,10);
    deletarElemento(&a,30);
    deletarElemento(&a,10);
    deletarElemento(&a,10);
    cout << a.tail << endl;
    imprimirLista(&a);
    return 0;
}
