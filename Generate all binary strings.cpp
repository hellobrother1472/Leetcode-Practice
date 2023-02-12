#include <bits/stdc++.h>
using namespace std;

// just using reccursion with base case that if length becomes 3 then cout it. As the condition is that we should not have consecutive 1 so just add 0 and make all subsequence and for one if the present element is zero it means we are safe to add 1 otherwise not.

#include <string>
class Solution{
public:
    string temp = "";
    void func(int num, int i){
        if(i == num){
            cout << temp << " ";
            return;
        }
        temp += "0";
        func(num, i+1);
        temp.pop_back();
        if(temp.length() == 0 || temp[i-1] == '0'){
            temp += "1";
            func(num, i+1);
            temp.pop_back();
        }
    }
    void generateBinaryStrings(int& num){
        func(num,0);
    } 
};

int main(){
    
    return 0;
}