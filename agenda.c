#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_SIZE sizeof(int)
#define NODE_SIZE sizeof(contato)
#define CONTROL_SIZE sizeof(controle)
#define CONTROL_BYTES NODE_SIZE+7*4+1

void addcontato();
void remcontato();
void findcontato();
void inithead();
void printlist();
void selectmenu(int control);
void loadtest();
void ordermenu();
void algorithmsmenu();
void bubblesort();
void insertionsort();
void swap(contato *c1, contato *c2);
void copynodes(contato *copy1, contato *copy2);

controle *pointerctrl;
void *buffer;

int main(){
    buffer=malloc(CONTROL_SIZE+NODE_SIZE);
    pointerctrl=malloc(CONTROL_SIZE);
    pointerctrl=buffer;
    pointerctrl->bufferin=buffer;
    buffer+=CONTROL_SIZE;
    inithead();
    buffer+=NODE_SIZE;
    pointerctrl->numcontatos=0;
    pointerctrl->buffersize=CONTROL_BYTES+NODE_SIZE;
    loadtest();
    while(pointerctrl->control!=6){
        printf("\n-------------------------------------\n");
        printf("        1-Adicionar Contato\n");
        printf("        2-Remover Contato\n");
        printf("        3-Buscar Contato\n");
        printf("        4-Listar Contatos\n");
        printf("        5-Ordenar Contatos\n");
        printf("        6-Sair\n");
        printf("\n        Buffer size: %d\n",pointerctrl->buffersize);
        printf("-------------------------------------\n");
        printf("Selecione uma opção: ");
        scanf("%d", &pointerctrl->control);
        getchar();
        printf("\n");
        selectmenu(pointerctrl->control);
    }
    buffer=pointerctrl->bufferin;
    free(buffer);
}

void reallocbuffer(){
    buffer=pointerctrl->bufferin;
    buffer=realloc(buffer,CONTROL_SIZE+NODE_SIZE*(pointerctrl->numcontatos+1));
    pointerctrl=buffer;
    pointerctrl->bufferin=buffer;
    buffer+=CONTROL_SIZE;
    pointerctrl->head=buffer;
    pointerctrl->temp=pointerctrl->head;
    while(pointerctrl->temp!=NULL){
        pointerctrl->temp=buffer;
        pointerctrl->temp=pointerctrl->temp->next;
        buffer+=NODE_SIZE;
    }
    //free(pointerctrl->temp);
}

void selectmenu(int control){
    switch(control){
        case 1: 
            addcontato();
            break;
        case 2: 
            remcontato();
            break;
        case 3: 
            findcontato();
            break;
        case 4: 
            printlist();
            break;
        case 5: 
            algorithmsmenu();
            break;
        case 6: 
            break;
        default: 
            printf("\nOpção não encontrada\n");
    }
}

void algorithmsmenu(){
    printf("\n1-Insertion Sort\n2-Bubble Sort\n3-Quick Sort\n");
    scanf("%d", &pointerctrl->control);
    getchar();
    switch(pointerctrl->control){
        case 1: 
            insertionsort();
            break;
        case 2: 
            bubblesort();
            break;
        case 3:
            break;
        default: 
            printf("\nOpção não encontrada\n");
    }
}

void copynodes(contato *copy1, contato *copy2){
    for(pointerctrl->indexit=0;pointerctrl->indexit<30;pointerctrl->indexit++){
        copy2->name[pointerctrl->indexit]=copy1->name[pointerctrl->indexit];
    }
    copy2->num=copy1->num;
}

void swap(contato *c1, contato *c2){
    pointerctrl->swaptemp=malloc(NODE_SIZE);
    copynodes(c1,pointerctrl->swaptemp);
    copynodes(c2,c1);
    copynodes(pointerctrl->swaptemp,c2);
}

void bubblesort(){
    pointerctrl->it=pointerctrl->head->next;
    for(pointerctrl->i=0;pointerctrl->i<pointerctrl->numcontatos-1;pointerctrl->i++){
        for(pointerctrl->j=0;pointerctrl->j<pointerctrl->numcontatos-pointerctrl->i-1;pointerctrl->j++){
            if(pointerctrl->it->num > pointerctrl->it->next->num){
                swap(pointerctrl->it,pointerctrl->it->next);
            }
            pointerctrl->it=pointerctrl->it->next;
        }
        pointerctrl->it=pointerctrl->head->next;
    }
}

void insertionsort(){
    pointerctrl->it=pointerctrl->head->next;
    for(pointerctrl->i=1;pointerctrl->i<pointerctrl->numcontatos;pointerctrl->i++){
        pointerctrl->j=pointerctrl->i;
        while(pointerctrl->j>0 && pointerctrl->it->prev->num>pointerctrl->it->num){
            swap(pointerctrl->it->prev,pointerctrl->it);
            pointerctrl->it=pointerctrl->it->prev;
            pointerctrl->j-=1;
        }
    }
}

void addcontato(){
    pointerctrl->numcontatos+=1;
    reallocbuffer();
    pointerctrl->newcontato=buffer;
    pointerctrl->temp=pointerctrl->head;
    
    do{
        printf("Nome: ");
        fgets(pointerctrl->newcontato->name,30,stdin);
        pointerctrl->newcontato->name[strlen(pointerctrl->newcontato->name)-1]='\0';
        if(strcmp(pointerctrl->newcontato->name,"\0")==0){
            printf("Nome inválido, digite novamente\n");
        }
    }while(strcmp(pointerctrl->newcontato->name,"\0")==0);
    
    printf("Número: ");
    scanf("%d", &pointerctrl->newcontato->num);
    getchar();

    while(pointerctrl->temp->next!=NULL){
        pointerctrl->temp=pointerctrl->temp->next;
    }
    pointerctrl->temp->next=pointerctrl->newcontato;
    pointerctrl->newcontato->prev=pointerctrl->temp;
    pointerctrl->newcontato->next=NULL;
    pointerctrl->buffersize+=NODE_SIZE;
}

void remcontato(){
    pointerctrl->temp=malloc(NODE_SIZE);
    pointerctrl->it=pointerctrl->head;
    pointerctrl->it=pointerctrl->it->next;
    printf("Nome: ");
    fgets(pointerctrl->temp->name,30,stdin);
    pointerctrl->temp->name[strlen(pointerctrl->temp->name)-1]='\0';
    while(pointerctrl->it!=NULL){
        if(strcmp(pointerctrl->temp->name,pointerctrl->it->name)==0){
            pointerctrl->i=1;
            pointerctrl->numcontatos-=1;
            pointerctrl->it->prev->next=pointerctrl->it->next;
            if(pointerctrl->it->next!=NULL)pointerctrl->it->next->prev=pointerctrl->it->prev;
            break;
        }
        pointerctrl->it=pointerctrl->it->next;
    }
    if(pointerctrl->i!=1)printf("Contato não encontrado\n");
    reallocbuffer();
    pointerctrl->buffersize-=NODE_SIZE;
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
    pointerctrl->head->prev=NULL;
}

void printlist(){
    pointerctrl->temp=pointerctrl->head->next;
    //pointerctrl->temp=pointerctrl->temp->next;
    while(pointerctrl->temp!=NULL){
        printf("Nome: %s\n", pointerctrl->temp->name);
        printf("Número: %d\n\n", pointerctrl->temp->num);
        pointerctrl->temp=pointerctrl->temp->next;
    }
    /*pointerctrl->temp=pointerctrl->temp->prev;
    while(pointerctrl->temp!=NULL){
        printf("Nome: %s\n", pointerctrl->temp->name);
        printf("Número: %d\n\n", pointerctrl->temp->num);
        pointerctrl->temp=pointerctrl->temp->prev;
    }*/
    if(pointerctrl->numcontatos==0)printf("Agenda vazia\n");
    else printf("Total de contatos: %d\n", pointerctrl->numcontatos);
}

void loadtest(){
    FILE *fp;
    int testnum,i;
    char testname[30];
    fp=fopen("test.txt","r");
    pointerctrl->numcontatos=20;
    reallocbuffer();
    for(i=0;i<20;i++){
        fscanf(fp,"%s",testname);
        fscanf(fp,"%d",&testnum);

        pointerctrl->newcontato=buffer;
        pointerctrl->temp=pointerctrl->head;
        strcpy(pointerctrl->newcontato->name,testname);
        pointerctrl->newcontato->name[strlen(pointerctrl->newcontato->name)-1]='\0';
        pointerctrl->newcontato->num=testnum;
        
        while(pointerctrl->temp->next!=NULL){
            pointerctrl->temp=pointerctrl->temp->next;
        }
        pointerctrl->temp->next=pointerctrl->newcontato;
        pointerctrl->newcontato->prev=pointerctrl->temp;
        pointerctrl->newcontato->next=NULL;
        buffer+=NODE_SIZE;
    }
    pointerctrl->buffersize+=NODE_SIZE*20;
}
