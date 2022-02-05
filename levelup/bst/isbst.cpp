#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

bool isValidBST(Node * root,int min,int max){
    if(root==NULL) return true;
    else if(root->key<min || root->key>max) return false;
    else isValidBST(root->left,min,root->key)&&isValidBST(root->right,root->key,max);
}
bool isBST(Node *root){
    return isValidBST(root,INT_MIN,INT_MAX);
}

Node* insert(Node *root , int key){
    if(root==NULL)  return new Node(key);
    if(key<root->key) root->left= insert(root->left,key);
    else root->right =insert(root->right,key);
    return root;
}

int main(){
    
    vector<int> arr={8,3,10,1,6,14,4,7,13};
    
    Node * root=NULL;
    for(int i=0;i<arr.size();i++){
        root = insert(root,arr[i]);
    }
    cout<<isBST(root);

    return 0;
}