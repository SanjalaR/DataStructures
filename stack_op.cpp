#include<iostream>
using namespace std;

class Stack 
{int stack[5];
 int top=-1;
 int MAXSIZE=4;
 public:
 bool EmptyStack()
 {
  bool empty;
  if(top==-1)
  empty=true;
  else
  empty=false;
  return empty;
 }
 bool FullStack()
 {
  bool full;
  if(top==MAXSIZE)
  full=true;
  else
  full=false;
  return full;
 }  
 bool push(int data)
 {
  bool success;
  if(FullStack()==1)
  {cout<<"Stack Overflow"<<endl;
   success=false;}
  else
  {stack[++top]=data;
   success = true;}
  return success;
 }
 bool pop(int dataOut)
 {
  bool success;
  if(EmptyStack()==1)
  {cout<<"Stack Underflow"<<endl;
   success=false;}
  else
  {dataOut=stack[top--];
   cout<<"Pop data: "<<dataOut<<endl;
   success=true;}
  return success;
 }
 bool StackTop(int dataOut)
 {
  bool success;
  if(EmptyStack()==1)
  {cout<<"Stack Underflow"<<endl;
   success=false;}
  else
  {dataOut=stack[top];
   cout<<"Stack top: "<<dataOut<<endl;
   success=true;}
  return success;
 }
};

int main()
{Stack s1;
 bool start=1;
 do
 {int option;
 cout<<"1. Push\n2. Pop\n3. StackTop\n4. EmptyStack\n5. FullStack\nChoose: ";
 cin>>option;
 switch(option)
 {case 1:
 for(int i=0;i<5;i++)
 {int x;
  cout<<"Enter: ";
  cin>>x;
  bool success = s1.push(x);
  if(success==0) cout<<"Unsuccessful"<<endl;
  cout<<"Do you want to continue? ";
  bool cont;
  cin>>cont;
  if(cont==0) break;
 }
  break;
  case 2:
 for(int i=0;i<5;i++)
  {int dataOut;
   bool success = s1.pop(dataOut);
   if(success==false) cout<<"Unsuccessful"<<endl;
  break;} 
  case 3:
  {int dataOut;
  bool success = s1.StackTop(dataOut);
  if(success==false) cout<<"Unsuccessful"<<endl;
  break;}
  case 4:
  {bool empty = s1.EmptyStack();
  if(empty==1) cout<<"Stack is empty"<<endl;
  else cout<<"Stack is not empty"<<endl;
  break;}
  case 5:
  {bool full = s1.FullStack();
  if(full==1) cout<<"Stack is full"<<endl;
  else cout<<"Stack is not full"<<endl;
  break;}
 }
 cout<<"Do you want to continue? ";
 cin>>start;
 }
 while(start!=0);
 return 0;
}

