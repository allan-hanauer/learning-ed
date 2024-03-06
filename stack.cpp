#include <iostream>

using namespace std;

struct No {
    int value;
    No* next = nullptr;
};

struct Pilha {
    No* Header = nullptr;

    void append(int value) {
        No* newno = new No;
        newno->value = value;
        newno->next = Header;
        Header = newno;
    }

    bool print() {
        if (Header == nullptr){cout <<"[]";  return false;}
        No* current = Header;
        cout << "[";
        while (current != nullptr) {
            if(current->next == nullptr){
                cout << current->value << "]";
            }else{
            cout << current->value <<",";
            }
            current = current->next;
        }
        return true;
    }
    bool pop(){
        if(Header == nullptr) return false;
        Header = Header->next;
        return true;
    }
    int findValue(int value){
        No* current = Header;
        int i= 0;
        while(current != nullptr){
            if(current->value == value){
                return i;
            }else{
                current = current->next;
                i++;
            }
        }
        return -1;
    }
};

int main() {
    Pilha a1;
    a1.append(10);
    a1.print();
    a1.append(20);
    a1.print();
    a1.append(25);
    a1.append(31);
    a1.print();
    cout << a1.findValue(10) << endl;
    a1.pop();
    a1.pop();
    a1.pop();
    a1.print();
    return 0;
}
