#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE sizeof(int)

int *test1,*test2,*test3,*testalmost,*testreversed,*finaltest;
int i,j;

void mallocandload();
void loadtest();
void printtest();
void insertionsort(int mode, int *array, int size);
void bubblesort(int *array, int size);
void printresult(int *array, int size);
void quicksort(int *array, int start, int end);
int partition(int *array, int start, int end);

int main(){
    mallocandload();
    printf("Test arrays:\n");
    printtest();
    printf("\nInsertion sort:\n");
    printf("Increasing:\n");
    insertionsort(1,test1,1);
    insertionsort(1,test2,2);
    insertionsort(1,test3,3);
    insertionsort(1,testalmost,10);
    insertionsort(1,testreversed,10);
    insertionsort(1,finaltest,10);
    mallocandload();
    printf("Decreasing:\n");
    insertionsort(2,test1,1);
    insertionsort(2,test2,2);
    insertionsort(2,test3,3);
    insertionsort(2,testalmost,10);
    insertionsort(2,testreversed,10);
    insertionsort(2,finaltest,10);
    mallocandload();
    printf("\nBubble sort:\n");
    bubblesort(test1,1);
    bubblesort(test2,2);
    bubblesort(test3,3);
    bubblesort(testalmost,10);
    bubblesort(testreversed,10);
    bubblesort(finaltest,10);
    mallocandload();
    printf("\nQuick sort:\n");
    quicksort(test1,0,0);
    printresult(test1,1);
    quicksort(test2,0,1);
    printresult(test2,2);
    quicksort(test3,0,2);
    printresult(test3,3);
    quicksort(testalmost,0,9);
    printresult(testalmost,10);
    quicksort(testreversed,0,9);
    printresult(testreversed,10);
    quicksort(finaltest,0,9);
    printresult(finaltest,10);

}

void quicksort(int *array, int start, int end){
    if(start<end){
         int pivotindex=partition(array,start,end);
         quicksort(array,start,pivotindex-1);
         quicksort(array,pivotindex+1,end);
    }
}

int partition(int *array, int start, int end){
    int pivot=array[start];
    int leftwall=start,rightwall=end;
    int temp;

    while(leftwall<rightwall){
        while(array[leftwall]<=pivot){
            leftwall++;
        }

        while(array[rightwall]>pivot){
            rightwall--;
        }
        if(leftwall<rightwall){
            temp=array[leftwall];
            array[leftwall]=array[rightwall];
            array[rightwall]=temp;
        }
    }
    array[start]=array[rightwall];
    array[rightwall]=pivot;
    
    return rightwall;
}


void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
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

void insertionsort(int mode, int *array, int size){
    //Increasing order
    if(mode==1){
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
    //Decreasing order
    if(mode==2){
        int temp;
        i=0;j=0;
        for(i=1;i<size;i++){
            j=i;
            while(j>0 && array[j-1]<array[j]){
                temp=array[j];
                array[j]=array[j-1];
                array[j-1]=temp;
                j-=1;
            }
        }
        printresult(array,size);
    }
    
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

void mallocandload(){
    test1=malloc(INT_SIZE);
    test2=malloc(INT_SIZE*2);
    test3=malloc(INT_SIZE*3);
    testalmost=malloc(INT_SIZE*10);
    testreversed=malloc(INT_SIZE*10);
    finaltest=malloc(INT_SIZE*10);
    loadtest();
}