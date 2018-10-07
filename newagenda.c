#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define POINTER_SIZE sizeof(int*)
#define INT_SIZE sizeof(int)
#define NODE_SIZE sizeof(contato)

typedef struct __attribute__((__packed__)) contato{
    char name[30];
    int num;
    struct contato *next;
}contato;


void addcontato();
void remcontato();
void findcontato();
void listcontato();
void inithead();
void printlist();
void selectmenu(int *control);

void *buffer;
contato *head;

int main(){
    void *temp;
    int *control;
    buffer=malloc(NODE_SIZE*10);
    control=buffer;
    buffer+=INT_SIZE;
    inithead();
    buffer+=NODE_SIZE;

    while(*control!=5){
        printf("\n1-Adicionar Contato\n2-Remover Contato\n3-Buscar Contato\n4-Listar Contatos\n5-Sair\n\nSelecione uma opção: ");
        scanf("%d", control);
        getchar();
        selectmenu(control);
    }

    printlist();

}

void selectmenu(int *control){
    switch(*control){
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
    contato *temp;
    contato *newcontato;
    temp=malloc(NODE_SIZE);
    newcontato=malloc(NODE_SIZE);
    newcontato=buffer;
    temp=head;

    printf("Nome: ");
    fgets(newcontato->name,30,stdin);
    newcontato->name[strlen(newcontato->name)-1]='\0';
    printf("Número: ");
    scanf("%d", &newcontato->num);
    getchar();
    newcontato->next=NULL;
    buffer+=NODE_SIZE;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newcontato;
}

void remcontato(){
    printf("\nremcontato\n");
}

void findcontato(){
    printf("\nfindcontato\n");
}

void listcontato(){
    //printf("\nlistcontato\n");
    printlist();
}

void inithead(){
    head=buffer;
    head=malloc(NODE_SIZE);
    strcpy(head->name,"head");
    head->num=0;
    head->next=NULL;
}

void printlist(){
    contato *temp;
    temp=malloc(NODE_SIZE);
    temp=head;
    temp=temp->next;
    while(temp!=NULL){
        printf("%s\n", temp->name);
        printf("%d\n", temp->num);
        temp=temp->next;
    }
}
