// to find lowest common ancesstor

// Given a Binary Search Tree and values of two nodes that lie inside the tree, find the Lowest Common Ancestor (LCA).
// Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T 
// that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).
// You may assume that both the values exist in the tree and are unique.
#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* lca(node*root, int a, int b){
    if(root==NULL)  return NULL;
    if(root->data<a && root->data<b){
        return lca(root->right,a,b);
    }
    else if(root->data>a && root->data>b){
        return lca(root->left,a,b);
    }
    else return root;
    
    
    
}
