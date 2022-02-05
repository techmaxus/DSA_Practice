//search element in rotated array in log n complecity
// so idea is to use binary search in rotated sorted array

#include <bits/stdc++.h>
using namespace std;

int searchrotated(vector<int> v,int target){
    int st=0;
    int end=v.size()-1;
    while(st<=end){
        int mid= (st+end)/2;
        // if val at mid is target
        if(v[mid]==target)  return mid;
        
        // to check for location of pivot

        // pivot in first half ==>arr[mid]<=arr[end]
        if(v[mid]<=v[end]){
            //target in second half which do not contain pivot
            if(target>v[mid] && target<=v[end]){
                st=mid+1;
            }
            // else target is in first half
            else{
                end=mid-1;
            }
        }

        // pivot in second half ==>arr[st]<=arr[mid]
        if(v[st]<=v[mid]){
            //target in first half which do not contain pivot
            if(target>=v[st] && target<v[mid]){
                end=mid-1;
            }
            // else target is in second half
            else{
                st=mid+1;
            }
        }
        
    }return -1;
}

int main(){
    vector<int> v={65,68,69,75,90,5,9,11,16,24,29,30,41};
    cout<<searchrotated(v,16)<<endl;
    return 0;
}