#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> m;
        
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if(m[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    

    return 0;
}