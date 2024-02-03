MST
#include<iostream>
using namespace std;
struct arc;
struct vertex{
    bool processed, inqueue, intree;
    int data;
    arc* firsta;
    vertex* nextv;
};
struct arc{
    int w;
    vertex* adj;
    arc* link;
};
struct node{
    vertex* data;
    node* link;
};

class Stack{
    node* top;
    public:
    Stack(){
        top=NULL;
    }
    void push(vertex* d){
        node* temp = new node;
        temp->data=d;
        temp->link=top;
        top=temp;
    }
    vertex* pop(){
        vertex* temp = top->data;
        top=top->link;
        return temp;
    }
    vertex* topstack(){
        return top->data;
    }
};

class Queue{
    node* front;
    node* rear;
    public:
    Queue(){
        front=rear=NULL;
    }
    bool empty(){
        if(front) return false;
        else return true;
    }
    void enqueue(vertex* d){
        node* temp = new node;
        temp->data=d;
        temp->link=NULL;
        //cout<<"Enqueue"<<endl;
        if(front) rear->link=temp;
        else front=temp;
        rear=temp;
    }
    vertex* dequeue(){
        vertex* temp = front->data;
        front=front->link;
        return temp;
    }
};

class Graph{
    vertex* first;
    int count;
    public:
    Graph(){
        first=NULL;
        count=0;
    }
    void addv(int data){
        vertex* temp = new vertex;
        temp->data=data;
        temp->processed=false;
        temp->inqueue=false;
        temp->nextv = NULL;
        temp->firsta = NULL;
        if(first==NULL) {
            first=temp;
            if(!first->inqueue) cout<<"False"<<endl;
        }
        else{
            vertex* t = first;
            while(t->nextv!=NULL) t=t->nextv;
            t->nextv=temp;
            if(!t->nextv->inqueue) cout<<"False 2"<<endl;
        }
        count++;
    }
    void adda(int x, int y, int w){
        vertex* t1 = first;
        while(t1!=NULL && t1->data!=x)t1=t1->nextv;
        vertex* t2 = first;
        while(t2!=NULL && t2->data!=y)t2=t2->nextv;
        arc* temp1 = new arc;
        temp1->adj=t2;
        temp1->link=t1->firsta;
        temp1->w=w;
        t1->firsta = temp1;
        arc* temp2 = new arc;
        temp2->adj = t1;
        temp2->link = t2->firsta;
        temp2->w=w;
        t2->firsta = temp2;
    }
    void DFT(){
        cout<<"Function call 1"<<endl;
        Stack s;
        int nov=0;
        vertex* temp = first;
        s.push(temp);
        temp->processed=true;
        nov++;
        cout<<temp->data;
        while(nov!=count){
            vertex* n = s.topstack();
            arc* a = n->firsta;
            while(a!=NULL && a->adj->processed) a=a->link;
            if(a!=NULL){
                s.push(a->adj);
                a->adj->processed=true;
                nov++;
                cout<<a->adj->data;
            }
            else{
                vertex* n = s.pop();
                if(s.topstack()==NULL){
                    vertex* a=first;
                    while(a!=NULL && a->processed) a=a->nextv;
                    if(a!=NULL){
                        s.push(a);
                        a->processed=true;
                        nov++;
                        cout<<a->data;
                    }
                }
            }
        }
    }
    void BFT(){
        //cout<<"Function call 2"<<endl;
        Queue q;
        int nov=0;
        vertex* temp = first;
        cout<<temp->data<<endl;
        while(nov!=count){
            //cout<<"while loop 1"<<endl;
            for(temp=first; temp->processed; temp=temp->nextv){
                //cout<<"For loop"<<endl;
            }
            //cout<<"End of for"<<endl;
            if(!temp->inqueue){
                //cout<<"Enqueue"<<endl;
                q.enqueue(temp);
                temp->inqueue=true;
            }
            while(!q.empty()){
                //cout<<"while loop 2"<<endl;
                temp=q.dequeue();
                temp->inqueue=false;
                temp->processed=true;
                nov++;
                cout<<temp->data;
                for(arc* a = temp->firsta; a; a=a->link){
                    if(!a->adj->processed&& !a->adj->inqueue){
                        q.enqueue(a->adj);
                        a->adj->inqueue=true;
                    }
                }
            }
        }
    }
    void disp(){
        vertex* v = first;
        arc* a = NULL;
        for(;v;v=v->nextv){
            cout<<v->data<<" <---> ";
            a=v->firsta;
            for(;a;a=a->link){
                cout<<a->adj->data<<" ---> ";
            }
            cout<<"Null\n";
            cout<<"|\n|\n";
        }
        cout<<"Null\n\n";
    }
    void mst(){
        vertex* v = first;
        vertex* suc = NULL;
        for(vertex* temp = first; temp; temp=temp->nextv) temp->intree=false;
        
        int min=9999, sum=0;
        vertex* minedge = NULL;
        bool treec = false;
        
        v = first;
        v->intree=true;
        while(!treec){
            min=9999;
            treec=true;
            
            for(v=first; v; v=v->nextv){
                if(v->intree && v->firsta){
                    for(arc* a = v->firsta; a; a=a->link){
                        if(!a->adj->intree){
                            treec=false;
                            if(min>a->w){
                                min=a->w;
                                minedge = a->adj;
                                suc=v;
                            }
                        }
                    }
                }
            }
            if(minedge!=NULL && !treec){
                sum+=min;
                minedge->intree=true;
                cout<<suc->data<<" ---("<<min<<")---> "<<minedge->data<<endl;
            }
        }
        cout<<"Cost = "<<sum<<endl;
    }
};

int main(){
    Graph g;
    g.addv(3);
    g.addv(2);
    g.addv(1);
    g.addv(4);
    cout<<"ADDED VERTEX"<<endl;
    g.adda(3,2, 25);
    g.adda(2,1, 36);
    g.adda(1,4, 45);
    g.adda(3,1, 55);
    g.adda(2,4, 11);
    cout<<"ADDED ARC"<<endl;
    //g.DFT();
    cout<<endl;
    //g.BFT();
    cout<<endl;
    g.disp();
    g.mst();
    g.disp();
    return 0;
}


