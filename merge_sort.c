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
    while (i1 < n && i2 < n){
            if (a1[i1] < a2[i2])
                dest[id++]=a1[i1++];
            else 
                dest[id++]=a2[i2++];
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
    return 0;
}
    
    

        
    
    
