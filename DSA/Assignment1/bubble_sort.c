#include <stdio.h>
#include <conio.h>
#define bool int
#define false 0
#define true 1

bubble_sort(int arr[],int n){
    int s=0;
    int e=n;
    bool enter=true;

    for(int i=0;i<n-1;i++){
        if(enter){
            enter=false;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    enter=true;
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }
}

int main() {
    int arr[]={4,1000,27,60,-4,44,98,100,2,99};
    int n;
    n=sizeof(arr)/sizeof(int);
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
