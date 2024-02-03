#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*link;
    Node(int val){
        data = val;
        link = nullptr;
    }
};

class Queue{
    Node* front;
    Node* rear;
    int count;
    public:
    Queue(){
        count=0;
        front=nullptr;
        rear=nullptr;
    }
    void enqueue(int dataIn){
        Node* temp = new Node(dataIn);
        if(rear==nullptr){
            front = temp;
        }
        else{
            rear->link = temp;
        }
        rear = temp;
        count++;
    }
    void dequeue(int dataOut){
        if(count==0){
            cout<<"Queue is empty"<<endl;
        }
        else{
            Node*temp = front;
            dataOut = temp->data;
            cout<<"Data: "<<dataOut<<endl;
            front=temp->link;
            if(front==nullptr){
                rear=nullptr;
            }
            count--;
        }
    }
    void queueFront(int dataOut){
        if(count==0){
            cout<<"Queue is empty"<<endl;
        }
        else{
            dataOut = front->data;
            cout<<"Queue Front: "<<dataOut<<endl;
        }
    }
    void queueRear(int dataOut){
        if(count==0){
            cout<<"Queue is empty"<<endl;
        }
        else{
            dataOut = rear->data;
            cout<<"Queue Rear: "<<dataOut<<endl;
        }
    }
    bool emptyQueue(){
        if(count==0) return true;
        else return false;
    }
    void queueCount(){
        cout<<"Queue Count: "<<count<<endl;
    }
    void destroyQueue(){
        while(front!=nullptr){
            Node* temp = front;
            front = temp->link;
            delete temp;
        }
        rear=nullptr;
        count=0;
    }
};
int main()
{Queue q1;
 bool start=1;
 do
 {int dataOut;
  int option;
  cout<<"1. Enqueue\n2. Dequeue\n3. Front data\n4. Rear data\n5. Empty Queue\n6. Queue Count\n7. Destroy Queue\nChoose: ";
  cin>>option;
  switch(option)
  {{case 1:
   bool cont=1;
   while(cont==1)
   {int data;
	cout<<"Enter: ";
	cin>>data;
	q1.enqueue(data);
	cout<<"Do you want to continue? ";
	cin>> cont;}
   break;}
   case 2:
   {q1.dequeue(dataOut);
   break;}
   case 3:
   {q1.queueFront(dataOut);
   break;}
   case 4:
   {q1.queueRear(dataOut);
   break;}
   case 5:
   {bool empty=q1.emptyQueue();
   if(empty==1) cout<<"Queue is Empty"<<endl;
   else cout<<"Queue is not Empty"<<endl;
   break;}
   case 6:
   {q1.queueCount();
   break;}
   case 7:
   {q1.destroyQueue();
	cout<<"Queue Destroyed"<<endl;}
   }
   cout<<"Do you want to continue? ";
   cin>>start;}
  while(start!=0);
  return 0;
}


