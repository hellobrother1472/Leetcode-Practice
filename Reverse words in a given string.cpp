#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string input) 
    { 
        // code here 
        string s = "";
        vector<string>v;
        for(int i = 0 ; i < input.size(); i++){
            if(input[i] == '.'){
                v.push_back(s);
                s = "";
                continue;
            }
            
            s+= input[i];
        }
        v.push_back(s);
        
        reverse(v.begin(),v.end());
        
        input = "";
        
        for(int i = 0 ; i < v.size(); i++){
            input+= v[i];
            if(i != v.size()-1) input+= '.';
        }
        
        return input;
        
    } 
};

int main(){

    return 0;
}