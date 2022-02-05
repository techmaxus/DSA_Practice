#include <iostream>
#include <vector>

using namespace std;

int main(){

    //initialising the vector
    vector<int> arr ={0,1,2,3,4};

    //adding new element in last in O(1) time
    arr.push_back(6);

    //size of vector is number of elements
    cout<<"Size : "<<arr.size()<<endl;

    //cpacity of vector is the space used in memory
    cout<<"Capacity : "<<arr.capacity()<<endl;

    //to remove last element in O(1) time
    arr.pop_back();

    cout<<"Size : "<<arr.size()<<endl;

    cout<<"Capacity : "<<arr.capacity()<<endl;

    cout<<"------------------------------------------------"<<endl;

    //printing all ement of array
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }

    cout<<"------------------------------------------------"<<endl;

    //fill constructor to fill a particular value for n elements
    // makes a array of 10 element with all values as 7
    vector<int> sample(10,7);
    for(int i=0;i<sample.size();i++){
        cout<<sample[i]<<endl;
    }

    return 0;
}