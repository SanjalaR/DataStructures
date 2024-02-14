#include<iostream>
using namespace std;

class Node{
    
    public:
    string city;
    string state;
    
    Node(){
        cout<<"Enter city: ";
        cin>>city;
        cout<<"Enter state: ";
        cin>>state;
    }
    
    string toString(){
        return "City: "+city+"\tState: "+state+"\n";
    }
};

class Sort{
    Node *arr[10];
    int n;
    public:
    
    Sort(){
        n=9;
        
        for(int i=0; i<n; i++){
            arr[i] = new Node();
        }
     
        city_sort();
        state_sort();
    
        
        for (int i=0; i<n; i++){
            string str = arr[i]->toString();
            cout<<str;
        }
    }
    
    void state_sort(){
        for (int j = 1; j<n; j++){
       		 Node *key = arr[j];
       		 int i = j-1;
       		 while (i>=0 && arr[i]->state>key->state){
       			 arr[i+1] = arr[i];
       			 i--;
       		 }
       		 arr[i+1] = key;
        }
    }

    void city_sort(){
        for (int j = 1; j<n; j++){
       		Node *key = arr[j];
       		int i = j-1;
       		while (i>=0 && arr[i]->city>key->city){
           		arr[i+1] = arr[i];
           		i--;
   		    }
   		    arr[i+1] = key;
        }
    }

};


int main(){
    new Sort();
}
