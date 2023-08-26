#include <stdio.h>
#include <conio.h>
#define bool int
#define false 0
#define true 1
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int find_pivot(int arr[],int s,int e){
    int pivot_value=arr[s];
    int l=s,r=e;
    while(l<r){
        while(arr[l]<=pivot_value && l<e){
            l++;
        }
        while(arr[r]>pivot_value && r>s){
            r--;
        }
        if(l<r){
            swap(&arr[l],&arr[r]);
        }
    }
    swap(&arr[s],&arr[r]);
    return r;  
}
void quick_sort(int arr[],int s,int e){
    if(s<e){
    int pivot_index=find_pivot(arr,s,e);
    quick_sort(arr,s,pivot_index-1);
    quick_sort(arr,pivot_index+1,e);
    }
}
int main() {
    int arr[]={6,6,-6,-2,-4,-6,2,-6 };
    int n;
    n=sizeof(arr)/sizeof(int);
    int s=0;
    int e=n-1;
    n=sizeof(arr)/sizeof(int);
    quick_sort(arr,s,e);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
