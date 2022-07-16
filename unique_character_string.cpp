#include <iostream>
#include <string>
#include <map>

using namespace std;

// wrong Answer I don't know why

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         map<char,int> m;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if(m.count(s[i])){
//                 m[s[i]] ++;
//             }
//             else{
//                 m[s[i]] = 1;
//             }
//         }

//         for (int i = 0; i <= m.size(); i++)
//         {
//             if(m[s[i]] == 1 ){
//                 return s.find(s[i]);
//             }
//         }

//         return -1;
//     }
// };

// This is the correct solution

class Solution
{
public:
    int firstUniqChar(string s)
    {

        int count[26] = {0};
        for (int i = 0; i < s.length(); i++)
            count[s[i] - 'a']++;

        for (int i = 0; i < s.length(); i++)
            if (count[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};

int main()
{
    string a = "dddccdbba";
    cout << a.size();
    return 0;
}