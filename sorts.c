#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE sizeof(int)

int *test1,*test2,*test3,*testalmost,*testreversed,*finaltest;
int i,j;

void mallocall();
void loadtest();
void printtest();
void insertionsort(int *array, int size);
void bubblesort(int *array, int size);
void printresult(int *array, int size);

int main(){
    mallocall();
    loadtest();
    printf("Test arrays:\n");
    printtest();
    printf("\nInsertion sort:\n");
    insertionsort(test1,1);
    insertionsort(test2,2);
    insertionsort(test3,3);
    insertionsort(testalmost,10);
    insertionsort(testreversed,10);
    insertionsort(finaltest,10);
    mallocall();
    loadtest();
    printf("\nBubble sort:\n");
    bubblesort(test1,1);
    bubblesort(test2,2);
    bubblesort(test3,3);
    bubblesort(testalmost,10);
    bubblesort(testreversed,10);
    bubblesort(finaltest,10);

    
}

void bubblesort(int *array, int size){
    int temp;
    i=0;j=0;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;

            }
        }
    }
    printresult(array,size);
}

void insertionsort(int *array, int size){
    int temp;
    i=0;j=0;
    for(i=1;i<size;i++){
        j=i;
        while(j>0 && array[j-1]>array[j]){
            temp=array[j];
            array[j]=array[j-1];
            array[j-1]=temp;
            j-=1;
        }
    }
    printresult(array,size);
}

void loadtest(){
    char *bp;
    FILE *fp;
    fp=fopen("sorttest.txt","r");
    fscanf(fp,"%d",test1);
    //fscanf(fp,"%c",bp);
    for(i=0;i<2;i++){
        fscanf(fp,"%d",&test2[i]);
    }
    //fscanf(fp,"%c",bp);
    for(i=0;i<3;i++){
        fscanf(fp,"%d",&test3[i]);
    }
    //fscanf(fp,"%c",bp);
    for(i=0;i<10;i++){
        fscanf(fp,"%d",&testalmost[i]);
    }
    //fscanf(fp,"%c",bp);
    for(i=0;i<10;i++){
        fscanf(fp,"%d",&testreversed[i]);
    }
    //fscanf(fp,"%c",bp);
    for(i=0;i<10;i++){
        fscanf(fp,"%d",&finaltest[i]);
    }
    fclose(fp);

}

void printtest(){
    printf("%d\n",*test1);
    for(i=0;i<2;i++){
        printf("%d ", test2[i]);
    }
    printf("\n");
    for(i=0;i<3;i++){
        printf("%d ", test3[i]);
    }
    printf("\n");
    for(i=0;i<10;i++){
        printf("%d ", testalmost[i]);
    }
    printf("\n");
    for(i=0;i<10;i++){
        printf("%d ", testreversed[i]);
    }
    printf("\n");
    for(i=0;i<10;i++){
        printf("%d ", finaltest[i]);
    }
    printf("\n");   
}

void printresult(int *array,int size){
    for(i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void mallocall(){
    test1=malloc(INT_SIZE);
    test2=malloc(INT_SIZE*2);
    test3=malloc(INT_SIZE*3);
    testalmost=malloc(INT_SIZE*10);
    testreversed=malloc(INT_SIZE*10);
    finaltest=malloc(INT_SIZE*10);
}