#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato1{
    char nome[30];
    int numero;
    struct contato1 *next;
}contato;

void addcontato();
void remcontato();
void findcontato();
void listcontato();
void optsmenu(int *opt);
void addlista(contato *novocontato, contato *head);
contato *initagenda();
contato *novo_contato(void *buffer);
void printagenda(contato *head);

int main(){
    void *buffer;
    buffer=malloc(1000);
    if(buffer==NULL)exit(1);
    
    void *temp;
    int *optmenu;
    contato *head,*novocontato;
    
    novocontato=malloc(sizeof(contato));
    head=malloc(sizeof(contato));
    //head=buffer;
    head->next=NULL;
    head->numero=999;
    strcpy(head->nome,"head");
    printf("%s\n", head->nome);
    //optmenu=buffer;
    //head=initagenda(buffer);

    //buffer+=sizeof(contato);
    //novocontato=buffer;
    /*while(*optmenu!=5){
        printf("\n1-Adicionar Contato\n2-Remover Contato\n3-Buscar Contato\n4-Listar Contatos\n5-Sair\n");
        scanf("%d", optmenu);
        getchar();
        optsmenu(optmenu);
        printf("%p\n", buffer);
    }*/

    novocontato=novo_contato(buffer);
    addlista(novocontato,head);
    printagenda(head);
    
    //free(buffer);
    //free(head);
    //free(temp);
    //free(optmenu);

    printf("fim\n");
}

contato *novo_contato(void *buffer){
    
    contato *novocontato;
    novocontato=malloc(sizeof(contato));
    novocontato->next=NULL;
    
    printf("Novo nome:\n");
    //fgets(novocontato->nome,30,stdin);
    strcpy(novocontato->nome,"teste");
    printf("Novo número:\n");
    scanf("%d", &novocontato->numero);

    return novocontato;

}

void printagenda(contato *head){
    contato *iterator;
    iterator=malloc(sizeof(contato));
    iterator=head;
    
    while(iterator->next!=NULL){
        printf("%s\n", iterator->nome);
        printf("%d\n", iterator->numero);
        iterator=iterator->next;
    }
    //free(iterator);
}

void addlista(contato *novocontato, contato *head){
    contato *current;
    current=malloc(sizeof(contato));
    current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=novocontato;
    novocontato->next=NULL;
    free(current);
}

contato *initagenda(void *buffer){
    contato *head;
    head=malloc(sizeof(contato));
    head=buffer;
    head->numero=99;
    strcpy(head->nome,"head");
    printf("%s\n", head->nome);
    //buffer+=sizeof(contato);
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
        case 5: break;
        default: printf("\nOpção não encontrada\n");

    }
}

void addcontato(){
    printf("\naddcontato\n");  
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