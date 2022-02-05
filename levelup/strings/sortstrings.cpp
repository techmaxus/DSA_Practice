// Given a list of 'n' strings S0,S1,S2,S3,......Sn-1 ,each constisting of digits and spaces,
// the number of spaces is the same for each entry, the goal is to implement a variation of 
// a sort command. None of the strings contains consecutive spaces. Also, no string starts 
// with a space nor ends with it. Spaces are used to divide strings into column which can be 
// used as keys in comparison.

// parameters
// key : column to be used as key (left most is 1)
// reversed : boolean indicating whether to reverse result
// comparison-type: either lexicographic or numeric

// sample input
// 3
// 92 022 
// 82 12 
// 77 13
// 2 false numeric

// sample output
// 82 12 
// 77 13
// 92 022

#include<bits/stdc++>
using namespace std;

string extractkey(string str,int key){

    char *s=strtok((char *)str.c_str()," ");
    while(key>1){
        s=strtok(NULL," ");
        key--;
    }
    return (string)s;
}

int main(){
    int n;
    cin>>n;

    cin.get(); //consume the enter

    string temp;
    vector<string> v;
    for(int i=0;i<n;i++){

    }

    int key;
    string reversal,ordering;
    cin>>key>>reversal>>odering;

    //extracting key
    vector<pair<string,string>> vp
    for(int i =0;i<n;i++){
        vp.push_back(make_pair(v[i],extractkey(v[i],key)))
    }

    //sorting
    
}