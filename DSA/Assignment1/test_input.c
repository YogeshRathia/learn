#include <stdio.h>
#include <conio.h>
#include <time.h>
#define bool int
#define false 0
#define true 1
void goto_loop(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){

            }
        }
    }
}
int main() {

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime(&rawtime);

    printf("Current local time and date: %s", asctime (timeinfo) );

    int n,num=5;

    clock_t start, end; // For time calculation
    double total_time_consumed,t1,t2,t3;


    FILE *in_File  = fopen("input.txt", "r");
    int L,N,S,K,P;
    fscanf(in_File,"%d",&L);
    // printf("%d,%d,%d,%d",N,S,K,P);
    for(int i=0;i<L;i++){
    fscanf(in_File,"%d %d %d %d",&N, &S, &K, &P);
    printf("%d,%d,%d,%d \n",N,S,K,P);

    }

    start = clock();
    goto_loop(100);
    end = clock();
    end = clock(); 
    total_time_consumed = ((double) (end - start)) / CLOCKS_PER_SEC;
    t1= total_time_consumed;
    printf("\n Time Consumed when => %f", t1);
    
    fclose(in_File);
    return 0;

}
