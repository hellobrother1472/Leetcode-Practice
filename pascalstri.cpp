#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        vector<int> comp;

        for (int row = 1; row <= numRows; row++)
        {
            for (int i = 0; i <= row - 1; i++)
            {
                if (i == 0 || i == row - 1)
                {
                    comp.push_back(1);
                }
                else
                {
                    comp[i] = ans[row - 2][i] + ans[row - 2][i - 1];
                }
            }
            ans.push_back(comp);
            comp.clear();
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;

        int k = 0;

        for (int i = 0; i < numRows; i++)
        {

            vector<int> a(i + 1);
            a[0] = 1;
            a[i] = 1;
            for (int j = 1; j < i; j++)
            {
                a[j] = prev[k] + prev[k + 1];

                k++;
            }
            prev = a;
            ans.push_back(a);
            k = 0;
        }

        return ans;
    }
};

int main()
{

    return 0;
}