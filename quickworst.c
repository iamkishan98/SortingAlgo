
#include<stdio.h>
#include<time.h>

int main(){
    long int n;
    scanf("%ld",&n);
    clock_t start, end;
     double total_time;
     start = clock();
     srand(time(NULL));
    long int array[n];
    long int i;
    for(i=0;i<n;i++){
        array[i] = n-i;
    }
    quicksort(array,0,n-1);
    for( i = 0; i < n; i++)
    {
        printf("%ld\t",array[i]);
    }
     end = clock();
    total_time= ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f",total_time);
    FILE *fptr;
    fptr= fopen("quickworst.txt","a");
    fprintf(fptr,"%ld\t",n);
    fprintf(fptr,"%f",total_time);
    fprintf(fptr,"\n");
    fclose(fptr);
    
    return 0;
}
void quicksort(long int arr[],long int low,long int high){
    
    if(low<high){
        long int p = partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
        

    }
}
int partition(long int arr[],long int low,long int high){
    long int i,j;
   
    i= low-1;
    long int x = arr[high];
                                                                                     
    for(j=low;j<=high-1;j++){
        if(arr[j] <= x){
            
             i= i+1;
            swap(&arr[j] , &arr[i]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void swap(long int *a,long int *b){
    int temp = *a;
    *a=*b;
    *b=temp; 
}