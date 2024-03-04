#include <iostream>
using namespace std;

#define MAX 50
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX+1];
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
bool adicionarListaOrd(LISTA* l, REGISTRO reg) {
    if(l->nroElement == MAX) return false;
    int pos = l->nroElement;
    while(pos >= 0 && l->A[pos-1].chave > reg.chave){
        l->A[pos] = l->A[pos-1];
        pos--;
    }
    l->A[pos] = reg;
    l->nroElement++;
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
int buscaSentinela(LISTA* l, int valor){
    int i =0;
    l->A[l->nroElement].chave = valor;
    while(l->A[i].chave != valor) i++;
    if(i == l->nroElement) return -1;
    else return i;
}
int buscaBinaria(LISTA* l, int valor){
    int esq,dir,meio;
    esq = 0;
    dir = l->nroElement -1;
    while(esq <= dir){
        meio = (dir + esq)/2;
        if(l->A[meio].chave == valor) return meio;
        else{
            if(l->A[meio].chave < valor) esq = meio +1;
            else dir = meio -1;
        }
    }
    return -1;
}
bool excluirElement(LISTA* l, int valor){
    int pos,j;
    pos = buscaBinaria(l,valor);
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

    adicionarListaOrd(&a, reg1);
    adicionarListaOrd(&a, reg2);

    excluirElement(&a, 10);

    cout << tamanhoLista(&a) << endl;
    exibirLista(&a);
    cout << buscaSequencial(&a, 2) << endl;
    cout << buscaSequencial(&a, 30) << endl;

    return 0;
}
