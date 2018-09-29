#include <stdio.h>
#include <stdlib.h>

typedef struct contato{
    char nome[30];
    int id;
    int numero;
    struct contato *next;
}contato;

void addcontato();
void remcontato();
void findcontato();
void listcontato();
void optsmenu(int *opt);
void addlista(contato *novocontato);
contato *initagenda();

int main(){
    void *buffer,*bufferIN;
    int *optmenu;
    contato *head;

    buffer=malloc(sizeof(int));
    bufferIN=buffer;
    if(buffer==NULL)exit(1);
    optmenu=buffer;
    buffer+=4;
    head=initagenda(buffer);
    while(*optmenu!=5){
        printf("\n1-Adicionar Contato\n2-Remover Contato\n3-Buscar Contato\n4-Listar Contatos\n5-Sair\n");
        scanf("%d", optmenu);
        optsmenu(optmenu);
    }
}

void addlista(contato *novocontato){
    contato *current=novocontato;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next->next=NULL;
}

contato *initagenda(void *buffer){
    contato *head;
    head=buffer;
    head->id=0;
    head->numero=0;
    return head;

}

void optsmenu(int *opt){
    switch(*opt){
        case 1: addcontato();
        break;
        case 2: remcontato();
        break;
        case 3: findcontato();
        break;
        case 4: listcontato();
        break;
        case 5: exit(1);
        default: printf("\nOpção não encontrada\n");

    }
}

void addcontato(){
    printf("\naddcontato\n");
    printf("%lu", sizeof(int));   
}

void remcontato(){
    printf("\nremcontato\n");
}

void findcontato(){
    printf("\nfindcontato\n");
}

void listcontato(){
    printf("\nlistcontato\n");
}