// inorder successor without calculating inorder
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


Node* insert(Node *root , int key){
    if(root==NULL)  return new Node(key);
    if(key<root->key) root->left= insert(root->left,key);
    else root->right =insert(root->right,key);
    return root;
}
static int succ=INT_MAX;
int inordersucc(Node *root ,int tar){
    if(root==NULL) return -1;
    else if(root->key==tar){
        if(root->right!=NULL){
            
            Node* temp=root->right;

            while(temp->left!=NULL){
                temp=temp->left;
            }
            return temp->key;
        }else{
            return succ;
        }
    }else if(root->key<tar){

        return inordersucc(root->right,tar);
    }else if(root->key>tar){
        if(root->key<succ) succ=root->key;
        return inordersucc(root->left,tar);
    }
}
int main(){
    
    vector<int> arr={8,3,10,1,6,14,4,7,13};
    
    Node * root=NULL;
    for(int i=0;i<arr.size();i++){
        root = insert(root,arr[i]);
    }
    cout<<inordersucc(root,8);
    return 0;
}