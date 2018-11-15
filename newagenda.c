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
    struct contato *prev;
}contato;



typedef struct __attribute__((__packed__)) controle{
    void *bufferin;
    int numcontatos;
    int control;
    int i;
    int j;
    int indexit;
    contato *head;
    contato *newcontato;
    contato *swaptemp;
    contato *temp;
    contato *temp2;
    contato *temp3;
    contato *it;
}controle;

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
void copynodes(contato *c1, contato *c2);

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
    loadtest();
    while(pointerctrl->control!=6){
        printf("-------------------------------------\n");
        printf("        1-Adicionar Contato\n");
        printf("        2-Remover Contato\n");
        printf("        3-Buscar Contato\n");
        printf("        4-Listar Contatos\n");
        printf("        5-Ordenar Contatos\n");
        printf("        6-Sair\n");
        printf("-------------------------------------\n");
        printf("Selecione uma opção: ");
        scanf("%d", &pointerctrl->control);
        getchar();
        selectmenu(pointerctrl->control);
    }
    buffer=pointerctrl->bufferin;
    free(buffer);
    free(pointerctrl);
}

void reallocbuffer(){
    buffer=pointerctrl->bufferin;
    buffer=realloc(buffer,CONTROL_SIZE+NODE_SIZE*(pointerctrl->numcontatos));
    pointerctrl=buffer;
    pointerctrl->bufferin=buffer;
    buffer+=CONTROL_SIZE;
    pointerctrl->head=buffer;
    pointerctrl->temp=pointerctrl->head;
    while(pointerctrl->temp!=NULL){
        buffer+=NODE_SIZE;
        pointerctrl->temp=buffer;
        pointerctrl->temp=pointerctrl->temp->next;
    }
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
            break;
        case 2: bubblesort();
            break;
        case 3:
            break;
        default: 
            printf("\nOpção não encontrada\n");
    }
}

void copynodes(contato *c1, contato *c2){
    for(pointerctrl->indexit=0;pointerctrl->indexit<30;pointerctrl->indexit++){
        c2->name[pointerctrl->indexit]=c1->name[pointerctrl->indexit];
    }
    c2->num=c1->num;
}

void swap(contato *c1, contato *c2){
    pointerctrl->swaptemp=malloc(NODE_SIZE);
    copynodes(c1,pointerctrl->swaptemp);
    copynodes(c2,c1);
    copynodes(pointerctrl->swaptemp,c2);
}

void bubblesort(){
    pointerctrl->temp2=malloc(NODE_SIZE);
    pointerctrl->temp3=malloc(NODE_SIZE);
    pointerctrl->it=pointerctrl->head->next;
    for(pointerctrl->i=0 ; pointerctrl->i < pointerctrl->numcontatos-1 ; pointerctrl->i++){
        for(pointerctrl->j=0 ; pointerctrl->j < pointerctrl->numcontatos-pointerctrl->i-1 ; pointerctrl->j++){
            pointerctrl->it=pointerctrl->it->next;
            if(pointerctrl->it->num > pointerctrl->it->next->num){
                copynodes(pointerctrl->it,pointerctrl->temp2);
                copynodes(pointerctrl->it->next,pointerctrl->temp3);
                swap(pointerctrl->temp2,pointerctrl->temp3);
            }
        
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

    pointerctrl->newcontato->next=NULL;
    while(pointerctrl->temp->next!=NULL){
        pointerctrl->temp=pointerctrl->temp->next;
    }
    pointerctrl->temp->next=pointerctrl->newcontato;
    pointerctrl->newcontato->prev=pointerctrl->temp;
}

void remcontato(){
    reallocbuffer();
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
    pointerctrl->numcontatos=20;
    reallocbuffer();
    for(i=0;i<20;i++){
        fscanf(fp,"%s",testname);
        fscanf(fp,"%d",&testnum);
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
        pointerctrl->newcontato->prev=pointerctrl->temp;
        buffer+=NODE_SIZE;
    }
}