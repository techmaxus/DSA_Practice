// making bst of minimum height of sorted element
// 1 2 3 4 5 6 7 8 9
// we dont want a skewd tree
//normal creation method takes order of n^2

#include <iostream>
#include<vector>
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
Node* createbstfromsorted(vector<int> arr , int st, int end){
    if(st>end){
        return NULL;
    }
    int mid = (st+end)/2;
    Node *root=new Node(arr[mid]);
    root->left=createbstfromsorted(arr,st,mid-1);
    root->right=createbstfromsorted(arr,mid+1,end);

    return root;
}
void inorder(Node *root){
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->key<<",";
    inorder(root->right);
}

int main(){
    
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    
    Node * root=createbstfromsorted(arr,0,arr.size()-1);
    inorder(root);
    return 0;
}