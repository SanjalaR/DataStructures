#include<iostream>
using namespace std;

void display(int array[], int size)
{for(int walker=0;walker<size;walker++)
 {cout<<array[walker]<<"  ";}
 cout<<endl;
}
void input(int array[], int size)
{for(int walker=0;walker<size;walker++)
 {cout<<"Enter: "; cin>>array[walker];}
 cout<<"Input: ";
 display(array,size);
}

void sort(int array[], int size)
{int var,m,flag=0;
 for(int current=0;current<size-1;current++)
 {int smallest=array[current];flag=0;
  for(int walker=current+1;walker<size;walker++)
  {if(smallest>array[walker]) 
   {flag=1;smallest=array[walker]; var=walker;}}
    if(flag){
	int temp=array[current];
  array[current]=array[var];
  array[var]=temp;
}
  //display(array,size);
 //cout<<"smallest="<<smallest;
 //cout<<"current="<<array[current];
 }
}
  
int main()
{int size;
 cout<<"Enter size of array: ";   
 cin>>size;
 int array[size];
 input(array, size);
 sort(array,size);
 display(array,size);
 return 0;
}
