// Given a special kind of Binary Search Tree,where every node also comtains a pointer to the parent node. 
// You have to find next inorder successor of a given target node in that tree. The node class look as below -
#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

Node* findInOrderSuccessor( Node *inputNode ){
    // if right subtree of node is present  ie simple case
    if(inputNode->right != NULL){
       // use temp iterator to reach left most node of right subtree
        Node* temp=inputNode->right;
        while(temp->left != NULL){
            temp=temp->left;
        }
        return temp;
    }
    else{
        // right sub tree is absent 
        // ans is the nearest ancestor whose right node exist
        // if any ansestor>node then return it
        Node* temp=inputNode;
        while(temp->parent != NULL){
        temp = temp->parent;
        if(temp->key > inputNode->key) return temp;
    }
    }

    
}