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
int partition(int *arr,int lb,int ub){
    int pivot = arr[ub];
    int i=lb-1;
    for(int j=lb;j<ub;j++){
        if(arr[j]<=pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i]=arr[ub];
    arr[ub]=temp;
    return i;
}
void quickSort(int *arr,int lb,int ub){
    if(lb<ub){
        int pivot = partition(arr,lb,ub);
        quickSort(arr,lb,pivot-1);
        quickSort(arr,pivot+1,ub);
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
    quickSort(arr,0,n-1);
    printf("Array element after sorting:\n");
    display(arr,n);
    return 0;
}