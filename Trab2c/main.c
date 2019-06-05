#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct{
    char caracter;
    int porcentagem;
}Hnodo; //nodo de huffmann */

struct Node {
    char caracter;
    double porcentagem;
    struct Node* pai;
    struct Node* esq;
    struct Node* dir;
};

typedef struct Node NODO;

// prototipos
void inserir(NODO** arv, int val);
void mostrar(NODO* arv);
NODO* pesquisar(NODO* arv, int val);

// código

void inserir(NODO** arv, int val) {
    if ( *arv == NULL ) {
        NODO* novo;
        novo = malloc(sizeof(NODO));
        novo->porcentagem = val;   //(*novo).valor = val;
        novo->pai = NULL;
        novo->esq = NULL;
        novo->dir = NULL;

        *arv = novo;
    } else {
        //if ( val < (**arv)valor)
        if ( val < (*arv)->porcentagem)
           //inserir(&((**arv).esq),val);
           inserir(&((*arv)->esq), val);
        else
           inserir(& ((*arv)->dir), val);
    }
}

NODO* pesquisar(NODO* arv, int val) {
    if ( arv ==NULL) return NULL;

    if ( arv->porcentagem == val)
        return arv;
    else if ( arv->porcentagem > val)
            return pesquisar(arv->esq, val);
         else
            return pesquisar(arv->dir, val);
}



void mostrar(NODO* arv) {
    if (arv == NULL) return;

    mostrar(arv->esq);
    printf("%d ", arv->porcentagem);
    mostrar(arv->dir);

}

int main() {
    //struct Node* raiz = NULL;
    //NODO* raiz = NULL;
    NODO* aux2;
    NODO* aux;
    NODO* auxp;
    int i = 0;
    FILE *fp = fopen("nomearq.txt","r");
    char c;
    char lista[5];
    if(fp == NULL){
        perror("Não ta lendo");
    }else{
        while ( (c = fgetc(fp)) != EOF){
            printf("char:%c\n",c);
            lista[i] = c;
            i++;
        }
    }
    int contb = 0;
    int conta = 0;
    for(int p = 0; p<= sizeof(lista); p++){
        printf("%c \n", lista[p]);//ta pegando coisa q noa precisa
        if(lista[p] == 'a'){
            conta++;
        }else if(lista[p] == 'b'){
            contb++;
        }

    }
    printf("print :%d,%d", conta,contb);//esta pegando certo

    inserir(auxp, conta+contb);
    inserir(aux,conta);
    inseiri




}
