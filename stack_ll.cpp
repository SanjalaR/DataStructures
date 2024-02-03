#include<iostream>
using namespace std;

class Node
{
 public:
 int data;
 Node* link;
 Node(int val)
 {data=val;
  link=nullptr;}
};

class Stack
{
 Node* head;
 int count;
 public:
 Stack()
 {head=nullptr;
  count=0;}
 void disp()
 {Node* temp;
  if(head==nullptr)
  {cout<<"Underflow2"<<endl;}
  else
  {temp=head;
   while(temp!=nullptr)
   {cout<<temp->data;
	temp=temp->link;
	if(temp!=nullptr) cout<<"  ";}
  cout<<endl;
  }
 }
 void push(int dataIn)
 {
  Node* temp = new Node(dataIn);
  temp->data = dataIn;
  temp->link = head;
  head=temp;
  count++;
  disp();
 }
 void pop(int dataOut)
 {
  Node*temp;
  if(head==nullptr)
  {cout<<"Underflow1"<<endl;}
  else
  {temp=head;
   dataOut=temp->data;
   cout<<"Data = "<<dataOut<<endl;
   head=temp->link;
   count--;
   disp();}
 }
 void top(int dataOut)
 {if(count==0)
  {cout<<"Empty Stack"<<endl;}
  else
  {dataOut=head->data;
   cout<<"Stack top: "<<dataOut<<endl;}
 }
 bool EmptyStack()
 {if (count==0)
  return true;
  else
  return false;
 }
 void destroy()
 {
  while(head!=nullptr)
  {Node* temp = head;
   head = temp->link;
   delete temp;}
  delete head;
 }
};

int main()
{Stack s1;
 bool start=1;
 do
 {int dataOut;
  int option;
  cout<<"1. Push\n2. Pop\n3. Stack Top\n4. Empty Stack\n5. Destroy Stack\nChoose: ";
  cin>>option;
  switch(option)
  {{case 1:
   bool cont=1;
   while(cont==1)
   {int data;
	cout<<"Enter: ";
	cin>>data;
	s1.push(data);
	cout<<"Do you want to continue? ";
	cin>> cont;}
   break;}
   case 2:
   {s1.pop(dataOut);
   break;}
   case 3:
   {s1.top(dataOut);
   break;}
   case 4:
   {bool empty=s1.EmptyStack();
   if(empty==1) cout<<"Stack is Empty"<<endl;
   else cout<<"Stack is not Empty"<<endl;
   break;}
   case 5:
   {s1.destroy();
	cout<<"Stack Destroyed"<<endl;}
   }
   cout<<"Do you want to continue? ";
   cin>>start;}
  while(start!=0);
  return 0;
}
