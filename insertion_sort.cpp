#include<iostream>
using namespace std;
int main()
{
 int list[6];
 cout<<"Enter 6 numbers: ";
 for(int i=0;i<6;i++)
 {
  cin>>list[i];
 }
 int current, last=6;
 int key, walker;
 for(current=1; current<last; current++)
 {
  key=list[current];
  for(walker=current-1; walker>=0 && key<list[walker]; walker--)
  {
   list[walker+1]=list[walker];
  }
  list[walker+1]=key;
 }
 for(int i=0;i<6;i++)
 {
  cout<<list[i]<<" ";
 }
}
