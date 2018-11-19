typedef struct __attribute__((__packed__)) contato{
    char name[30];
    int num;
    struct contato *next;
    struct contato *prev;
}contato;



typedef struct __attribute__((__packed__)) controle{
    void *bufferin;
    int buffersize;
    int numcontatos;
    int control;
    int i;
    int j;
    int k;
    int indexit;
    contato *head;
    contato *newcontato;
    contato *swaptemp;
    contato *temp;
    contato *it;
}controle;