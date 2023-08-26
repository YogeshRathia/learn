#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
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

void bubble_sort(int arr[],int n){
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

void random(int arr[],int n){
    for(int i=0;i<n;i++){
            arr[i] = rand()%10000;
    }
}

void descending(int arr[],int n){
    int c=n;
    for(int i=0;i<n;i++){
            arr[i]=c--;
    }
}

void ascending(int arr[],int n){
    for(int i=0;i<n;i++){
            arr[i]=i+1;
    }
    
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        if(i>=49){
            break;
        }
    }

}

void main(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime(&rawtime);
    clock_t start, end;
    double total_time_consumed,t1;
    FILE *in_File  = fopen("input.txt", "r");
    int L,N,S,K,P;
    fscanf(in_File,"%d",&L);
    for(int i=0;i<L;i++){
        fscanf(in_File,"%d %d %d %d",&N,&S,&K,&P);
        int arr[N];
        // N is number of integers.
        // K=0 elements are in random order 1 sorted 3 reverse sorted
        switch (K)
        {
        case 1:
            ascending(arr,N);
            break;
        case 2:
            descending(arr,N);
            break;
        
        case 0:
            random(arr,N);
            break;
        }

        // N S K P
        // P=0 nothing printed 1 only output 2 input and output printed
        if(P==2){
            print(arr,N);
        }

        // (0 Bubble, 1 Selection , 2 Insertion, 3 Merge, 4 Quick)
        switch (S)
        {
        case 0:
            start = clock(); // start time
            bubble_sort(arr,N);
            end = clock();
            total_time_consumed = ((double) (end - start)) / CLOCKS_PER_SEC;
            t1= total_time_consumed;
            break;
        
        case 1:
            start = clock(); // start time
            selection_sort(arr,N);
            end = clock();
            total_time_consumed = ((double) (end - start)) / CLOCKS_PER_SEC;
            t1= total_time_consumed;
            break;

        case 2:
            start = clock(); // start time
            insertion_sort(arr,N);
            end = clock();
            total_time_consumed = ((double) (end - start)) / CLOCKS_PER_SEC;
            t1= total_time_consumed;
            break;
        case 3:
            start = clock(); // start time
            merge_sort(arr,0,N-1);
            end = clock();
            total_time_consumed = ((double) (end - start)) / CLOCKS_PER_SEC;
            t1= total_time_consumed;
            break;
        case 4:
            start = clock(); // start time
            quick_sort(arr,0,N-1);
            end = clock();
            total_time_consumed = ((double) (end - start)) / CLOCKS_PER_SEC;
            t1= total_time_consumed;
            break;
        }


        // P=0 nothing printed 1 only output 2 input and output printed
        if(P==1 || P==2){
            print(arr,N);
        }


        printf("%f \n",t1);
    }

    fclose(in_File);
}