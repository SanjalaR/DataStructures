
#include <iostream>
#include <fstream>
using namespace std;

class InsertionSort{
    int n = 10000;
    int a[10000];
    int count;
    public:
    InsertionSort(){
   	 ifstream file;
   	 file.open("input_desc.txt");
   	 int i=0;
   	 while(file>>a[i]){
   		 i++;
   	 }
   	 file.close();
   	 sort();
    }
    private:
    void sort(){
   	 count = 0;
   	 for (int j = 1; j<n; j++){
   		 int key = a[j];
   		 int i = j-1;
   		 count++;
   		 while (i>=0 && a[i]>key){
   			 count++;
   			 a[i+1] = a[i];
   			 i--;
   		 }
   		 a[i+1] = key;
   	 }
   	 cout<<count<<endl;
    }
    public:
    ~InsertionSort(){
   	 ofstream files;
   	 files.open("output_ins.txt");
   	 for(int i=0; i<10000; i++){
   		 files<<a[i]<<"  ";
   	 }
   	 files.close();
    }
};

int main(){
    InsertionSort();
}
