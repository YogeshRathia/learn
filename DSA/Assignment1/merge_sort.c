#include <stdio.h>
#include <conio.h>
#define bool int
#define false 0
#define true 1
void merge(int arr[],int l,int r,int mid){
    int array_size1=mid-l+1;
    int array_size2=r-mid;
    int temp_arr1[array_size1];
    int temp_arr2[array_size1];
    // printf("array l=%d r=%d m=%d :",l,r,mid);
    // for(int i=l;i<=r;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");
    for(int i=0;i<array_size1;i++){
        temp_arr1[i]=arr[l+i];
    }
    for(int i=0;i<array_size2;i++){
        temp_arr2[i]=arr[mid+1+i];
    }
    int a1=0;
    int a2=0;
    int position=l;
    while(a1<array_size1 && a2<array_size2){
        if(temp_arr1[a1]<temp_arr2[a2]){
            arr[position]=temp_arr1[a1];
            a1++;
        }
        else{
            arr[position]=temp_arr2[a2];
            a2++;
        }
            position++;
        
    }
    while(a1<array_size1){
        arr[position]=temp_arr1[a1];
        position++;
        a1++;
    }
    while(a2<array_size2){
        arr[position]=temp_arr2[a2];
        position++;
        a2++;
    }
}
void merge_sort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int mid=(l+r)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    merge(arr,l,r,mid);
}
int main() {
    int arr[]={1,1,1,1,6};
    int n;
    n=sizeof(arr)/sizeof(int);
    int l=0;
    int r=n-1;
    merge_sort(arr,l,r);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
