// Given a string, Write a function to replace all spaces in string with %20
// It is given that string has enough space in end to hold additional spaces

#include<bits/stdc++.h>
using namespace std;

void URL(char *s){
    int count=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' ') count++;
    }
    int add = 2*count;
    s[strlen(s)+add]='\0';

    for(int i=strlen(s)-1;i>0;i--){
        if(s[i]!=' ') s[i+add]=s[i];
        else{
            s[i+add]='0';
            s[i+add-1]='2';
            s[i+add-2]='%';
            add-=2;
        }
    }
}

int main(){
    char input[1000];
    cin.getline(input,1000);
    URL(input);
    cout<<input<<endl;
}