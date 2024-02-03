MERGE SORT
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

void merge(int arr[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int l[n1];
    int R[n2];
    for (int i=0; i<n1; i++){
   	 l[i]=arr[p+i];
    }
    for(int j=0; j<n2; j++){
   	 R[j]=arr[q+j+1];
    }
    int i=0;
    int j=0;
    l[n1] = R[n2] = 2147483647;
    for(int k=p; k<=r; k++){
   	 if(l[i]<=R[j]){
   		 arr[k]=l[i];
   		 i++;
   	 }
   	 else{
   		 arr[k]=R[j];
   		 j++;
   	 }
    }
}

void mergesort(int arr[], int p, int r){
    if(p<r){
   	 int q=(p+r)/2;
   	 mergesort(arr, p, q);
   	 mergesort(arr, q+1, r);
   	 merge(arr, p, q, r);
    }
}

int main(){
    int n=10000;
    int arr[n];
    int i=0;
    ifstream file;
    file.open("input.txt");
    while(!file.eof()){
   	 file>>arr[i];
   	 i++;
    }
    file.close();
    mergesort(arr, 0, n-1);
    ofstream files;
    files.open("output.txt");
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
   	 files<<arr[i]<<"  ";
    }

    files.close();
    cout<<endl;
}



