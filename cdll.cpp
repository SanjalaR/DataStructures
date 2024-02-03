
#include<iostream>
using namespace std;

struct node{
    int data;
    node* front;
    node* back;
};

struct list{
    int count;
    node*first;
    node*rear;
};

class CDLL{
    list* head;
    public:
    CDLL(){
        head = new list;
        head->count = 0;
        head->first = head->rear = NULL;
    }
    bool search(node* &pre, node* &loc, int target){
        pre = NULL;
        loc = head->first;
        if(loc!=NULL){
            if(loc->data==target) return true;
            if(loc->data>target) return false;
            pre=loc;
            loc=loc->front;
            while(loc!=head->first && loc->data<target){
                pre = loc;
                loc=loc->front;
            }
        }
        if(loc==head->first) return false;
        else{
            if(loc->data==target) return true;
            else return false;
        }

        cout<<"End of search"<<endl;
    }
    void insert(int data){
        node* pre = NULL;
        node* suc = NULL;
        bool found = search(pre, suc, data);
        if(!found){
            node* temp = new node;
            temp->data=data;
            temp->front = temp->back=NULL;
            if(pre==NULL){
                if(head->count==0){
                    head->first = temp;
                    head->rear = temp;
                }
                else{
                    head->first->back = temp;
                    head->rear->front = temp;
                }
                temp->back=head->rear;
                temp->front=head->first;
                head->first=temp;
                head->rear->front = temp;
            }
            else{
                temp->front=suc;
                temp->back=pre;
                pre->front=temp;
                if(suc==head->first){
                    head->rear = temp;
                }
                suc->back=temp;
            }
            head->count++;
        }
    }
    void deletee(int data){
        if(head->count==0) cout<<"Empty"<<endl;
        node* pre = NULL;
        node* loc = NULL;
        bool found = search(pre, loc, data);
        if(!found) cout<<"Not found"<<endl;
        else{
            if(pre==NULL){
                head->first = NULL;
                head->rear = NULL;
            }
            else{
                pre->front = loc->front;
                loc->front->back = pre;
            }
            if(loc==head->rear){
                head->rear = pre;
            }
            delete loc;
            head->count--;
        }
    }
    void disph(){
        node* temp = head->first;
        if(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->front;
        }
        while(temp!=head->first){
            cout<<temp->data<<"  ";
            temp=temp->front;
        }
        cout<<endl;
    }
    void dispr(){
        node* temp = head->rear;
        if(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->back;
        }
        while(temp!=head->rear){
            cout<<temp->data<<"  ";
            temp=temp->back;
        }
        cout<<endl;
    }
};

int main(){
    CDLL l;
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


