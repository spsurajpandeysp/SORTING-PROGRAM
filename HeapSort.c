#include<stdio.h>
void input(int *arr,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void display(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void heapify(int arr[],int n,int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest ;
    if(left<n && arr[left]>arr[i]){
        largest = left;
    }
    else{
        largest = i;
    }
    if(right<n && arr[right]>arr[largest]){
        largest =right;
    }
    if(i!=largest){
        int temp = arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr,n,largest);
    }
}
void createMaxHeap(int *arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}
void heapSort(int *arr,int n){
    createMaxHeap(arr,n);
    for(int i=n-1;i>0;i--){
        int last = arr[i];
        arr[i]=arr[0];
        arr[0]=last;
        heapify(arr,i,0);
    }
}
int main(){
    int arr[100],n;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    printf("Enter array element:\n");
    input(arr,n);
    printf("Array element before sorting:\n");
    display(arr,n);
    heapSort(arr,n);
    printf("Array element after sorting:\n");
    display(arr,n);
    return 0;
}