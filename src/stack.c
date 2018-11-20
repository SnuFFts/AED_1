#include "structs.h"
#include <stdio.h>

extern void *buffer;
extern controle *pointerctrl;

int isempty(Stack *s){
    if(s->top)return 1;
    else return 0;
}

void pop(Stack *s){
    if(!isempty(s))s->top=s->top->next;
}

void push(Stack *s, node *pushnode ){
    pointerctrl->temp=pushnode;
    pointerctrl->temp->next=s->top;
    s->top=pointerctrl->temp;
}

void clear(Stack *s){
    while(!isempty(s))pop(s);
}

