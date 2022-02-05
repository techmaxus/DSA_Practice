//calculating square root of integers using binary search methodlogy

#include<bits/stdc++.h>

using namespace std;

int squareroot(int n){
    if(n<2) return n;
    int st=1;
    int end=n/2;
    int ans=0;
    while(st<=end){
        int mid=(st+end)/2;
        if(mid*mid==n)  return mid;
        else if(mid*mid>n) end=mid-1;
        else if(mid*mid<n){
            st=mid+1;
            ans=mid;
        } 
    }
    return ans;
}
int main(){

    cout<<squareroot(10);
    return 0;
}