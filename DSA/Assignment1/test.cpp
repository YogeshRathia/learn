#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
#define bool int
#define false 0
#define true 1
using namespace std;
void test(int arr[],int n){
    // int pivot_index=0;
    int pivot_value=arr[0];
    int l=1,r=n-1;
        while(l<r){
            cout<<"lr_"<<l<<"_"<<r<<endl;
            if(arr[l]<=pivot_value){
                l++;
            }
            if(arr[r]>pivot_value){
                r--;
            }
            if(arr[l]> pivot_value && pivot_value>arr[r]){
                int temp=arr[l];
                arr[l]=arr[r];
                arr[r]=temp;
            }
    
    
        }
        cout<<l<<"_-_"<<r<<endl;
        cout<<l<<"_"<<r<<endl;
        int temp=arr[0];
        arr[0]=arr[r];
        arr[r]=temp;
}
int main() {
    int arr[]={6,6,-6,-2,-4,-6,2,-6  };
    int n;
    n=sizeof(arr)/sizeof(int);
    test(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

/*
9 9 9 8 2 3 -6 
6 6 -6 -2 -4 -6 2 -6 
0 9 -4 -9 -9 -7 
1 -8 -8 2 
3 -8 0 6 -1 -5 
0 3 -5 
*/