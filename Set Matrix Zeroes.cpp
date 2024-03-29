#include <bits/stdc++.h>

using namespace std;

// Simply storing the i and j of the element at zero and making all the element having same i or j be zero in second iteration.
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        map<int, int> mi;
        map<int, int> mj;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    mi[i]++;
                    mj[j]++;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (mi[i] || mj[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

// Here the algo is with O(1) space. Taking the flag array inside the array as the first column and row iteself.
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool isCol = false;
        int R = matrix.size();
        int C = matrix[0].size();

        for (int i = 0; i < R; i++)
        {

            // Since first cell for both first row and first column is the same i.e. matrix[0][0]
            // We can use an additional variable for either the first row/column.
            // For this solution we are using an additional variable for the first column
            // and using matrix[0][0] for the first row.
            if (matrix[i][0] == 0)
                isCol = true;

            for (int j = 1; j < C; j++)
            {
                // If an element is zero, we set the first element of the corresponding row and column to 0
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Iterate over the array once again and using the first row and first column, update the elements.
        for (int i = 1; i < R; i++)
        {
            for (int j = 1; j < C; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // See if the first row needs to be set to zero as well
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < C; j++)
                matrix[0][j] = 0;
        }

        // See if the first column needs to be set to zero as well
        if (isCol)
        {
            for (int i = 0; i < R; i++)
                matrix[i][0] = 0;
        }
    }
};

int main()
{

    return 0;
}