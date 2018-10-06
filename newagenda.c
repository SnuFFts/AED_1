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

int main(){
    contato *head;
    void *buffer,*temp;
    int *control;
    printf("size of list node: %lu\n", NODE_SIZE);
    buffer=malloc(NODE_SIZE*4);
    head=malloc(NODE_SIZE);
    
    control=buffer;
    buffer+=INT_SIZE;
    
    head=buffer;
    head->num=0;
    strcpy(head->name,"head");
    head->next=NULL;
    buffer+=NODE_SIZE;
}