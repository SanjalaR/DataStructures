
#include<iostream>

using namespace std;

struct node
{
    int data;
    node *link;
};

struct head
{
    int count;
    node *first;
};

class SLL
{
private:
    head *headnode;

public:
    void create()
    {
        headnode=new head();
        headnode->count=0;
        headnode->first=NULL;
    }

    bool insert(int x)
    {
        int found;
        node *temp=new node;
        if(temp==NULL)
            return false;
        else
        {
            temp->data=x;
            temp->link=NULL;
        }
        
        node *ppre=NULL;
        node *ploc=NULL;
        found=search(ppre,ploc,x);
        
        if(found) ///Duplication check
            return false;
        
        if(ppre==NULL)
        {
            temp->link=headnode->first;
            headnode->first=temp;
            (headnode->count)++;
            return true;
        }
        else
        {
            temp->link=ppre->link;
            ppre->link=temp;
            (headnode->count)++;
            return true;
        }
    }

    bool del(int x)
    { 
        node* ppre=NULL;
        node* ploc=NULL;
        int found=search(ppre,ploc,x);
        
        if(!found)
            return false;
        
        if(ppre==NULL)
        { 
            node *temp=headnode->first;
            cout<<"Data deleted: "<<temp->data<<endl;
            headnode->first=headnode->first->link;
            delete temp;
            (headnode->count)--;
            return true;
        }
        else
        {
            node *temp=ploc;
            cout<<"Data deleted: "<<temp->data<<endl;
            ppre->link=ploc->link;
            delete temp;
            (headnode->count)--;
            return true;
        }
    }

    bool search(node *&ppre, node *&ploc, int target)
    {
        ppre=NULL;
        ploc=headnode->first;
        while(ploc!=NULL&&(ploc->data)<target)
        {
            ppre=ploc;
            ploc=ploc->link;
        }
        
        if(ploc==NULL)
            return false;
        else if(ploc->data == target)
            return true;
        else
            return false;
    }

    bool isfull()
    {
        node *temp=new node;
        if(temp==NULL)
            return true;
        else
        {
            delete temp;
            return false;
        }
    }

    bool isempty()
    {
        if(headnode->first==NULL)
            return true;
        else
        {
            return false;
        }
    }

    int returncount()
    {
        return (headnode->count);
    }

    void display()
    {
        cout<<"List elements:-\n";
        node *temp=headnode->first;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->link;
        }
        cout<<endl;
    }

    void destroy()
    {
        node *temp=headnode->first;
        while(headnode->first!=NULL)
        {
            temp=headnode->first;
            headnode->first=headnode->first->link;
            delete temp;
            (headnode->count)--;
        }
        delete headnode;
        cout<<"List Destroyed!"<<endl;
    }
};

int main()
{ 
    SLL s;
    int ch,x;
    node *ppre=NULL,*ploc=NULL;
    bool success;
    s.create();
    do
    {
        cout<<"1- insert, 2-delete, 3-search, 4-check if full, 5-check if empty, 6-get count, 7-display, 8-destroy, 0-exit:-\n";
        cout<<"Enter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter element to insert: ";
                cin>>x;
                success=s.insert(x);
                if(success)
                    cout<<"Element inserted successfully!\n";
                else
                { 
                    cout<<"Either memory full or duplication attempt!\n";
                }
                break;

            case 2:
                cout<<"Enter element to delete: ";
                cin>>x;
                success=s.del(x);
                if(success)
                    cout<<"Element deleted successfully!\n";
                else
                { 
                    cout<<"Element doesn't exist!\n";
                }
                break;

            case 3:
                cout<<"Enter element to search: ";
                cin>>x;
                success=s.search(ppre,ploc,x);
                if(success)
                    cout<<"Element present!\n";
                else
                    cout<<"Element not present!\n";
                break;

            case 4:
                if(s.isfull())
                    cout<<"List is full!"<<endl;
                else
                    cout<<"List is not full!"<<endl;
                break;

            case 5:
                if(s.isempty())
                    cout<<"List is empty!"<<endl;
                else
                    cout<<"List is not empty!"<<endl;
                break;

            case 6:
                cout<<"Count = "<<s.returncount()<<endl;
                break;

            case 7:
                s.display();
                break;

            case 8:
                s.destroy();
                break;

            case 0:
                cout<<"Program now exits.\n";
                break;
        }
    } while (ch!=0);

}
