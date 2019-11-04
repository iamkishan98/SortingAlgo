#include<stdio.h>
#include<time.h>
void swap(long int *,long int *);
void selection(long int [],long int );
void main(){
    long int n;
    scanf("%ld",&n);
    clock_t start, end;
     double total_time;
     start = clock();
     srand(time(NULL));
    long int i;
    long int arr[n];
    for( i = 0; i < n; i++)
    {
       arr[i] =i;
    }
    selection(arr,n);
    end = clock();
    total_time= ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f",total_time);
    FILE *fptr;
    fptr= fopen("selectionworst.txt","a");
    fprintf(fptr,"%ld\t",n);
    fprintf(fptr,"%f",total_time);
    fprintf(fptr,"\n");
    fclose(fptr);
}
void selection(long int a[],long int n){
    
    long int i,j,num,temp;
    for(i=0;i<n;i++){
        printf("%ld\t",a[i]);
    }
    for(i=0;i<n-1;i++){
        num=a[i];
        for(j=i+1;j<n;j++){
            if(a[j] < num){
                swap(&a[j],&a[i]);
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%ld\t",a[i]);
    }

}
void swap(long int *a ,long int *b){
     int temp = *a;
    *a=*b;
    *b=temp; 
}