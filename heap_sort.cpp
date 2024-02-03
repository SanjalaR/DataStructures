HEAP SORT

#include <iostream>
#include <fstream>
using namespace std;

int heapsize;
int length = 10000;

int Left(int i){
return 2*i+1;
}

int Right(int i){
return 2*i+2;
}

void maxheapify(int a[], int i){
int l=Left(i);
int r=Right(i);
int largest;
if (l<heapsize && a[l]>a[i]){
largest = l;
}
else{
largest = i;
}
if (r<heapsize && a[r]>a[largest]){
largest = r;
}
if(largest!=i){
int temp = a[i];
a[i]=a[largest];
a[largest] = temp;
maxheapify(a, largest);
}
}

void build_maxheap(int a[]){
heapsize = length;
for(int i=(length-2)/2; i>=0; i--){
maxheapify(a, i);
}
}

void heapsort(int a[]){
build_maxheap(a);
for(int i=length-1; i>=1; i--){
int temp = a[0];
a[0]=a[i];
a[i]=temp;
heapsize--;
maxheapify(a,0);
}
}


int main(){
ifstream file;
file.open("input.txt");
int s=0;
int a[length];
while(file>>a[s]){
s++;
}
file.close();
heapsort(a);
ofstream files;
files.open("output_heap.txt");
for(int i=0; i<length; i++){
files<<a[i]<<"  ";
}
files.close();
}


OOA
#include <iostream>
#include <fstream>
using namespace std;

class HeapSort{
    private:
    int a[10000];
    int length = 10000;
    int heapsize;
    
    int Left(int i){
   	 return 2*i+1;
    }

    int Right(int i){
   	 return 2*i+2;
    }

    void maxheapify(int a[], int i){
   	 int l=Left(i);
   	 int r=Right(i);
   	 int largest;
   	 if (l<heapsize && a[l]>a[i]){
   		 largest = l;
   	 }
   	 else{    
   		 largest = i;
   	 }
   	 if (r<heapsize && a[r]>a[largest]){
   		 largest = r;
   	 }
   	 if(largest!=i){
   		 int temp = a[i];
   		 a[i]=a[largest];
   		 a[largest] = temp;
   		 maxheapify(a, largest);
   	 }
    }

    void build_maxheap(int a[]){
   	 heapsize = length;
   	 for(int i=(length-2)/2; i>=0; i--){
   		 maxheapify(a, i);
   	 }
    }
    
    void heapsort(int a[]){
   	 build_maxheap(a);
   	 for(int i=length-1; i>=1; i--){
   		 int temp = a[0];
   		 a[0]=a[i];
   		 a[i]=temp;
   		 heapsize--;
   		 maxheapify(a,0);
   	 }
    }    
   	 
    public:
    
    HeapSort(){
   	 ifstream file;
   	 file.open("input.txt");
   	 int s=0;

   	 while(file>>a[s]){
   		 s++;
   	 }
   	 file.close();
   	 heapsort(a);
    }
    ~HeapSort(){
   	 ofstream files;
   	 files.open("output_hs.txt");
   	 for(int i=0; i<length; i++){
   		 files<<a[i]<<"  ";
   	 }
   	 files.close();
    }
    
};

int main(){
    HeapSort hs;
    return 0;
    
}
