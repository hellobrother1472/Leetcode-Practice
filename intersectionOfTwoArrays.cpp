#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Brut Force Meathod (Runtime error)
class Solution
{
public:
    vector<int> intersect(vector<int> &a, vector<int> &b)
    {
        vector<int> c;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                if (a[i] == b[j])
                {
                    c.push_back(a[i]);
                    i++;
                }
            }
        }
        return c;
    }
};

// Using Mapping
class Solution2
{
public:
    vector<int> intersect(vector<int> &a, vector<int> &b)
    {
        vector<int> c;
        map<int, int> forA;
        map<int, int> forB;
        int prev = -555;
        for (int i = 0; i < a.size(); i++)
        {
            forA[a[i]]++;
        }

        for (int i = 0; i < b.size(); i++)
        {
            forB[b[i]]++;
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != prev)
            {
                if ((forA[a[i]] - forB[a[i]]) < forA[a[i]])
                {
                    prev = a[i];
                    int sameNum;

                    if (forA[a[i]] >= forB[a[i]])
                    {
                        sameNum = forA[a[i]] - abs(forA[a[i]] - forB[a[i]]);
                    }
                    else
                    {
                        sameNum = forB[a[i]] - abs(forA[a[i]] - forB[a[i]]);
                    }

                    for (int j = 0; j < sameNum; j++)
                    {
                        c.push_back(a[i]);
                    }
                }
            }
            else
            {
                continue;
            }
        }

        return c;
    }
};

// Another Way of using Mapping
class Solution3
{
public:
    vector<int> intersect(vector<int> &v1, vector<int> &v2)
    {
        vector<int> ans;
        map<int, int> m;

        for (int i = 0; i < v1.size(); i++)
        {

            m[v1[i]]++;
        }
        for (int i = 0; i < v2.size(); i++)
        {
            if (m[v2[i]] != 0)
            {
                ans.push_back(v2[i]);
                m[v2[i]]--;
            }
        }
        return ans;
    }
};

// Using Two Pointer Method
class Solution4
{
public:
    vector<int> intersect(vector<int> &a, vector<int> &b)
    {
        int j = 0;
        vector<int> intersection;

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[j])
            {
                j++;
                i--;
            }
            else
            {
                intersection.push_back(a[i]);

                b[j] = -1;
                j = 0;
            }

            if (j == b.size())
            {
                j = 0;
                i++;
            }
        }
        return intersection;
    }
};

int main()
{

    return 0;
}