#include <bits/stdc++.h>
using namespace std;

// Logic for this approach is explained in second class below
class Solution
{
public:
    string reverse(string s)
    {
        string ans = "";
        for (int i = s.size() - 1; i >= 0; i--)
        {
            ans += s[i];
        }
        return ans;
    }
    string frequencySort(string s)
    {
        string ans = "";
        map<char, int> firstmap;
        int strlen = s.length();
        for (int i = 0; i < strlen; i++)
        {
            firstmap[s[i]]++;
        }
        map<int, string> secondMap;
        for (auto i : firstmap)
        {
            secondMap[i.second] += i.first;
        }
        for (auto i : secondMap)
        {
            cout << i.first << " " << i.second << endl;
        }
        // vector<string>sv(s.length(),"");
        for (auto i : secondMap)
        {
            for (int k = 0; k < i.second.size(); k++)
            {
                for (int j = 0; j < i.first; j++)
                {
                    ans += i.second[k];
                }
            }
        }
        ans = reverse(ans);
        return ans;
    }
};

// Without using reverse function, by iterating map in backward direction
class Solution
{
public:
    string frequencySort(string s)
    {
        string ans = "";
        map<char, int> firstmap;
        int strlen = s.length();
        // Firstly recording total number of times an element is repeating
        for (int i = 0; i < strlen; i++)
        {
            firstmap[s[i]]++;
        }
        // Then by making the ordered map of int and string so that I can store the elements with same frequency at same place and map the elements by frequency in sorted form (as I am using ordered map)
        map<int, string> secondMap;
        for (auto i : firstmap)
        {
            secondMap[i.second] += i.first;
        }
        // It looks like O(n^3) but it's O(n). Just using above data for adding to the answer.
        for (auto i = secondMap.rbegin(); i != secondMap.rend(); i++)
        {
            for (int k = 0; k < i->second.size(); k++)
            {
                for (int j = 0; j < i->first; j++)
                {
                    ans += i->second[k];
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}