#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE sizeof(int)

int *test1,*test2,*test3,*testalmost,*testreversed,*finaltest;
int i,j;

void loadtest();
void printtest();
void insertionsort(int *array, int size);
void printresult(int *array,int size);

int main(){
    test1=malloc(INT_SIZE);
    test2=malloc(INT_SIZE*2);
    test3=malloc(INT_SIZE*3);
    testalmost=malloc(INT_SIZE*10);
    testreversed=malloc(INT_SIZE*10);
    finaltest=malloc(INT_SIZE*10);
    loadtest();
    //printtest();
    insertionsort(test1,1);
    insertionsort(test2,2);
    insertionsort(test3,3);
    insertionsort(testalmost,10);
    insertionsort(testreversed,10);
    insertionsort(finaltest,10);

    
}

void insertionsort(int *array, int size){
    int temp;
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
    i=0;
    j=0;
}

void loadtest(){
    char *bp;
    FILE *fp;
    fp=fopen("sorttest.txt","r");
    fscanf(fp,"%d",test1);
    fscanf(fp,"%c",bp);
    for(i=0;i<2;i++){
        fscanf(fp,"%d",&test2[i]);
    }
    fscanf(fp,"%c",bp);
    for(i=0;i<3;i++){
        fscanf(fp,"%d",&test3[i]);
    }
    fscanf(fp,"%c",bp);
    for(i=0;i<10;i++){
        fscanf(fp,"%d",&testalmost[i]);
    }
    fscanf(fp,"%c",bp);
    for(i=0;i<10;i++){
        fscanf(fp,"%d",&testreversed[i]);
    }
    fscanf(fp,"%c",bp);
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