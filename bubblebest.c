#include<stdio.h>
#include<time.h>
void bubblesort(long int [],long int );
void main(){
    long int n;
    scanf("%ld",&n);
     clock_t start, end;
     double total_time;
     start = clock();
     srand(time(NULL));
    long int arr[n];
    long int i;
    for(i=0;i<n;i++){
        arr[i] =i;
    }
   
    bubblesort(arr,n);
    end = clock();
    total_time= ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f",total_time);
    FILE *fptr;
    fptr= fopen("data4.txt","a");
    fprintf(fptr,"%ld\t",n);
    fprintf(fptr,"%f",total_time);
    fprintf(fptr,"\n");
    fclose(fptr);
}
void bubblesort(long int a[],long int n){
    long int i,j,swapped ;
    for(i=0;i<n-1;i++){
        swapped =0;
        for(j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                swapped =1;
                int temp =a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }

        }
        if(swapped == 0){
            break;
        }
    }
    for(i=0;i<n;i++){
        printf("%ld\t",a[i]);
    }
}