#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void array_reverse(int arr[], int start, int end){
int temp;
while (start < end)
{
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
}
}

void add_constant(int arr[], int length, int num){
int i =0;
for(i=0;i<length;i++)
{
    arr[i]=arr[i]+num;
}
}

void mul_constant(int arr[], int length, int num){
int i =0;
for(i=0;i<length;i++)
{
    arr[i]=arr[i]*num;
}
}

int main(void){

time_t rawtime;
struct tm * timeinfo;

time ( &rawtime );
timeinfo = localtime(&rawtime);

printf("Current local time and date: %s", asctime (timeinfo) );

int n,num=5;

clock_t start, end; // For time calculation
double total_time_consumed,t1,t2,t3;
for (n=10000; n<=50000; n=n+20000) {
    int arr[n],i;
    for(i=0;i<n;i++) {
    arr[i] = rand()%10000; // Generate a number between 0 and 9999
}
start = clock(); // start time
for(int i=0;i<1000;i++){
    for(int i=0;i<1000;i++){
        for(int i=0;i<1000;i++){
            
        }
    }
}
end = clock(); // end time

total_time_consumed = ((double) (end - start)) / CLOCKS_PER_SEC;
t1= total_time_consumed;

start = clock(); // start time
add_constant(arr,n,num);
end = clock(); // end time

total_time_consumed = ((double) (end - start)) / CLOCKS_PER_SEC;
t2= total_time_consumed;

start = clock(); // start time
mul_constant(arr,n,num*2);
end = clock(); // end time

total_time_consumed = ((double) (end - start)) / CLOCKS_PER_SEC;
t3= total_time_consumed;
printf("\n Time Consumed when n=%d => %f \t %f \t %f",n, t1, t2, t3);
}
return 0;
}