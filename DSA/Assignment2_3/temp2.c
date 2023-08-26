#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

bool isValidStackPermutation(int arr[], int size) {
    int stack[MAX_SIZE];
    int top = -1;
    int current = 1;  // The next number to push

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
    int arr[MAX_SIZE];

    printf("Enter the permutation of 1, 2, 3, 4, 5: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    if (isValidStackPermutation(arr, MAX_SIZE)) {
        printf("The given permutation is a valid stack permutation.\n");
    } else {
        printf("The given permutation is not a valid stack permutation.\n");
    }

    return 0;
}
