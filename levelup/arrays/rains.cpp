//  https://leetcode.com/problems/trapping-rain-water/

// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining

//brute force O(n^2)

#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> arr){
    int n=arr.size();
    if(n<3)  return 0;
    int ans=0;
    // storing leftmax element so far
    vector<int> left(n,0);
    // storing rightmax element so far
    vector<int> right(n,0);
    left[0]=arr[0];
    right[0]=arr[0];
    for(int i=1;i<arr.size();i++){
        left[i]=max(left[i-1],arr[i]);
        right[n-1-i]=max(left[i-1],arr[i]);
    }
    for(int i=0;i<arr.size();i++){
        ans+=min(left[i],right[i])-arr[i];
    }  
    return ans;
}

int main(){
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<solve(arr)<<endl;
    return 0;
}

