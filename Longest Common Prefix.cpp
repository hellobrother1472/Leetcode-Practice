#include <bits/stdc++.h>
using namespace std;

// In this approach I am finding the common substring, like starting from 0 and 1 after getting common substring I am updating it real time and then comparing the new st's which are comming to the next, and at last I will get the ans. 
class Solution {
public:

    string findCommonSubstring(string one, string two){ // function to find common prefix between two
        string st = ""; 
        int i = 0, j = 0;
        while(i< one.length() && j < two.length()){
            if(one[i] == two[j]){ // If equal then add to st
                st += one[i];
                i++;
                j++;
            }
            else{ // here I am breaking because I want prefix, so until I get same I will store otherwise I will just break it and return the value which I get till now.
                break;
            }
        }
        return st;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n <= 1) return strs[0];
        string st = strs[0]; // starting from first value
        int i = 0, j = 0;
        for(int k = 1; k<n;k++){ 
            if(st == ""){
                return "";
            }
            st = findCommonSubstring(st,strs[k]); // Real time updating.
        }
        return st;
    }
};

int main(){
    

    return 0;
}