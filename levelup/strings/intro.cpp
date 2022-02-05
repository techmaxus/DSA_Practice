#include <iostream>
#include <string>
#include<vector>

using namespace std;

int main(){
    string s;
    getline(cin,s,'.');
    cout<<s<<endl;
    for(char ch : s){
    cout<<ch<<endl;}

    // s.find(word)
    cout<<s.find("word")<<endl;
    cout<<s.find("no")<<endl;


}
