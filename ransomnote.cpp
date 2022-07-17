#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote == "")
        {
            return true;
        }

        if (magazine.size() < ransomNote.size())
        {
            return false;
        }

        map<char, int> map;

        for (int i = 0; i < magazine.size(); i++)
        {
            map[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (map[ransomNote[i]] < 1)
            {
                return false;
            }
            else
            {
                map[ransomNote[i]]--;
            }
        }

        return true;
    }
};


int main()
{

    return 0;
}