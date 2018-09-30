#include <stdio.h>
#include <stdlib.h>

typedef struct contato{
    char nome[30];
    int numero;
    struct contato *next;
}contato;

void addcontato();
void remcontato();
void findcontato();
void listcontato();
void optsmenu(int *opt);
void addlista(contato *novocontato, contato *head);
contato *initagenda();

int main(){
    void *buffer,*temp;
    int *optmenu;
    contato *head;

    buffer=malloc(sizeof(int));
    if(buffer==NULL)exit(1);
    //printf("%p\n", buffer);
    optmenu=buffer;
    //temp=realloc(buffer,2*sizeof(int));
    //buffer=temp;
    head=initagenda(buffer);
    while(*optmenu!=5){
        printf("\n1-Adicionar Contato\n2-Remover Contato\n3-Buscar Contato\n4-Listar Contatos\n5-Sair\n");
        scanf("%d", optmenu);
        getchar();
        optsmenu(optmenu);
        printf("%p\n", buffer);
    }
    free(buffer);
    free(head);
    free(temp);
    free(optmenu);

    printf("teste\n");
}

void addlista(contato *novocontato, contato *head){
    contato *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=novocontato;
    novocontato->next=NULL;
    free(current);
}

contato *initagenda(void *buffer){
    contato *head;
    head=buffer;
    head->numero=0;
    buffer+=sizeof(contato);
    return head;

}

void optsmenu(int *opt){
    switch(*opt){
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
    printf("\naddcontato\n");
    //printf("%lu", sizeof(int));   
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