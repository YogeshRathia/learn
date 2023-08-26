#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;
    int test_case;
    file = fopen("./input.txt", "r");
    fscanf(file, "%d", &test_case);
    for(int i=0;i<test_case;i++)
    {
        int n,k;
        fscanf(file, "%d",&n);
        fscanf(file, "%d",&k);
        printf("\n %d %d",n,k);
    }
    fclose(file);
    return 0;
}