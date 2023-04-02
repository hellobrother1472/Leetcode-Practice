#include <bits/stdc++.h>
using namespace std;

// Using Heap solution
// First I am storing the frequency in map, then using pair ds I am putting the frequency and character in pair, frequency is made pair.first as heap sort on basis of pair.first.
// That just printing the elements on the top of heap (element with max frequency) and then poping.
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char,int> mp;
        for(int i= 0 ; i < s.size(); i++){
            mp[s[i]]++;
        }

        for(auto i = mp.begin(); i != mp.end(); i++){
            pair<int,char>p;
            p.first = i->second;
            p.second = i->first;

            maxHeap.push(p);
        }

        string ans = "";
        while(!maxHeap.empty()){
            for(int i = 0; i < maxHeap.top().first; i++) ans += maxHeap.top().second;
            maxHeap.pop();
        }
        return ans;
    }
};

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