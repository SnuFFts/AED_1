typedef struct __attribute__((__packed__)) node{
    char name[30];
    int num;
    struct node *next;
    struct node *prev;
}node;


typedef struct __attribute__((__packed__)) Stack{
    node *top;
}Stack;

typedef struct __attribute__((__packed__)) controle{
    void *bufferin;
    int buffersize;
    int numnodes;
    int control;
    int i;
    int j;
    int nodeflag;
    int indexit;
    node *head;
    node *newnode;
    node *swaptemp;
    node *stacktemp;
    node *temp;
    node *it;
    Stack *stack;
}controle;