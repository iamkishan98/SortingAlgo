#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;
long int findmed(long int arr[] ,long int size ){
    sort(arr,arr+size);
    return arr[(size/2)];
    //returns the median of every subarray
}
long int kthsmall(long int arr[],long int low,long int high,long int k){
    if(k>0 && k<=high - low +1){
        long int n = high -low +1;
        long int i;
        long int medians[(n+4)/5];
         for(i=0;i<n/5;i++){
                medians[i] = findmed(arr+low+i*5,5);
            }
            //If last subarray is having lesser than 5 elements
        if(i *5 <n){
            medians[i] = findmed(arr +low +i*5, n%5);
            i ++;
        
        }
        long int midmed = (i==1)? me





    }
    
}
int main(){
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
		<< kthsmall(arr, 0, n-1, k); 
    //fclose(fptr);
    ifile.close();
    return 0;    
}