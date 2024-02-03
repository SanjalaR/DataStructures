#include<iostream>
using namespace std;
bool search(int list[], int index, int last, int locn, int target)
{
 if(index>last)
 {
  locn=-1;
  return false;
 }
 if(target==list[index])
 {
  locn=index;
  return true;
 }
 else
 {
  return search(list, index+1, last, locn, target);
 }
}

int main()
{int list[6];
 cout<<"Enter 6 numbers: ";
 for(int i=0;i<6;i++)
 {
  cin>>list[i];
 }
 int target, index=0, last=6, locn;
 cout<<"Enter target number: ";
 cin>>target;
 bool found=search(list, index, last, locn, target);
 cout<<found<<endl;
}
 
