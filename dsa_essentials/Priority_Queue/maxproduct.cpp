#include<bits/stdc++.h>
using namespace std;


int maxProduct(vector<int>& nums) {
    priority_queue<int> heap;
    for(int x: nums) heap.push(x);
    int y= heap.top();
    heap.pop();
    return y*heap.top();
}

int main(){
    vector<int> arr ={ 1,6,5,2,10,1,15,7,9};
    cout<<maxProduct(arr);
    return 0;
} 

