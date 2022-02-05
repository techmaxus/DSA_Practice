// Implement a function that returns a list of all occurrences of a given  substring inside a big string.
// Return empty vector if smaller string is not present inside bigger string.

// Sample Input

// string bigString = "I liked the movie, acting in movie was great!";
// string smallString = "movie"


// Sample Output
// 12, 29

#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    vector<int> result;
    int i=big.find(small);
    while(i!=-1){
        result.push_back(i);
        i=big.find(small,i+1);
    }
    return result;
}
int main(){
    vector<int> v= stringSearch("I liked the movie, acting in movie was great!","movie");
    for(auto u:v){
        cout<<u<<endl;
    }
}
