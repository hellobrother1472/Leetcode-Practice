#include <iostream>
#include <map>
#include <string>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> ms;
        map<char, int> mt;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (ms.count(s[i]))
            {
                ms[s[i]]++;
            }
            else
            {
                ms[s[i]] = 1;
            }
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (mt.count(t[i]))
            {
                mt[t[i]]++;
            }
            else
            {
                mt[t[i]] = 1;
            }
        }

        for (int i = 0; i < t.size(); i++)
        {
            if(mt[t[i]] != ms[t[i]] ){
                return false;
            }
        }
        

        return true;
    }
};

int main(){
    

    return 0;
}