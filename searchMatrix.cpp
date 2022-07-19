#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix[0][0] > target)
        {
            return false;
        }

        int row;

        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] > target)
            {
                row = i - 1;
                break;
            }
            else if (matrix[i][0] == target)
            {
                return true;
            }
            else
            {
                if (i == matrix.size() - 1)
                {
                    row = i;
                }
                else
                {
                    continue;
                }
            }
        }

        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (matrix[row][i] == target)
            {
                return true;
            }
        }

        return false;
    }
};

class Solution2
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix.size() == 1)
            {
                for (int k = 0; k < matrix[0].size(); k++)
                {
                    if (matrix[i][k] == target)
                    {
                        return true;
                    }
                }
            }

            if ((i + 1) < matrix.size() && target <= matrix[i + 1][0])
            {
                if (target == matrix[i + 1][0])
                {
                    return true;
                }
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    if (matrix[i][j] == target)
                    {
                        return true;
                    }
                }
            }

            if (i == (matrix.size() - 1))
            {
                for (int t = 0; t < matrix[0].size(); t++)
                {
                    if (matrix[i][t] == target)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}