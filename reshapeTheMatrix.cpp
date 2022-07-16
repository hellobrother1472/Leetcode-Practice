#include <iostream>
#include <vector>

using namespace std;

// Brut Force
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        vector<vector<int>> ans;
        vector<int> comp;
        int matSize = mat.size();
        int row = 0, col = 0;

        if ((mat[0].size() * matSize) != r * c)
        {
            return mat;
        }
        else
        {
            for (int i = 0; i < matSize; i++)
            {
                for (int j = 0; j < mat[0].size(); j++)
                {
                    if (col < c)
                    {
                        comp.push_back(mat[i][j]);
                        col++;
                    }
                    if (col == c)
                    {
                        row++;
                        col = 0;
                        ans.push_back(comp);
                        comp.clear();
                    }
                }
            }
        }

        return ans;
    }
};
// Another Way 1

class Solution4
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int n = mat.size(), m = mat[0].size();
        int all = n * m;
        if (all != r * c)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < all; i++)
        {
            ans[i / c][i % c] = mat[i / m][i % m];
        }
        return ans;
    }
};

// Another Way 2

class Solution2
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int n = mat.size(), m = mat[0].size(), k = 0;
        if (c * r != n * m)
            return mat;
        vector<vector<int>> ans;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                v.push_back(mat[i][j]);
                k++;
                if (k == c)
                {
                    k = 0;
                    ans.push_back(v);
                    v.clear();
                }
            }
        }
        return ans;
    }
};

class Solution3
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        vector<int> presol;
        vector<vector<int>> sol(r, vector<int>(c, 0));
        int a = 0, b = 0; // a = rows and b = column

        int n = mat.size(), m = mat[0].size(), k = 0;
        if (c * r != n * m)
        {
            return mat;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                presol.push_back(mat[i][j]);
            }
        }

        int iter = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (iter < presol.size())
                {
                    sol[i][j] = presol[iter];
                    iter++;
                }
            }
        }
        return sol;
    }
};

int main()
{

    return 0;
}