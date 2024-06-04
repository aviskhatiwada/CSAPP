#include<stdio.h>
//csapp p564

void list(int* p1, int len){
    int i;
    for (i=0; i<len; i++){
        printf("%d ", *(p1+i));
    }
    printf("\n");
}

void merge(int a1[], int a2[], int dest[], int n){
    int i1=0;
    int i2=0;
    int id=0;
    // write for cond. mov
    // the first loop causes performance bottleneck (17.5 cpe), due to branch misprediction;
    while (i1 < n && i2 < n){
            if (a1[i1] < a2[i2]){
                dest[id]=a1[i1];
                id++;
                i1++;
            }

            else{
                dest[id]=a2[i2];
                id++;
                i2++;
            }
    }
        
    while (i1 < n)
        dest[id++]=a1[i1++];
    while (i2 < n)
        dest[id++]=a2[i2++];
    list(dest,3);
}


void merge1(int a1[], int a2[], int dest[], int n){
    int i1=0;
    int i2=0;
    int id=0;
    
    int if_1;
    int if_2;
    int move;
    // write for cond. mov
    while (i1 < n && i2 < n){
            if_1=a1[i1];
            if_2=a2[i2];

            move=(a1[i1] < a2[i2]);
            dest[id]=move ? if_1 : if_2;
            id++;
            i1+=move;
            i2+=(1-move);

    }
    while (i1 < n)
        dest[id++]=a1[i1++];
    while (i2 < n)
        dest[id++]=a2[i2++];
    list(dest,3);
}

int main(){
    int a1[3]={1,2,3};
    int a2[3]={2,3,4};
    int dest[10];
    merge(a1,a2,dest,3);
    merge1(a1,a2,dest,3);
    return 0;
}
    
    
