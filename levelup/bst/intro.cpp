#include <iostream>
#include<vector>
using namespace std;

// inorder traversal of any bst is always sorted
// advantage : restric branch searchin ==> order(h) not logn in case of skewed bst O(n)
// generally reccursive problem

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

int main(){
    
    vector<int> arr={8,3,10,1,6,14,4,7,13};
    
    Node * root=NULL;
    for(int i=0;i<arr.size();i++){
        root = insert(root,arr[i]);
    }
    inorder(root);
    cout<<isPresent(root,2)<<endl;
    cout<<isPresent(root,3)<<endl;
    return 0;
}