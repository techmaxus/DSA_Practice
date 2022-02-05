//  https://leetcode.com/problems/longest-consecutive-sequence/

// Given an array of n integers return the longest band
// A band is defined as subsequence which can be reordered in such a manner
// that all elements appear consecutive

//Sorting the array and making all band and comparing the size in O(nlogn+n)

//using unordered_sets

#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> arr){

    unordered_set<int> s;
    // insert all elements in the given set
    for(int i =0;i<arr.size();i++){
        s.insert(arr[i]);
    }
    int max=0;

    // Iterate over all elements in the given arr ie O(n)
    for(int i =0;i<arr.size();i++){
        // Checking for if the element can start a chain ie if element-1 is present or not
        if(s.find(arr[i]-1)==s.end()){
            int j=0;
            int size=0;
            while(s.find(arr[i]+j)!=s.end()){
                size++;
                j++;
            }
            if(size>max)    max=size;
        }
    }
    
    return max;
}

int main(){
    
    vector<int> arr = {1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<solve(arr)<<endl;

    return 0;
}