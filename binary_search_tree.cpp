
#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

class BST{
    public:
    node* root;
    BST(){
        root=NULL;
    }
    node* insert(node* root, int data){
        if(root==NULL){
            node* temp = new node;
            temp->data = data;
            temp->left = temp->right = NULL;
            root = temp;
            return root;
        }
        if(data<root->data){
            root->left = insert(root->left, data);
        }
        else{
            root->right = insert(root->right, data);
        }
        return root;
    }
    void inorder(node* root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data<<"  ";
            inorder(root->right);
        }
    }
    void preorder(node* root){
        if(root!=NULL){
            cout<<root->data<<"  ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(node* root){
        if(root!=NULL){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<"  ";
        }
    }
    int largest(node* root){
        if(root->right!=NULL) return largest(root->right);
        else return root->data;
    }
    void smallest(node* root){
        if(root->left!=NULL) smallest(root->left);
        else cout<<root->data<<endl;
    }
    node* deletee(node* root, int data){
        if(root==NULL) return root;
        if(data<root->data) root->left= deletee(root->left, data);
        else if(data>root->data) root->right=deletee(root->right, data);
        else if(root->left==NULL){
            node* dlt = root;
            root=root->right;
            delete dlt;
            return root;
        }
        else if(root->right==NULL){
            node* dlt = root;
            root = root->left;
            delete dlt;
            return root;
        }
        else{
            int large = largest(root->left);
            root->data = large;
            root->left = deletee(root->left, large);
        }
        return root;
    }
};

int main(){
    BST t;
    int a;
    for(int i=0;i<4;i++){
        cout<<"Enter: ";
        cin>>a;
        t.root=t.insert(t.root,a);
    }
    cout<<"Inorder: "<<endl;
    t.inorder(t.root);
    cout<<"\nPreorder: "<<endl;
    t.preorder(t.root);
    cout<<"\nPostorder: "<<endl;
    t.postorder(t.root);
    cout<<"\nLargest: ";
    int l = t.largest(t.root);
    cout<<l<<endl;
    cout<<"Smallest: ";
    t.smallest(t.root);
    cout<<"Enter: ";
    cin>>a;
    t.deletee(t.root, a);
    cout<<"Inorder: "<<endl;
    t.inorder(t.root);
    cout<<"\nPreorder: "<<endl;
    t.preorder(t.root);
    cout<<"\nPostorder: "<<endl;
    t.postorder(t.root);
    cout<<"\nLargest: ";
    l = t.largest(t.root);
    cout<<l<<endl;
    cout<<"Smallest: ";
    t.smallest(t.root);
    return 0;
}

