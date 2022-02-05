// Array Products
// Implement a function that takes in a vector of integers, and returns a vector of the same length, 
// where each element in the output array is equal to the product of every other number in the input 
// array. Solve this problem without using division.

// In other words, the value at output[i] is equal to the product of every number in the input array 
// other than input[i]. You can assume that answer can be stored inside int datatype and no-overflow
// will occur due to products.

// Sample Input
// {1,2,3,4,5}
// Sample Output
// {120, 60, 40, 30, 24}

#include<bits/stdc++.h>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    //put in output array the product of element from 0 index to index i-1;
    //so output[0]=1 
    output[0]=1;
    for(int i=1;i<arr.size();i++){
        output[i]=arr[i-1]*output[i-1];
    }
    
    //now multiply all element of output with product of elements on right side of the chosen element
    int product=1;
    for(int i=arr.size()-1;i>=0;i--){
        output[i]*=product;
        product*=arr[i];
    }
    
    
    
    
    return output;
}

int main(){

    vector<int> arr = {1,2,3,4,5};
    auto ans =productArray(arr);
    cout<<"{";
    for(auto p : ans){
        cout<<p<<",";
    }
    cout<<"}";
    return 0;
}

