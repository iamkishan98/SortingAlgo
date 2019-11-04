
#include<iostream> 
#include<algorithm> 
#include<climits> 
#include<stdio.h>
#include<fstream>
using namespace std; 
long int findMedian(long int arr[], long int n) 
{ 
	sort(arr, arr+n); // Sort the array 
	return arr[n/2]; // Return middle element 
} 

long int partition(long int arr[], long int l, long int r, long int k); 

long int kthSmallest(long int arr[], long int l, long int r, long int k) 
{ 
	// If k is smaller than number of elements in array 
	if (k > 0 && k <= r - l + 1) 
	{ 
		long int n = r-l+1; // Number of elements in arr[l..r] 

		// Divide arr[] in groups of size 5, calculate median 
		
		long int i, median[(n+4)/5]; 
		for (i=0; i<n/5; i++) 
			median[i] = findMedian(arr+l+i*5, 5); 
		if (i*5 < n) //For last group with less than 5 elements 
		{ 
			median[i] = findMedian(arr+l+i*5, n%5); 
			i++; 
		}	 

		
	
		long int medOfMed = (i == 1)? median[i-1]: 
								kthSmallest(median, 0, i-1, i/2); 

	
		long int pos = partition(arr, l, r, medOfMed); 

	
		if (pos-l == k-1) 
			return arr[pos]; 
		if (pos-l > k-1) 
			return kthSmallest(arr, l, pos-1, k); 

		// Else traverse for right subarray 
		return kthSmallest(arr, pos+1, r, k-pos+l-1); 
	} 

	// If k is more than number of elements in array 
	return INT_MAX; 
} 

void swap(long int *a, long int *b) 
{ 
	long int temp = *a; 
	*a = *b; 
	*b = temp; 
} 


long int partition(long int arr[], long int l, long int r, long int x) 
{ 
	// Search for x in arr[l..r] and move it to end 
	long int i; 
	for (i=l; i<r; i++) 
		if (arr[i] == x) 
		break; 
	swap(&arr[i], &arr[r]); 

	// Standard partition algorithm 
	i = l; 
	for (long int j = l; j <= r - 1; j++) 
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

int main() 
{ 
    /*FILE  *fptr;
    fptr = fopen("num.txt","r");
    if (fptr == NULL){
        printf("Error Reading File\n");
        exit (0);
    }
*/
ifstream ifile;
ifile.open("n1.txt");
if (!ifile) {
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
}
cout<<"opened\n";
	long int n;
    //cin>>n;
    long int arr[100000] ;
     int  k = 9; 
    //for(long int i=0;i<n;i++){
        //fscanf(fptr,"%ld",&arr[i]);
      //  arr[i] = rand()%n +1;
   // }
    long int i=0;
   for(i=0;i<100000;i++){
       ifile >> arr[i];
   }
   n =sizeof(arr)/sizeof(arr[0]);
	cout << "K'th smallest element is "
		<< kthSmallest(arr, 0, n-1, k); 
    //fclose(fptr);
    ifile.close();
	return 0; 
} 
