//bst to sorted linkedlist conversion
// 
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        Node *left;
        Node *right;
        Node *next;

        Node(int key){
            this->key=key;
            left=right=NULL;
        }
};

class Linkedlist{
    public:
        Node * head;
        Node * tail;
};

Node* insert(Node *root , int key){
    if(root==NULL)  return new Node(key);
    if(key<root->key) root->left= insert(root->left,key);
    else root->right =insert(root->right,key);
    return root;
}

Linkedlist treetoll(Node*root){
    Linkedlist l;
    if(root->left==NULL && root->right ==NULL)  {
        l.head=root;
        l.tail=root;
    }
    else if(root->left!=NULL && root->right ==NULL)  {
        l.head=treetoll(root->left).head;
        l.tail=root;
        treetoll(root->left).tail->next=root;
    }
    else if(root->left==NULL && root->right !=NULL)  {
        l.head=root;
        l.tail=treetoll(root->right).tail;
        root->next=treetoll(root->right).head;
    }
    else{
        l.head=treetoll(root->left).head;
        l.tail=treetoll(root->right).tail;
        treetoll(root->left).tail->next=root;
        root->next=treetoll(root->right).head;
    }


    return l;
}

int main(){
    
    vector<int> arr={8,3,10,1,6,14,4,7,13};
    
    Node * root=NULL;
    for(int i=0;i<arr.size();i++){
        root = insert(root,arr[i]);
    }
    Linkedlist ans = treetoll(root);
    Node * temp=ans.head;
    while(temp!=NULL){
        cout<<temp->key<<"  ";
        temp=temp->next;
    }
    return 0;
}