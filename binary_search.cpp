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

bool binSearch(int list[], int last, int target, int locn)
{int begin=0, mid;
 int end=last;
 while(begin<=end)
 {
  mid=(begin+end)/2;
  if(target>list[mid])
  {
   begin=mid+1;
  }
  else if(target<list[mid])
  {
   end=mid-1;
  }
  else
  {
   begin=end+1;
  }
 }
 locn=mid;
 if(target==list[mid])
 {
  cout<<"Location: "<<locn<<endl;
  return true;
 }
 else
 {
  return false;
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
 int target, last=5, locn;
 cout<<"Enter target number: ";
 cin>>target;
 bool found=binSearch(list, last, target, locn);
 cout<<found<<endl;
}
 
