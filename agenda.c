#include <stdio.h>
#include <stdlib.h>

typedef struct agenda{
    char nome[30];
    int numero;
    struct agenda *prox;
}ag;

void AddContato();
void RemContato();
void FindContato();
void ListContato();
void OptMenu(int *opt);
void menu();

int main(){
    void *buffer;
    int *optmenu;
    buffer=malloc(sizeof(int));
    if(buffer==NULL)exit(1);
    optmenu=buffer;
    
    while(*optmenu!=5){
        menu();
        scanf("%d", optmenu);
        OptMenu(optmenu);
    }
}

void menu(){
    printf("\n1-Adicionar Contato\n2-Remover Contato\n3-Buscar Contato\n4-Listar Contatos\n5-Sair\n");
}

void OptMenu(int *opt){
    switch(*opt){
        case 1: AddContato();
        break;
        case 2: RemContato();
        break;
        case 3: FindContato();
        break;
        case 4: ListContato();
        break;
        case 5: exit(1);
        default: printf("\nOpção não encontrada\n");

    }
}

void AddContato(){
    printf("\naddcontato\n");   
}

void RemContato(){
    printf("\nremcontato\n");
}

void FindContato(){
    printf("\nfindcontato\n");
}

void ListContato(){
    printf("\nlistcontato\n");
}