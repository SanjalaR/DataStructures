#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int partition(int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    for (int j=p; j<r; j++){
   	 if (a[j]<=x){
   		 i++;
   		 int temp = a[i];
   		 a[i] = a[j];
   		 a[j] = temp;
   	 }
    }
    int temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;
    return i+1;
}

int rpartition(int a[], int p, int r){
    int i = (rand()%(r-p+1))+p;
    int temp = a[r];
    a[r] = a[i];
    a[i] = temp;
    return partition(a, p, r);
}

void rquicksort(int a[], int p, int r){
    if(p<r){
   	 int q = rpartition(a, p, r);
   	 rquicksort(a, p, q-1);
   	 rquicksort(a, q+1, r);
    }
}

int main(){
    ifstream file;
    int s = 0;
    int a[10000];
    file.open("input.txt");
    while (file>>a[s]){
   	 s++;
    }
    file.close();
    rquicksort(a, 0, s+1);
    ofstream files;
    files.open("output_rquick.txt");
    for(int i=0; i<=s; i++){
   	 files<<a[i]<<"  ";
    }
    files.close();
}


