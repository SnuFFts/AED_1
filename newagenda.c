#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_SIZE sizeof(int)
#define NODE_SIZE sizeof(contato)
#define CONTROL_SIZE sizeof(controle)

typedef struct __attribute__((__packed__)) contato{
    char name[30];
    int num;
    struct contato *next;
}contato;

typedef struct __attribute__((__packed__)) controle{
    void *bufferin;
    int numcontatos;
    int control;
    int i;
    int j;
    int inttemp;
    contato *head;
    contato *newcontato;
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
void loadtest();
void ordermenu();
void algorithmsmenu();

void *buffer;
controle *pointerctrl;

int main(){
    buffer=malloc(CONTROL_SIZE+NODE_SIZE);
    pointerctrl=malloc(CONTROL_SIZE);
    pointerctrl=buffer;
    pointerctrl->bufferin=buffer;
    buffer+=CONTROL_SIZE;
    pointerctrl->head=buffer;
    inithead();
    buffer+=NODE_SIZE;
    pointerctrl->numcontatos=0;
    //loadtest();

    while(pointerctrl->control!=5){
        printf("\n1-Adicionar Contato\n2-Remover Contato\n3-Buscar Contato\n4-Listar Contatos\n5-Ordenar Contatos\n6-Sair\n\nSelecione uma opção: ");
        scanf("%d", &pointerctrl->control);
        getchar();
        selectmenu(&pointerctrl->control);
    }
}

void reallocbuffer(){
    buffer=pointerctrl->bufferin;
    buffer=realloc(buffer,CONTROL_SIZE+(NODE_SIZE*(pointerctrl->numcontatos)));
    pointerctrl=buffer;
    pointerctrl->bufferin=buffer;
    buffer+=CONTROL_SIZE;
    pointerctrl->head=buffer;
    buffer+=NODE_SIZE;
    pointerctrl->temp=malloc(NODE_SIZE);
    pointerctrl->temp=pointerctrl->head;
    while(pointerctrl->temp!=NULL){
        pointerctrl->temp=pointerctrl->temp->next;
        buffer+=NODE_SIZE;
    }
    
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
        case 5: ordermenu();
            break;
        case 6: break;
        default: printf("\nOpção não encontrada\n");

    }
}

void ordermenu(){
    printf("Ordernar por:\n1-Nome\n2-Número");
    scanf("%d",&pointerctrl->control);
    getchar();
    switch(pointerctrl->control){
        case 1:
            break;
        case 2:
            algorithmsmenu();
        default: printf("\nOpção não encontrada\n");
    }
}

void algorithmsmenu(){
    printf("1-Insertion Sort\n2-Bubble Sort\n3-Quick Sort");
    scanf("%d", &pointerctrl->control);
    getchar();
    switch(pointerctrl->control){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default: printf("\nOpção não encontrada\n");
    }
}

void addcontato(){
    pointerctrl->numcontatos+=1;
    reallocbuffer();
    pointerctrl->temp=malloc(NODE_SIZE);
    pointerctrl->newcontato=buffer;
    pointerctrl->temp=pointerctrl->head;

    printf("Nome: ");
    fgets(pointerctrl->newcontato->name,30,stdin);
    pointerctrl->newcontato->name[strlen(pointerctrl->newcontato->name)-1]='\0';
    printf("Número: ");
    scanf("%d", &pointerctrl->newcontato->num);
    getchar();
    pointerctrl->newcontato->next=NULL;

    while(pointerctrl->temp->next!=NULL){
        pointerctrl->temp=pointerctrl->temp->next;
    }
    pointerctrl->temp->next=pointerctrl->newcontato;
}

void remcontato(){
    pointerctrl->numcontatos-=1;
    reallocbuffer();
    pointerctrl->temp=malloc(NODE_SIZE);
    pointerctrl->it=pointerctrl->head;
    pointerctrl->it=pointerctrl->it->next;
    printf("Nome: ");
    fgets(pointerctrl->temp->name,30,stdin);
    pointerctrl->temp->name[strlen(pointerctrl->temp->name)-1]='\0';

    while(pointerctrl->it!=NULL){
        if(strcmp(pointerctrl->temp->name,pointerctrl->it->name)==0){
            break;
        }
        pointerctrl->it2=pointerctrl->it;
        pointerctrl->it=pointerctrl->it->next;
    }
    pointerctrl->it=pointerctrl->it->next;
    pointerctrl->it2->next=pointerctrl->it;
    pointerctrl->numcontatos-=1;
}

void findcontato(){
    pointerctrl->temp=malloc(NODE_SIZE);
    pointerctrl->it=pointerctrl->head;
    pointerctrl->it=pointerctrl->it->next;
    printf("Nome: ");
    fgets(pointerctrl->temp->name,30,stdin);
    pointerctrl->temp->name[strlen(pointerctrl->temp->name)-1]='\0';

    while(pointerctrl->it!=NULL){
        if(strcmp(pointerctrl->temp->name,pointerctrl->it->name)==0){
            printf("%s\n", pointerctrl->it->name);
            printf("%d\n", pointerctrl->it->num);
        }
        pointerctrl->it=pointerctrl->it->next;
    }

}

void inithead(){
    pointerctrl->head=buffer;
    strcpy(pointerctrl->head->name,"head");
    pointerctrl->head->num=0;
    pointerctrl->head->next=NULL;
}

void printlist(){
    pointerctrl->temp=malloc(NODE_SIZE);
    pointerctrl->temp=pointerctrl->head;
    pointerctrl->temp=pointerctrl->temp->next;
    
    while(pointerctrl->temp!=NULL){
        printf("Nome: %s\n", pointerctrl->temp->name);
        printf("Número: %d\n\n", pointerctrl->temp->num);
        pointerctrl->temp=pointerctrl->temp->next;
    }
    printf("Total de contatos: %d\n", pointerctrl->numcontatos);
}

void loadtest(){
    FILE *fp;
    int testnum,i;
    char testname[30];
    fp=fopen("test.txt","r");
    for(i=0;i<20;i++){
        fscanf(fp,"%s",testname);
        //getchar();
        fscanf(fp,"%d",&testnum);
        //getchar();

        pointerctrl->numcontatos+=1;
        pointerctrl->temp=malloc(NODE_SIZE);
        pointerctrl->newcontato=buffer;
        pointerctrl->temp=pointerctrl->head;

        strcpy(pointerctrl->newcontato->name,testname);
        pointerctrl->newcontato->name[strlen(pointerctrl->newcontato->name)-1]='\0';
        pointerctrl->newcontato->num=testnum;
        pointerctrl->newcontato->next=NULL;

        while(pointerctrl->temp->next!=NULL){
            pointerctrl->temp=pointerctrl->temp->next;
        }
        pointerctrl->temp->next=pointerctrl->newcontato;

        buffer+=NODE_SIZE;

    }
}