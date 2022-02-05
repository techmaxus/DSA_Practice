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
int quickselect(vector<int> &array,int s, int e, int k){
    int p = partition(array,s,e);
    if(p==k) return array[p];
    else if(k<p)    return quickselect(array,s,p-1,k);
    else return quickselect(array,p+1,e,k);
       
}

int main(){

    vector<int> arr={10,5,2,0,7,6,4};

    int s =0;
    int e= arr.size()-1;
    int k;
    cin>>k;
    cout<<quickselect(arr,s,e,k);
  
}