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
void addlista(contato *novocontato, contato *head);
contato *initagenda();

int main(){
    void *buffer,*bufferIN;
    int *optmenu,*buffersize;
    contato *head;

    buffer=malloc(sizeof(int));
    if(buffer==NULL)exit(1);
    bufferIN=buffer;
    buffersize=buffer;
    *buffersize=4;
    buffer+=4;
    buffer=realloc(buffer,2*sizeof(int));
    optmenu=buffer;
    buffer+=4;
    
    head=initagenda(buffer);
    while(*optmenu!=5){
        printf("\n1-Adicionar Contato\n2-Remover Contato\n3-Buscar Contato\n4-Listar Contatos\n5-Sair\n");
        scanf("%d", optmenu);
        optsmenu(optmenu);
    }
}

void addlista(contato *novocontato, contato *head){
    contato *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=novocontato;
    novocontato->next=NULL;
}

contato *initagenda(void *buffer){
    contato *head;
    head=buffer;
    head->id=0;
    head->numero=0;
    buffer+=sizeof(contato);
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