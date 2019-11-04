#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
long int partititon(long int [],long int ,long int ,long int);
void swap(long int *a,long int *b){
   /* *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
    */
   long int temp = *a; 
    *a = *b; 
    *b = temp; 
}
long int findmedian(long int arr[],long int n){
    //sort the given array
    sort(arr,arr+n);
    //return the median of the particular array
    return arr[n/2];

}
long int partition(long int arr[],long int l,long int r,long int x){
   long int i; 
 for (i=l; i<r; i++) 
     if (arr[i] == x) 
         break; 
    swap(&arr[i], &arr[r]);  
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
     if (arr[j] <= x) 
      { 
       swap(&arr[i], &arr[j]); 
       i++; 
     } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 

}

long int kthSmallest(long int a[], long int l, long int r, long int k) 
{ 
 if (k > 0 && k <= r - l + 1) 
{ 
 long int n = r-l+1; 
 long int i, med[(n+4)/5]; 
 for (i=0; i<n/5; i++) 
    // dividing each array into size of 5
    // calculating median for each of the partition and storing in median[] array
      med[i] = findmedian(a+l+i*5, 5); 
    if (i*5 < n) 
    { 
    med[i] = findmedian(a+l+i*5, n%5);  
    i++; 
    }
long int medOfMed;     
// it will again recursively call kthsmallest until only median remain
if(i==1){
    medOfMed =med[i-1];
}
else{
    kthSmallest(med,0,i-1,i/2);
}
 
 long int pos = partition(a, l, r, medOfMed); 
 if (pos-l == k-1) 
     return a[pos]; 
 if (pos-l > k-1)        
  return kthSmallest(a, l, pos-1, k); 
return kthSmallest(a, pos+1, r, k-pos+l-1); 
} 
 return INT_MAX; 
} 


int main(){
    long int n,i;
     cin>>n;
    long int arr[n];
   
    long int k;
    cin>>k;
    for(i=0;i<n;i++){
       arr[i] = i;
    }
    long int x =kthSmallest(arr,0,n-1,k);;
    cout<<x;
    return 0;
}