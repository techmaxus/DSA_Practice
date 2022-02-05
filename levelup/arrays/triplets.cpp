//  https://leetcode.com/problems/3sum/

// Given an array of N integer and an int s ie targetsum
// Find all distinct triplet that add up to form targetsum
// all triplet and their elements should also be sorted

// Brute force O(n^3)
// Using pair sum for each element in O(n^2) time

// New approach
// Sort the array and iterate over each element to find pairsum using 2 pointer approach

#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> arr,int S){
    vector<int> ans;
    // nlogn complexity for sorting the array
    sort(arr.begin(),arr.end());

    //for loop for n elements
    for(int i=0;i<=arr.size()-3;i++){
        int x=S-arr[i];
        int j=i+1;
        int k=arr.size()-1;

        //while loop for two pointer
        while(j<k){
            if(arr[k]+arr[j]==x ){
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                ans.push_back(arr[k]);
                k--;
                j++;
            }
            else if(arr[k]+arr[j]>x){
                k--;
            }
            else if(arr[k]+arr[j]<x){
                j++;
            }                
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {15,9,8,6,7,2,4,5,1,3};
    int S= 18;
    
    vector<int> r = solve(arr,S);
    for(int i=0;i<r.size()-2;i+=3){
        cout<<"("<<r[i]<<","<<r[i+1]<<","<<r[i+2]<<")   ";
    }
    
    
}