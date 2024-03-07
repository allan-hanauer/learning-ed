#include <iostream>
#include <cmath>

using namespace std;

struct No {
    int value = -1;
    No* collision = nullptr;
};

class HashTable {
    public:
        int Size;
        No Arr[6];

    public:
        HashTable(int Size) {
            this->Size = Size;
            Arr = new No[Size];
        }
        void append(string key, int value){
            if(Arr[0].value == -1 && Arr[0].collision == nullptr){
                    Arr[0]->value = value;
            }
        }
        int hashCreate(string a){
            const int prime = 31;
            const int modulo = 100;

            long long sum = 0;
            for(int i = 0; i < a.length(); i++) {
                sum += (sum * prime + a[i]) % modulo;
            }

            return sum;
        }
        ~HashTable() {
            delete[] Arr;
        }

};


int main(void){
    HashTable* a = new HashTable(100);
    a->append("carro",10);
    a->append("carro",20);
    cout << a->Arr[0].collision->value;
    return 0;
}
