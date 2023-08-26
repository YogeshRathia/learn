#include <stdio.h>
#include <conio.h>
#define bool int
#define false 0
#define true 1
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
}
int main() {
    int arr[]={1,2,3,4,5,6,7,8,9,10,-5};
    int n;
    n=sizeof(arr)/sizeof(int);
    insertion_sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
