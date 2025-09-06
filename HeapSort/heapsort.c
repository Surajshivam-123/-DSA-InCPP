#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void max_heapify(int a[],int i,int size){
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<size && a[l]>a[largest]){
        largest=l;
    }
    if(r<size && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(&a[i],&a[largest]);
        max_heapify(a,largest,size);
    }
}
void build_max_heapify(int a[],int size){
    for(int i=size/2-1;i>=0;i--){
        max_heapify(a,i,size);
    }
}
void heapsort(int a[],int size){
    build_max_heapify(a,size);
    int length=size;
    for(int i=length-1;i>=1;i--){
        swap(&a[0],&a[i]);
        size--;
        max_heapify(a,0,size);
    }
}
int max_element(int a[]){
    return a[0];
}
int heap_extract_max(int a[],int size){
    if(size<=0){
        printf("underflow\n");
        return -1;//underflow
    }
    int max=a[0];
    a[0]=a[size-1];
    size--;
    max_heapify(a,0,size);
    return max;
}
void heap_increase_key(int a[],int key,int pos){
    if(key<a[pos]){
        printf("key is lesser than original key\n");
        return;
    }
    a[pos]=key;
    while(pos>0 && a[(pos-1)/2]<a[pos]){
        swap(&a[pos],&a[(pos-1)/2]);
        pos=(pos-1)/2;
    }
}
int* max_heap_insert(int a[],int key,int size){
    int *temp = realloc(a, (size + 1) * sizeof(int));
    if (!temp) {
        printf("Memory allocation failed\n");
    return NULL;
}
a = temp;
    size++;
    a[size-1]=-__INT_MAX__;
    heap_increase_key(a,key,size-1);
    return a;
}
int main(){
    int *a=(int *)malloc(10*sizeof(int));
    for(int i=0;i<10;i++){
        a[i]=rand()%10;
    }
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    heapsort(a,10);
    a=max_heap_insert(a,2,10);
    heapsort(a,11);
    for(int i=0;i<11;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
return 0;
}