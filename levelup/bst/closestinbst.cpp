//closest to element in bst
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        Node *left;
        Node *right;

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
void inorder(Node *root){
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->key<<",";
    inorder(root->right);
}
bool isPresent(Node * root,int key){
    if(root==NULL) return false;
    else if(root->key==key)  return true;
    else if(root->key>key) return isPresent(root->left,key);
    else if(root->key<key) return isPresent(root->right,key);
    else return false;
    
}
int findclosest(Node* root , int target){
    Node *node=root;
    int closest;
    int min=INT_MAX;
    while(node!=NULL){
        if(node->key==target)   return target;
        if(node->key<target){
            if(target-node->key<min){
                min=target-node->key;
                closest=node->key;
            }
            node=node->right;
        }
        else{
            if(node->key-target<min){
                min=node->key-target;
                closest=node->key;
            }
            node=node->left;
        }
        
    }
return closest;
}

int main(){
    
    vector<int> arr={8,3,10,1,6,14,4,7,13};
    
    Node * root=NULL;
    for(int i=0;i<arr.size();i++){
        root = insert(root,arr[i]);
    }
    //inorder(root);
    cout<<findclosest(root,12);
    return 0;
}