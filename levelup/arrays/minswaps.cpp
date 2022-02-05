//  https://practice.geeksforgeeks.org/problems/minimum-swaps/1

// Given an array of N integer find the minimum number of swaps needed to make the array as sorted

// Finding correct position of each element

#include<bits/stdc++.h>
using namespace std;



int solve(vector<int> arr){
    int n=arr.size();
    // pair of element value and old index
    pair<int,int> a[n];

    //storing data for each pair
    for(int i =0 ;i<n;i++){
        a[i].first=arr[i];
        a[i].second=i;
    }

    // sorting the array according to the values
    sort(a,a+n);

    // building  the main logic---------------------------
        //making a bool for cyclic swaps
        vector<bool> visited(n,false);
        int ans=0;
        //iterating over whole array of pair
        for(int i=0;i<n;i++){

            // if the element has been visited or is positioned correctly
            if(visited[i]==true or a[i].second==i){
                continue;
            }

            //visiting the element for first time
            int node = i;
            int cycle_element =0;
            while(visited[node]==false){
                visited[node]=true;
                cycle_element++;
                node=a[node].second;
            }
            ans+=cycle_element-1;
        }





    return ans;
}

int main(){
    vector<int> arr ={5,4,3,2,1};
    auto p =solve(arr);
    cout<<p<<endl;
    return 0; 
}