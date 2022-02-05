//  https://leetcode.com/problems/longest-mountain-in-array/

// Take input a array of distinct integer return the length of longest mountain
// a mountain is a set of adjacent integer that are strictly increasing until 
// they reach a peak after which they are strictly decreasing
// Atleast 3 numbers are required to form a mountain

// complexity = O(2n)

#include<bits/stdc++.h>

using namespace std;
int solve(vector<int> arr){
    int max=0;
//for each element 
    for(int i=1 ;i<arr.size()-1;){
        //checking if the selected element is a peek
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            int localmax=1;
            int j=i;

            // Counting increasing element on left side of the peek
            while(j>0 && arr[j]>arr[j-1]){
                j--;
                localmax++;
            }

            // Counting decreasing element on right side of the peek
            while(i<arr.size()-1 && arr[i]>arr[i+1]){
                i++;
                localmax++;
            }

            // If the length of 
            if(localmax>=max) max=localmax;
        }
        else {
            i++;
        }
    }


    return max;
}


int main(){
    vector<int>arr ={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<solve(arr)<<endl;

    return 0;
}