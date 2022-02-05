#include
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this-&gt;data = data;
		next = NULL;
	}
};


bool isPresent(node * head, int key){
    //Complete this function 
    if(head->data == key) return true;
    new node N = head;
    while(N!=null){
        if(n->data==key) return true;
        N=N->next;
    }
    return false;
    
    
    
    
}