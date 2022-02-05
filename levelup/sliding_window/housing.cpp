// Along one side of a road there is a sequence of vacant plots of land. Each plot 
// has a different area(non-zero). So,the areas form a sequence A[1],A[2],.....A[N]

// You want to buy K acres of land to build a house. You want to find all segments 
// of contiguous plots(ie a subsection in the sequence) of whose sum is exactly K.


// brute force n^3
// prefix sum n^2
// using binary search  nlogn
//O(n) time and O(1) space ===>> sliding window 


//Sample input = [1 3 2 1 4 1 3 2 1 1 2]
// k=8
// sample answer 
// 2 5 
// 4 6 
// 5 9
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> solve(vector<int> arr,int k){

    vector<pair<int,int>> v;
    int i=0;
    int sum=0;
    int j=0;
    while(i<arr.size() && j<arr.size()){
        if(sum==k)  {
            v.push_back(make_pair(i,j-1));
            sum=sum-arr[i];
            i++;
            sum=sum+arr[j];
            j++;
        }else if(sum<k){
            sum=sum+arr[j];
            j++;
            
        }else if(sum>k){
            sum=sum-arr[i];
            i++;
        }
    }
    return v;
}

int main(){
    vector<int> arr={1,3,2,1,4,1,3,2,1,1,2};
    auto x=solve(arr,8);
    for(auto p :x){
        cout<<p.first<<","<<p.second<<endl;
    }
    return 0;
}