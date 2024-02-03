#include<iostream>
using namespace std;
void sort(int list[], int last)
{int walker, current=0, temp;
 bool sorted=false;
 while(current<=last&&!sorted)
 {
  walker=last;
  sorted=true;
  while(walker>current)
  {
   if(list[walker]<list[walker-1])
   {
	temp=list[walker];
	list[walker]=list[walker-1];
	list[walker-1]=temp;
	sorted=false;
   }
   walker-=1;
  }
  current+=1;
 }
}

bool binSearch(int list[], int first, int last, int target, int locn)
{if(first>last)
 {
  locn=-1;
  return false;
 }
 else
 {
  int mid=(first+last)/2;
  if(target<list[mid])
  {
   return binSearch(list, first, mid-1, target, locn);
  }
  else if(target>list[mid])
  {
   return binSearch(list, first, mid+1, target, locn);
  }
  else
  {
   locn=mid;
   cout<<"Location: "<<locn<<endl;
   return true;
  }
 }
}

int main()
{int list[6];
 cout<<"Enter 6 numbers: ";
 for(int i=0;i<6;i++)
 {
  cin>>list[i];
 }
 sort(list, 5);
 for(int i=0;i<6;i++)
 {
  cout<<list[i]<<" ";
 }
 cout<<endl;
 int target, first=0, last=5, locn;
 cout<<"Enter target number: ";
 cin>>target;
 bool found=binSearch(list, first, last, target, locn);
 cout<<found<<endl;
}
 
