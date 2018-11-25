#include "structs.h"
#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_SIZE sizeof(int)
#define NODE_SIZE sizeof(node)
#define CONTROL_SIZE sizeof(controle)
#define CONTROL_BYTES NODE_SIZE+7*4+1+sizeof(Stack)

void addnode();
void rmnode();
void findnode();
void inithead();
void printagenda();
void selectmenu(int control);
void loadtest();
void ordermenu();
void algorithmsmenu();
void bubblesort();
void insertionsort();
void swapnodes(node *c1, node *c2);
void copynodes(node *copy1, node *copy2);

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
    pointerctrl->numnodes=0;
    pointerctrl->buffersize=CONTROL_BYTES+NODE_SIZE;
    printf("LOAD TEST ?\nPRESS 5 FOR YES\nDON'T ADD NEW NODE IF TEST IS LOADED\n");
    scanf("%d",&pointerctrl->nodeflag);
    if(pointerctrl->nodeflag==5)loadtest();
    while(pointerctrl->control!=6){
        printf("\n-------------------------------------\n");
        printf("        1-Add contact\n");
        printf("        2-Remove contact\n");
        printf("        3-Find contact\n");
        printf("        4-List all\n");
        printf("        5-Sort\n");
        printf("        6-Exit\n");
        printf("\n        Buffer size: %dB\n",pointerctrl->buffersize);
        printf("-------------------------------------\n");
        printf("Option: ");
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
    buffer=realloc(buffer,CONTROL_SIZE+NODE_SIZE*(pointerctrl->numnodes+1));
    pointerctrl=buffer;
    pointerctrl->stack=malloc(sizeof(Stack));
    pointerctrl->bufferin=buffer;
    buffer+=CONTROL_SIZE;
    pointerctrl->head=buffer;
    pointerctrl->temp=pointerctrl->head;
    while(pointerctrl->temp!=NULL){
        pointerctrl->temp=buffer;
        pointerctrl->temp=pointerctrl->temp->next;
        buffer+=NODE_SIZE;
    }
}

void selectmenu(int control){
    switch(control){
        case 1: 
            addnode();
            break;
        case 2: 
            rmnode();
            break;
        case 3: 
            findnode();
            break;
        case 4: 
            printagenda();
            break;
        case 5: 
            algorithmsmenu();
            break;
        case 6: 
            break;
        default: 
            printf("\nOption not found\n");
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
            printf("\nOption not found\n");
    }
}

void copynodes(node *copy1, node *copy2){
    for(pointerctrl->indexit=0;pointerctrl->indexit<30;pointerctrl->indexit++){
        copy2->name[pointerctrl->indexit]=copy1->name[pointerctrl->indexit];
    }
    copy2->num=copy1->num;
}

void swapnodes(node *c1, node *c2){
    pointerctrl->swaptemp=malloc(NODE_SIZE);
    copynodes(c1,pointerctrl->swaptemp);
    copynodes(c2,c1);
    copynodes(pointerctrl->swaptemp,c2);
}

void bubblesort(){
    pointerctrl->it=pointerctrl->head->next;
    for(pointerctrl->i=0;pointerctrl->i<pointerctrl->numnodes-1;pointerctrl->i++){
        for(pointerctrl->j=0;pointerctrl->j<pointerctrl->numnodes-pointerctrl->i-1;pointerctrl->j++){
            if(pointerctrl->it->num > pointerctrl->it->next->num){
                swapnodes(pointerctrl->it,pointerctrl->it->next);
            }
            pointerctrl->it=pointerctrl->it->next;
        }
        pointerctrl->it=pointerctrl->head->next;
    }
}

void insertionsort(){
    pointerctrl->it=pointerctrl->head->next;
    for(pointerctrl->i=1;pointerctrl->i<pointerctrl->numnodes;pointerctrl->i++){
        pointerctrl->j=pointerctrl->i;
        while(pointerctrl->j>0 && pointerctrl->it->prev->num>pointerctrl->it->num){
            swapnodes(pointerctrl->it->prev,pointerctrl->it);
            pointerctrl->it=pointerctrl->it->prev;
            pointerctrl->j-=1;
        }
    }
}

void addnode(){
    pointerctrl->numnodes+=1;
    reallocbuffer();
    pointerctrl->newnode=buffer;
    pointerctrl->temp=pointerctrl->head;
    
    do{
        pointerctrl->nodeflag=0;
        printf("Name: ");
        fgets(pointerctrl->newnode->name,30,stdin);
        pointerctrl->newnode->name[strlen(pointerctrl->newnode->name)-1]='\0';
        if(strcmp(pointerctrl->newnode->name,"\0")==0){
            printf("Invalid name, try again\n");
            pointerctrl->nodeflag=1;
        }
    }while(pointerctrl->nodeflag==1);
    
    printf("Number: ");
    scanf("%d", &pointerctrl->newnode->num);
    getchar();

    pointerctrl->nodeflag=0;
    while(pointerctrl->temp->next!=NULL){
        pointerctrl->temp=pointerctrl->temp->next;
        if(strcmp(pointerctrl->newnode->name,pointerctrl->temp->name)==0){
            pointerctrl->nodeflag=1;
            printf("Name already exists\n");
        }
        if(pointerctrl->temp->num==pointerctrl->newnode->num){
            pointerctrl->nodeflag=1;
            printf("Number already exists\n");
        }
    }

    pointerctrl->temp=pointerctrl->head;
    if(!pointerctrl->nodeflag){
        while(pointerctrl->temp->next!=NULL){
            pointerctrl->temp=pointerctrl->temp->next;
        }
        pointerctrl->temp->next=pointerctrl->newnode;
        pointerctrl->newnode->prev=pointerctrl->temp;
        pointerctrl->newnode->next=NULL;
        pointerctrl->buffersize+=NODE_SIZE;
    }
}

void rmnode(){
    pointerctrl->temp=malloc(NODE_SIZE);
    pointerctrl->it=pointerctrl->head;
    printf("Name: ");
    fgets(pointerctrl->temp->name,30,stdin);
    pointerctrl->temp->name[strlen(pointerctrl->temp->name)-1]='\0';
    pointerctrl->nodeflag=0;
    if(pointerctrl->numnodes==1){
        pointerctrl->it->next=NULL;
        pointerctrl->nodeflag=1;
        pointerctrl->numnodes-=1;
    }
    else{
        while(pointerctrl->it->next!=NULL){
            pointerctrl->it=pointerctrl->it->next;
            if(strcmp(pointerctrl->temp->name,pointerctrl->it->name)==0){
                pointerctrl->it->prev->next=pointerctrl->it->next;
                if(pointerctrl->it->next!=NULL)pointerctrl->it->next->prev=pointerctrl->it->prev;
                pointerctrl->nodeflag=1;
                pointerctrl->numnodes-=1;
                break;
            }
        }
    }
    if(!pointerctrl->nodeflag)printf("Name not found\n");
    else pointerctrl->buffersize-=NODE_SIZE;
    reallocbuffer();
}

void findnode(){
    pointerctrl->temp=malloc(NODE_SIZE);
    pointerctrl->it=pointerctrl->head;
    pointerctrl->it=pointerctrl->it->next;
    printf("Name: ");
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

void printagenda(){
    pointerctrl->temp=pointerctrl->head;
    if(pointerctrl->temp->next!=NULL){
        clear(pointerctrl->stack);
        while(pointerctrl->temp->next!=NULL)pointerctrl->temp=pointerctrl->temp->next;
        while(pointerctrl->temp->num!=0){
            push(pointerctrl->stack,pointerctrl->temp);
            pointerctrl->temp=pointerctrl->temp->prev;
        }
        while(!isempty(pointerctrl->stack)){
            printf("Name: %s\n",pointerctrl->stack->top->name);
            printf("Number: %d\n",pointerctrl->stack->top->num);
            pop(pointerctrl->stack);
        }
    }
    else printf("Empty\n");
    
}

void loadtest(){
    FILE *fp;
    int testnum,iter;
    char testname[30];
    fp=fopen("test.txt","r");
    pointerctrl->numnodes=20;
    reallocbuffer();
    for(iter=0;iter<20;iter++){
        fscanf(fp,"%s",testname);
        fscanf(fp,"%d",&testnum);
        
        //pointerctrl->numnodes+=1;
        //reallocbuffer();
        pointerctrl->newnode=buffer;
        pointerctrl->temp=pointerctrl->head;
        strcpy(pointerctrl->newnode->name,testname);
        pointerctrl->newnode->name[strlen(pointerctrl->newnode->name)-1]='\0';
        pointerctrl->newnode->num=testnum;
        
        while(pointerctrl->temp->next!=NULL){
            pointerctrl->temp=pointerctrl->temp->next;
        }
        pointerctrl->temp->next=pointerctrl->newnode;
        pointerctrl->newnode->prev=pointerctrl->temp;
        pointerctrl->newnode->next=NULL;
        buffer+=NODE_SIZE;
    }
    fclose(fp);
    pointerctrl->buffersize+=NODE_SIZE*20;
    //reallocbuffer();
}
