#include <iostream>
using namespace std;

#define MAX 50
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElement;
} LISTA;

void inicializarLista(LISTA* l) {
    l->nroElement = 0;
}
void reinicializarLista(LISTA* l) {
    l->nroElement = 0;
}
int tamanhoLista(LISTA* l){
    return l->nroElement;
}
void exibirLista(LISTA* l) {
    cout << "[";
    for (int i = 0; i < l->nroElement; i++) {
        cout << l->A[i].chave;
        if (i < l->nroElement - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
bool adicionarLista(LISTA* l, REGISTRO reg ,int i) {
    int j;
    if((l->nroElement == MAX) || (i < 0) || (i > l->nroElement)) return false;
    for(j=l->nroElement; j > i; j--) l->A[j] = l->A[j-1];
    l->A[i] = reg;
    l->nroElement++;
    return true;
}
int buscaSequencial(LISTA* l, int valor){
    int i=0;
    while(i < l->nroElement){
        if(l->A[i].chave == valor){
            return i;
        }
        i++;
    }
    return -1;
}
bool excluirElement(LISTA* l, int valor){
    int pos,j;
    pos = buscaSequencial(l,valor);
    if(pos == -1) return false;
    for(j = pos; j < l->nroElement; j++){
        l->A[j] = l->A[j+1];
    }
    l->nroElement --;
    return true;
}
int main(void) {
    LISTA a;
    inicializarLista(&a);

    REGISTRO reg1, reg2;
    reg1.chave = 10;
    reg2.chave = 30;

    adicionarLista(&a, reg1, 0);
    adicionarLista(&a, reg2, 1);

    excluirElement(&a, 10);

    cout << tamanhoLista(&a) << endl;
    exibirLista(&a);
    cout << buscaSequencial(&a, 2) << endl;

    return 0;
}
