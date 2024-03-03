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

int main(void) {
    LISTA a;
    inicializarLista(&a);
    return 0;
}
