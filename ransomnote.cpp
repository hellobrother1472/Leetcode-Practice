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
        map<char, int> mm;
        map<char, int> mr;
        for (int i = 0; i < magazine.size(); i++)
        {
            if (mm.count(magazine[i]))
            {
                mm[magazine[i]]++;
            }
            else
            {
                mm[magazine[i]] = 1;
            }
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (mr.count(ransomNote[i]))
            {
                mr[ransomNote[i]]++;
            }
            else
            {
                mr[ransomNote[i]] = 1;
            }
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if(mr[ransomNote[i]] > mm[ransomNote[i]] ){
                return false;
            }
        }
        

        return true;
    }
};


class Solutiontwo {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26]={0};
        for(int i=0;i<magazine.size();i++){
            freq[int(magazine[i])-97]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            freq[int(ransomNote[i])-97]--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]<0)
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}