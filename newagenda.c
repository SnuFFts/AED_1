#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define POINTER_SIZE sizeof(int*)
#define INT_SIZE sizeof(int)
#define NODE_SIZE sizeof(contato)
#define CONTROL_SIZE sizeof(controle)

typedef struct __attribute__((__packed__)) contato{
    char name[30];
    int num;
    struct contato *next;
}contato;

typedef struct __attribute__((__packed__)) controle{
    contato *temp;
    contato *it;
    contato *it2;
}controle;

void addcontato();
void remcontato();
void findcontato();
void inithead();
void printlist();
void selectmenu(int *control);

void *buffer;
void *iBuffer;
contato *head;
int *numcontatos;

int main(){
    void *temp;
    int *controlmenu;
    buffer=malloc(NODE_SIZE*100);
    iBuffer = buffer;
    controlmenu=malloc(INT_SIZE);
    numcontatos=malloc(INT_SIZE);

    controlmenu=buffer;
    temp=buffer;
    buffer+=INT_SIZE;
    numcontatos=buffer;
    *numcontatos=0;
    buffer+=INT_SIZE;
    inithead();
    buffer+=NODE_SIZE;

    while(*controlmenu!=5){
        printf("\n1-Adicionar Contato\n2-Remover Contato\n3-Buscar Contato\n4-Listar Contatos\n5-Sair\n\nSelecione uma opção: ");
        scanf("%d", controlmenu);
        getchar();
        selectmenu(controlmenu);
    }

    //free(buffer);
    //free(head);
    free(iBuffer);
}

void selectmenu(int *controlmenu){
    switch(*controlmenu){
        case 1: addcontato();
            break;
        case 2: remcontato();
            break;
        case 3: findcontato();
            break;
        case 4: printlist();
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

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newcontato;
    
    buffer+=NODE_SIZE;
    *numcontatos+=1;
}

void remcontato(){
    contato *temp,*it,*it2;
    temp=malloc(NODE_SIZE);
    it=malloc(NODE_SIZE);
    it2=malloc(NODE_SIZE);
    it=head;
    it=it->next;
    printf("Nome: ");
    fgets(temp->name,30,stdin);
    temp->name[strlen(temp->name)-1]='\0';

    while(it!=NULL){
        if(strcmp(temp->name,it->name)==0){
            break;
        }
        it2=it;
        it=it->next;
    }
    it=it->next;
    it2->next=it;
}

void findcontato(){
    contato *temp,*it;
    temp=malloc(NODE_SIZE);
    it=malloc(NODE_SIZE);
    it=head;
    it=it->next;
    printf("Nome: ");
    fgets(temp->name,30,stdin);
    temp->name[strlen(temp->name)-1]='\0';

    while(it!=NULL){
        if(strcmp(temp->name,it->name)==0){
            printf("%s\n", it->name);
            printf("%d\n", it->num);
        }
        it=it->next;
    }

}

void inithead(){
    head=malloc(NODE_SIZE);
    head=buffer;
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
    printf("Total de contatos: %d\n", *numcontatos);
}
