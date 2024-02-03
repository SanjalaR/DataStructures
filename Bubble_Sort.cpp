#include<iostream>
using namespace std;
int main()
{
 int arr[6];
 cout<<"Enter 6 values: ";
 for(int i=0;i<6;i++)
 {
  cin>>arr[i];
 }
 int last=5, walker, current=0, temp;
 bool sorted=false;
 while(current<=last&&!sorted)
 {
  walker=last;
  sorted=true;
  while(walker>current)
  {
   if(arr[walker]<arr[walker-1])
   {
	temp=arr[walker];
	arr[walker]=arr[walker-1];
	arr[walker-1]=temp;
	sorted=false;
   }
   walker-=1;
  }
  current+=1;
 }
 for(int i=0;i<6;i++)
  {cout<<arr[i]<<" ";}
}
 

