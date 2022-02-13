#include<iostream>
#include<queue>

using namespace std;

//Custom comparator class 
class Compare{
public:
    bool operator()(int a, int b){
        //min heap ==> a > b
       //descending ==>
        return a < b;

}
};


int main(){
    int arr[]={0,15,20,13,6,90};
    int n = sizeof(arr)/sizeof(int);

// max heap  ==>  priority_queue<int> heap;
// min heap  ==>  priority_queue<int , vector<int> , greater<int>> heap;
//custom compare
    priority_queue<int , vector<int> , Compare> heap;
    for(int x:arr){
        heap.push(x);
    }
    while(!heap.empty()){
        cout<<heap.top()<<endl;
        heap.pop();
    }

    return 0;
}