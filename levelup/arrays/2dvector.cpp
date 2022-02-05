#include <iostream>
#include <vector>

using namespace std;

int main(){

    //initialising the 2d vector vector
    vector<vector<int>> arr =
        {{1,2,3},
        {4,5,6,7,8},
        {9,10}};

    //printing the array
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<"\t";
        }cout<<endl;
    }
    cout<<"-------------------------------------------"<<endl;

    //use of for each loop
    for(vector<int>a : arr){
        for(int x : a){
            cout<<x<<"\t";
        }cout<<endl;
    }


    return 0;
}