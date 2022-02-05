// Minimum Difference

// Implement a function that takes in two non-empty arrays of integers, 
// finds the pair of numbers (one from each array) who absolute difference 
// is closest to zero, and returns a pair containing these two numbers,
// with the first number from array. Only one such pair will exist for the test.

// Input

// Array1 = [23, 5, 10, 17, 30]
// Array2 = [26, 134, 135, 14, 19]
// Output

// 17,19

//O( mlogm + nlogn)
#include<bits/stdc++.h>

using namespace std;

pair<int,int> solve(vector<int> arr1 , vector<int>arr2){
    //sorting the both arrays
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    int mindif=INT_MAX;
    pair<int,int> p={0,0};
    //while loop of max order m+n
    int i=0;
    int j=0;
    while(i<arr1.size() && j<arr2.size()){
        //changing the value of min difference if current difference is less than mindif
        if(abs(arr1[i]-arr2[j])<mindif){
            mindif=abs(arr1[i]-arr2[j]);
            p.first=arr1[i];
            p.second=arr2[j];
        }
        //incrementing the smaller value in order to reduce differnce
        if(arr1[i]<arr2[j]) i++;
        else if(arr1[i]>arr2[j]) j++;
        else return p;
    }

    return p;
}

int main(){

    vector<int> arr1 ={23, 5, 10, 17, 30};
    vector<int> arr2 ={26, 134, 135, 14, 19};
    auto p =solve(arr1,arr2);
    cout<<p.first<<","<<p.second<<endl;
    return 0;
}

