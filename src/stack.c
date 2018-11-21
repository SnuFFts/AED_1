#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

extern void *buffer;
extern controle *pointerctrl;

int isempty(Stack *s){
    if(s->top)return 0;
    else return 1;
}

void pop(Stack *s){
    if(!isempty(s))s->top=s->top->next;
}

void push(Stack *s, node *pushnode ){
    if(isempty(s))s->top=pushnode;
    else{
        pointerctrl->stacktemp=(node*)malloc(sizeof(node));
        pointerctrl->stacktemp=pushnode;
        pointerctrl->stacktemp->next=s->top;
        s->top=pointerctrl->stacktemp;
    }
}

void clear(Stack *s){
    while(!isempty(s))pop(s);
}

void countstack(Stack *s){
    int a=0;
    while(!isempty(s)){
        printf("Nome: %s\n",s->top->name);
        printf("Número: %d\n",s->top->num);
        s->top=s->top->next;
        a++;
    }
    printf("%d",a);
}

