#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POINTER_SIZE sizeof(int*)
#define INT_SIZE sizeof(int)
#define NAME_SIZE sizeof(char)*30
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
void selectmenu(int *control, contato *head,void *buffer);
void printlist(contato *head);
void addtolistend(contato *head, void *buffer);

contato *inithead();


int main(){
    //printf("%lu\n", NAME_SIZE);
    contato *head;
    void *buffer,*temp;
    int *control;

    buffer=malloc(NODE_SIZE*4);
    head=malloc(NODE_SIZE);
    
    control=buffer;
    printf("size of list node: %lu\n", NODE_SIZE);
    //printf("%p\n", buffer);
    buffer+=INT_SIZE;
    //printf("%p\n", buffer);
    
    head=buffer;
    head->num=0;
    strcpy(head->name,"head");
    head->next=NULL;
    buffer+=NODE_SIZE;
    //head=buffer;
    //buffer+=NODE_SIZE;
    //printf("%lu\n", sizeof(int));
    //printf("%p\n", buffer);
    
    
    while(*control!=5){
        printf("\n1-Adicionar Contato\n2-Remover Contato\n3-Buscar Contato\n4-Listar Contatos\n5-Sair\n\nSelecione uma opção:");
        scanf("%d", control);
        getchar();
        selectmenu(control,head,buffer);
    }

    printlist(head);
}

void printlist(contato *head){
    contato *temp;
    temp=malloc(NODE_SIZE);
    temp=head;
    while(temp!=NULL){
        printf("%s\n", temp->name);
        printf("%d\n", temp->num);
        temp=temp->next;
    }
}

void addtolistend(contato *head, void *buffer){
    contato *newcontato,*temp;
    char *stemp;

    stemp=malloc(NAME_SIZE);
    temp=malloc(NODE_SIZE);
    newcontato=malloc(NODE_SIZE);

    newcontato=buffer;
    printf("type name:\n");
    fgets(stemp,30,stdin);
    strcpy(newcontato->name,stemp);
    newcontato->name[strlen(newcontato->name)-1]='\0';
    
    printf("type num:\n");
    scanf("%d", &newcontato->num);
    getchar();
    buffer+=NODE_SIZE;
    newcontato->next=NULL;
    
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newcontato;;
}

void selectmenu(int *control, contato *head,void *buffer){
    switch(*control){
        case 1: addtolistend(head,buffer);
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
    //printf("\naddcontato\n");
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