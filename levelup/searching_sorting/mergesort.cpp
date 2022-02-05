// mergesort 
// make 2 recursive calls to get 2 sorted subarray
// merge 2 sorted arrays to make single sorted arrays

// base case 1 element

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &array,int s ,int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;

    vector<int> temp;

    while(i<=m and j<=e){
        if(array[i]<array[j]){
            temp.push_back(array[i]);
            i++;
        }
        else{
            temp.push_back(array[j]);
            j++;
        }
    }
    //copy remaining element from first part
    while(i<=m) temp.push_back(array[i++]);

    //copy element from other array
    while(j<=e) temp.push_back(array[j++]);

    //copy back elemnet from temp to original
    int k=0;
    for(int idx=s;idx<=e;idx++){
        array[idx]=temp[k++];
    }

    return;

}

void mergesort(vector<int> &array,int s, int e){
    //base case
    if(s>=e)    return;
    //reccursive case
    int mid =(s+e)/2;
    mergesort(array,s,mid);
    mergesort(array,mid+1,e);
    
    return merge(array,s,e);
    
}

int main(){

    vector<int> arr={10,5,2,0,7,6,4};

    int s =0;
    int e= arr.size()-1;
    mergesort(arr,s,e);
    for(int x : arr){
        cout<<x<<",";

    }
}