//  https://leetcode.com/problems/maximum-subarray/

//Maximum Subarray Sum
// Implement a function that takes an input a vector of integers, and prints the maximum subarray sum that can be formed. A subarray is defined as consecutive segment of the array. If all numbers are negative, then return 0.

// Input
// {-1,2,3,4,-2,6,-8,3}
// Output
// 13

// Expected Time Complexity
// O(N)
// Space Complexity
// O(1)

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> arr){

    int maxsofar =arr[0];
    int maxending =arr[0];
    for(int i=1;i<arr.size();i++){
        maxending=max(maxending+arr[i],arr[i]);
        maxsofar=max(maxending,maxsofar);
    }
    return maxsofar;
}

int main (){

    vector<int> arr={-1,2,3,4,-2,6,-8,3};
    cout<<solve(arr)<<endl;
    return 0;
}