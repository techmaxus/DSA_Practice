//  https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

// Given an array of size at-least two,find the smallest subarray that needs to be sorted 
// in place so that entire input array become sorted. If the input array is already sorted, 
// the function should return [-1,-1], otherwise return start and end index of smallest subarray

// nlogn approach sort the array and find anamoly n+nlogn


#include<bits/stdc++.h>
using namespace std;

// vector<int> solve(vector<int> arr){
//     vector<int> ans = {-1,-1};
//     vector<int> copy = arr;
//     sort(arr.begin(),arr.end());

//     int i=0;
//     while(i<arr.size() && arr[i]==copy[i]){
//         i++;
//     }
//     if(i==arr.size()) return ans;
//     ans[0]=i;

//     i=arr.size()-1;
//     while(i>0 && arr[i]==copy[i]){
//         i--;
//     }
//     ans[1]=i;

//     return ans;
// }


// O(n) approach is to find all out of order number and saving 
// smallest of the and largest of them in single loop
// find right index for both element and return pair of that indexes

pair<int,int> solve(vector<int> arr){
    pair<int,int> ans = {-1,-1};
int largest=-1;
int smallest=INT_MAX;
   for(int i=1 ;i<arr.size()-1;i++){
       if(arr[i]>arr[i+1]||arr[i-1]>arr[i]){
           if(arr[i]>largest)   largest=arr[i];
           if(arr[i]<smallest)   smallest=arr[i];
       }
   }
    if(smallest==INT_MAX)  return ans;
    int i=0;
    while(i<arr.size() && arr[i]<=smallest ){
        i++;
    }
    
    ans.first=i;
    i=arr.size()-1;
    while(i>0 && arr[i]>=largest){
        i--;
    }
    ans.second=i;

    return ans;
}

int main(){
    vector<int> arr ={1,2,3,4,5,8,9,6,10,11};
    auto p =solve(arr);
    cout<<p.first<<"\t"<<p.second<<endl;
    return 0; 
}