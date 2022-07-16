#include <iostream>
#include <vector>

using namespace std;

class Solution
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

// void display(vector<vector<int>> mat)
// {
//     for (int i = 0; i < mat.size(); i++)
//     {
//         cout<< mat[i];
//     }
// }

int main()
{

    vector<vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    Solution s;
    // display(s.matrixReshape(a, 1, 8));
    return 0;
}