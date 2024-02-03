#include<iostream>
using namespace std;

class Queue
{
 int queue[10];
 int front=-1, rear=-1;
 int MAXSIZE=9;
 public:
  bool EmptyQueue()
 {
  bool empty;
  if(front==rear==-1)
  {empty=true;}
  else
  {empty=false;}
  return empty;
 }
 bool FullQueue()
 {
  bool full;
  if(rear==MAXSIZE)
  {full=true;}
  else
  {full=false;}
  return full;
 }
 bool enqueue(int dataIn)
 {
  bool success;
  if(FullQueue()==1)
  {success=false;}
  else
  {queue[++rear]=dataIn;
   if(front=-1) front=0;
   success=true;}
  return success;
 }
 bool dequeue(int dataOut)
 {
  bool success;
  if(EmptyQueue()==1)
  {success=false;}
  else
  {dataOut=queue[front];
   cout<<"Dequeue operaton: "<<dataOut<<endl;
   if(front==rear) front=rear=-1;
   else
   {front++;}
	success=true;
  }
  return success;
 }
 bool QueueFront(int dataOut)
 {
  bool success;
  if(EmptyQueue()==1)
  {success=false;}
  else
  {dataOut=queue[front];
   cout<<"Queue Front: "<<dataOut<<endl;
   success=true;}
  return success;
 }
 bool QueueRear(int dataOut)
 {
  bool success;
  if(EmptyQueue()==1)
  {success=false;}
  else
  {dataOut=queue[rear];
   cout<<"Queue Rear: "<<dataOut<<endl;
   success=true;}
  return success;
 }
 int QueueCount()
 {
  if(EmptyQueue()==1)
  {cout<<"Queue is Empty"<<endl;
   return -1;}
  else
  return rear-front+1;
 }
};

int main()
{Queue q1;
 bool start=1;
 do{
     int option;
     cout<<"1. Enqueue\n2. Dequeue\n3. QueueFront\n4. QueueRear\n5. EmptyQueue\n6. FullQueue\n7. QueueCount\nChoose: ";
     cin>>option;
     switch(option)
     {case 1:
       {for(int i=0;i<10;i++)
       {int x;
        cout<<"Enter: ";
        cin>>x;
        bool success = q1.enqueue(x);
        if(success==0) cout<<"Unsuccessful"<<endl;
        cout<<"Do you want to continue? ";
        bool cont;
        cin>>cont;
        if(cont==0) break;}
       break;}
      case 2:
       {for(int i=0;i<5;i++)
       {int dataOut;
        bool success = q1.dequeue(dataOut);
        if(success==false) cout<<"Unsuccessful"<<endl;
        break;}}
      case 3:
       {int dataOut;
       bool success=q1.QueueFront(dataOut);
       if(success==false) cout<<"Unsuccessful"<<endl;
       break;}
      case 4:
       {int dataOut;
       bool success=q1.QueueRear(dataOut);
       if(success==false) cout<<"Unsuccessful"<<endl;
       break;}
      case 5:
        {bool empty=q1.EmptyQueue();
        if(empty==1) cout<<"Queue is empty"<<endl;
        else cout<<"Queue is not empty"<<endl;
        break;}
      case 6:
        {bool full=q1.FullQueue();
        if(full==1) cout<<"Queue is full"<<endl;
        else cout<<"Queue is not full"<<endl;
        break;}
      case 7:
        {int temp = q1.QueueCount();
        if(temp!=-1)
        cout<<"Queue Count: "<<temp<<endl;
        break;}}
      cout<<"Do you want to continue? ";
      cin>>start;
    }
    while(start!=0);
    return 0;
}
    







