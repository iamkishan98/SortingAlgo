#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
    clock_t start, end;
     double total_time;
     start = clock();
     srand(time(NULL));
        long  int n;
     scanf("%ld",&n);
    long int arr[n];
    long int i;
    for(i=0;i<n;i++){
        arr[i] = rand() % n +1;
    }
    
    insertion(arr,n);
    end = clock();
    total_time= ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f",total_time);
    FILE *fptr;
    fptr= fopen("insertionavg.txt","a");
    fprintf(fptr,"%ld\t",n);
    fprintf(fptr,"%f",total_time);
    fprintf(fptr,"\n");
    fclose(fptr);

}
void insertion(long int a[],long int n){
    long int i,j;
    for(i=0;i<n;i++){
       long  int key = a[i];
        long int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] =a[j];
            j =j-1;
        } 
        a[j+1] =key;
    }
    for(i=0;i<n;i++){
        printf("%ld\t",a[i]);
    }

}
