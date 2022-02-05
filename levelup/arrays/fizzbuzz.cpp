// FizzBuzz Test
// Write a fizzbuzz function that returns a vector<string> with the numbers from 1 to n with the following restrictions:

// for multiples of 3 store "Fizz" instead of the number
// for multiples of 5 store "Buzz" instead of the number
// for numbers which are multiples of both 3 and 5 store "FizzBuzz"
// You may use the std::to_string(number) method to convert a number into a string.

// Example

// fizzbuzz(15) == {
// "1", "2", "Fizz", "4", "Buzz",
// "Fizz", "7", "8", "Fizz", "Buzz",
// "11", "Fizz", "13", "14", "FizzBuzz"
// }

// Hint
// Expected Time Complexity O(N)
// Expected Space Complexity O(1)



#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> fizzbuzz(int n){
   vector<string> result ={};
   for(int i =1;i<=n;i++){
       if(i%3==0 &&i%5==0)  result.push_back("FizzBuzz");
       else if(i%5==0) result.push_back("Buzz");
       else if(i%3==0) result.push_back("Fizz");
       else result.push_back(std::to_string(i));
   }

   return result;
}

int main(){
    vector<string> answer =fizzbuzz(15);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}