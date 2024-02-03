DLL
#include <iostream>
using namespace std;

struct node{
    int data;
    node* back;
    node* front;
};

struct head{
    int count;
    node* first;
    node* rear;
};

class DLL{
    head* hn;
    public:
    DLL(){
        hn->count=0;
        hn->first = hn->rear = NULL;
    }
    bool search(node* &pre, node* &loc, int target){
        pre = NULL;
        loc = hn->first;
        while(loc!=NULL && target>loc->data){
            pre = loc;
            loc=loc->front;
        }
        if(loc==NULL) return false;
        else{
            if(loc->data==target) return true;
            else return false;
        }
    }
    void insert(int data){
        node* pre = NULL;
        node* suc = NULL;
        bool found = search(pre, suc, data);
        if(!found){
            hn->count++;
            node* temp = new node;
            temp->data=data;
            temp->back=temp->front=NULL;
            if(pre==NULL){
                temp->back = NULL;
                temp->front = hn->first;
                hn->first = temp;
            }
            else{
                temp->back = pre;
                temp->front = suc;
                pre->front = temp;
            }
            if(suc==NULL){
                hn->rear = temp;
            }
            else{
                suc->back = temp;
            }
        }
    }
    void disph(){
        node* temp = hn->first;
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->front;
        }
        cout<<endl;
    }
    void dispr(){
        node* temp = hn->rear;
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->back;
        }
        cout<<endl;
    }
    void deletee(int data){
        if(hn->count==0){
            cout<<"Empty"<<endl;
        }
        else{
            node* pre = NULL;
            node* loc = NULL;
            bool found = search(pre, loc, data);
            if(!found) cout<<"Not found"<<endl;
            else{
                pre->front = loc->front;
                loc->front->back=pre;
                delete loc;
            }
        }
    }
};

int main(){
    DLL l;
    int a;
    for(int i=0;i<4;i++){
        cout<<"Enter: ";
        cin>>a;
        l.insert(a);
    }
    cout<<"From head: "<<endl;
    l.disph();
    cout<<"From rear: "<<endl;
    l.dispr();
    cout<<"Enter: ";
    cin>>a;
    l.deletee(a);
    cout<<"From head: "<<endl;
    l.disph();
    cout<<"From rear: "<<endl;
    l.dispr();
    return 0;
}


