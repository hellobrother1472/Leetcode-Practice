#include <iostream>
#include <map>
#include <string>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
            return false;
        }

        map<char,int> m;

        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            if(m[t[i]] < 1){
                return false;
            }
            else{
                m[t[i]]--;
            }
        }
        
        return true;
        
    }
};

int main(){
    

    return 0;
}