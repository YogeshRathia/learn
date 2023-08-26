#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 5
void insert_array(int arr[], int size,int ret[]) {
    for (int i = 0; i < size; i++) {
        ret[i]=arr[i];
    }
    // printf("\n");
}
bool generateNext(int arr[], int size) {
    int i = size - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    int j = size - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    for (int l = i + 1, r = size - 1; l < r; l++, r--) {
        temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
    }
    return true;
}

bool isValidStackPermutation(int arr[], int size) {
    int stack[size];
    int top = -1;
    int current = 1;

    for (int i = 0; i < size; i++) {
        while (top >= 0 && stack[top] == current) {
            top--;
            current++;
        }
        if (arr[i] == current) {
            current++;
        } else {
            if (top >= 0 && stack[top] < arr[i]) {
                return false;
            }
            stack[++top] = arr[i];
        }
    }

    while (top >= 0 && stack[top] == current) {
        top--;
        current++;
    }

    return top == -1;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int lst[n];
    int arr[30];
    for (int i = 0; i < n; i++) {
        arr[i] = i+1;
    }

    do
    {
        insert_array(arr,n,lst);
        if(isValidStackPermutation(arr, n)){
            // printf("valid\n");
            for(int i=0;i<n;i++){
                printf("%d ",lst[i]);
            }
                printf("\n");
        }
        else{
            // printf("invalid\n");
            for(int i=0;i<n;i++){
                printf("%d ",lst[i]);
            }
            printf("\n");
        }
    } while (generateNext(arr, n));

    return 0;
}
