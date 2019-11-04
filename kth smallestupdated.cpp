#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int partition(int a[], int l, int r, int k); 
int findmed(int a[], int n) 
{ 
 sort(a, a+n);  // Sort aay 
 return a[n/2];    
} 
int kthSmallest(int a[], int l, int r, int k) 
{ 
 if (k > 0 && k <= r - l + 1) 
{ 
 int n = r-l+1; 
 int i, med[(n+4)/5]; 
 for (i=0; i<n/5; i++) 
      med[i] = findmed(a+l+i*5, 5); 
 if (i*5 < n) 
{ 
  med[i] = findmed(a+l+i*5, n%5);  
  i++; 
}     
 int medOfMed = (i == 1)? med[i-1]: kthSmallest(med, 0, i-1, i/2); 
 int pos = partition(a, l, r, medOfMed); 
 if (pos-l == k-1) 
     return a[pos]; 
 if (pos-l > k-1)        
  return kthSmallest(a, l, pos-1, k); 
return kthSmallest(a, pos+1, r, k-pos+l-1); 
} 
 return INT_MAX; 
} 
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
int partition(int a[], int l, int r, int x) 
{ 
 int i; 
 for (i=l; i<r; i++) 
     if (a[i] == x) 
         break; 
 swap(&a[i], &a[r]);  
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
     if (a[j] <= x) 
      { 
       swap(&a[i], &a[j]); 
       i++; 
     } 
    } 
    swap(&a[i], &a[r]); 
    return i; 
} 
int main() 
{ 
    int a[] = {12, 3, 5, 7, 4, 19, 26}; 
    int n = sizeof(a)/sizeof(a[0]), k = 3; 
    cout << "K'th smallest element is "
         << kthSmallest(a, 0, n-1, k); 
    return 0; 
} 