//divide and conquer
//choose the pivot element
//partititon the array in true order
// recursively sort left and right part
 

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &array,int s, int e){
    int i=s-1;
    for(int j=s;j<e;j++){
        if(array[j]<array[e]){
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[e]);
    return i+1;
    
}
void quicksort(vector<int> &array,int s, int e){
    if(s>=e) return;
    int p = partition(array,s,e);
    
    quicksort(array,s,p-1);
    quicksort(array,p+1,e);
    return;    
}

int main(){

    vector<int> arr={10,5,2,0,7,6,4};

    int s =0;
    int e= arr.size()-1;
    quicksort(arr,s,e);
    for(int x : arr){
        cout<<x<<",";
    }
}