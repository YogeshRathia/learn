
#include <stdio.h>
#include <conio.h>
#define bool int
#define false 0
#define true 1
void selection_sort(int arr[],int n){
    bool swap=false;
    
    for(int i=0;i<n-1;i++){
        int min_value=arr[i];
        int swap_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min_value){
                min_value=arr[j];
                swap=true;
                swap_index=j;
            }
        }
        if(swap){
            int temp=arr[i];
            arr[i]=arr[swap_index];
            arr[swap_index]=temp;
        }
    }
}
int main() {
    int arr[]={4,1000,27,60,-4,44,98,100,2,99,100,100,1000};
    int n;
    n=sizeof(arr)/sizeof(int);
    selection_sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
