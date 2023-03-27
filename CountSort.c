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
void countSort(int *arr,int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>k){
            k= arr[i];
        }
    }
    int ans[n];
    int count[k+1];
    for(int i=0;i<=k;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]=count[arr[i]]+1;
    }
    for(int i=1;i<=k;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        ans[count[arr[i]]-1]=arr[i];
        count[arr[i]]=count[arr[i]]-1;
    }
    for(int i=0;i<n;i++){
        arr[i]=ans[i];
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
    countSort(arr,n);
    printf("Array element after sorting:\n");
    display(arr,n);
    return 0;
}