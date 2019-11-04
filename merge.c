#include<stdlib.h> 
#include<stdio.h> 
#include<time.h>  

void merge(long int arr[], long int l, long int m, long int r) 
{ 
    long int i, j, k; 
    long int n1 = m - l + 1; 
    long int n2 =  r - m; 
  
 
    long int L[n1], R[n2]; 
  

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(long int arr[], long int l, long int r) 
{ 
    if (l < r) 
    { 
        
        long int m = l+(r-l)/2; 
  

        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
void print(long int A[], long int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%ld ", A[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
   
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
  
    mergeSort(arr, 0, n-1); 
  
    printf("\nSorted array is \n"); 
    print(arr, n); 
     end = clock();
    total_time= ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f",total_time);
    FILE *fptr;
    fptr= fopen("data2.txt","a");
    fprintf(fptr,"%ld\t",n);
    fprintf(fptr,"%f",total_time);
    fprintf(fptr,"\n");
    fclose(fptr);
    return 0; 
} 