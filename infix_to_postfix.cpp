
#include<iostream>
#include<string>
using namespace std;

class stack{
    int a[100];
    int top=-1;
    public:
    void push(char x){
   	 a[++top]=x;
    }
    char pop(){
   	 return a[top--];
    }
    char stop(){
   	 return a[top];
    }
    bool isempty(){
   	 if(top==-1) return true;
   	 else return false;
    }
};

int priority(char ch){
    if(ch=='+' || ch=='-') return 1;
    else if(ch=='*' || ch=='/' || ch=='%') return 2;
    else if(ch=='^') return 3;
    else return 0;
}

int main(){
    stack s;
    string exp;
    char postfix[100];
    int l=0;
    cout<<"Enter infix expression: ";
    cin>>exp;
    for(int i=0; i<exp.size(); i++){
   	 char ch = exp[i];
   	 if(ch=='(')
   		 s.push('(');
   	 else if(ch==')'){
   		 s.pop();
   		 while(ch!='(' && !s.isempty()){
   			 postfix[l++]=ch;
   			 ch=s.pop();
   		 }
   	 }
   	 else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='%'){
   		 char top=s.stop();
   		 while(!s.isempty() && priority(ch)<=priority(top)){
   			 char c = s.pop();
   			 postfix[l++]=c;
   			 top = s.stop();
   		 }
   		 s.push(ch);
   	 }
   	 else{
   		 postfix[l++]=ch;
   	 }
   			 
    }
    while(!s.isempty()){
   	 char ch=s.pop();
   	 postfix[l++]=ch;
    }
    postfix[l]='\0';
    cout<<"Postfix: "<<postfix<<endl;
}
   	 
	


