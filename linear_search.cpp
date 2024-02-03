#include<iostream>
using namespace std;
bool seqSearch(int list[], int last, int target, int locn)
{int looker;
 for(looker=0;looker<last&&target!=list[looker];looker++)
 {}
 locn=looker;
 bool found;
 if(target==list[looker])
 {
  found=true;
 }
 else
 {
  found=false;
 }
 return found;
}

int main()
{
 int list[6];
 cout<<"Enter 6 numbers: ";
 for(int i=0;i<6;i++)
 {
  cin>>list[i];
 }
 int target, locn;
 cout<<"Enter target number: ";
 cin>>target;
 bool found=seqSearch(list, 6, target, locn);
 cout<<found<<endl;
}
 
