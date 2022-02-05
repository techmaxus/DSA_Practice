//  https://leetcode.com/problems/two-sum/

// Given an array containing n integer and integer S ie target
// you need to find number of pair of two number whose sum is equal to S

// Brute force O(N^2)
// take each number and try to form all number

// Sort + Binary search O(nlogn)
// Sort the array in nlogn time 
// for each element make a binary search O(logn)*n
// So total of nlogn 

// Sort and two pointer approach

// Use of unordered set
// search in O(1) time
// for each element lookup in set and add to set if it's complement is not present

#include<bits/stdc++.h>

using namespace std;

vector<int> solve1(vector<int> arr,int S){
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            if(arr[i]+arr[j]==S) {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
        }
    }
    return ans;
}
vector<int> solve2(vector<int> arr,int S){
    vector<int> ans;
    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++){
        int complement=S-arr[i];
        int left=i;int right=arr.size()-1;
        while(left<=right){
            int mid=left +(right-left)/2;
            if(arr[mid]==complement) {
                ans.push_back(arr[i]);
                ans.push_back(arr[mid]);
                break;
            }
            if(arr[mid]<complement) {
                left=mid+1;
            }
            if(arr[mid]>complement) {
                right=mid-1;
            }
        }
    }
    return ans;
}
vector<int> solve3(vector<int> arr,int S){
    vector<int> ans;
    unordered_set <int> s;
    for(int i=0;i<arr.size();i++){
        int x=S-arr[i];
        if(s.find(x)!=s.end()){
            ans.push_back(arr[i]);
            ans.push_back(x);
        }
        else{
            s.insert(arr[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {-6,9,8,5,1,18,4,88,-9,-15,-98,0,100};
    int S= 9;
    vector<int> p = solve1(arr,S);
    for(int i=0;i<p.size()-1;i+=2){
        cout<<"("<<p[i]<<","<<p[i+1]<<")\t";
    }
    cout<<"\n-------------------------------------------------------"<<endl;
    vector<int> q = solve2(arr,S);
    for(int i=0;i<q.size()-1;i+=2){
        cout<<"("<<q[i]<<","<<q[i+1]<<")\t";
    }
    cout<<"\n-------------------------------------------------------"<<endl;
    vector<int> r = solve3(arr,S);
    for(int i=0;i<r.size()-1;i+=2){
        cout<<"("<<r[i]<<","<<r[i+1]<<")\t";
    }
    
    
}