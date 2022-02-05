// Shortest Tree Path
// Given a Binary Search Tree and values of two nodes that lie inside the tree, find the Shortest Path Length between the two nodes.

//          10
//        /     \
//       4      15
//     /   \   /   \
//    2     5 13   22
//  /           \
// 1            14
// Examples

// Shortest Distance between (1,4) is 2.
// Shortest Distance between (2,13) is 4.
// Shortest Distance between (5,14) is 5.
// Hint:
// First find LCA, then note down the distance of two nodes from LCA.

#include<bits/stdc++.h>
using namespace std;

class node
{
  public:
   int key;
   node *left;
   node *right;

   node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

//here nodes a and b are the inputs
int shortestDist(node * root,int a,int b){
    if(root->key<a && root->key<b){
        return shortestDist(root->right,a,b);
    }
    else if(root->key>a && root->key>b){
        return shortestDist(root->left,a,b);
    }
    else {
        node * temp = root;
        int count=0;
        while(temp->key!=a){
            if(temp->key>a){
                temp=temp->left;
                count++;
            }
            else{
                temp=temp->right;
                count++;
            }
        }
        while(root->key!=b){
            if(root->key>b){
                root=root->left;
                count++;
            }
            else{
                root=root->right;
                count++;
            }
        }
        return count;

    }
    
    
    
    
}