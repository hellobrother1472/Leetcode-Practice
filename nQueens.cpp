#include <iostream>
#include <vector>
#include <string>

using namespace std;

// This solution have a very high time complexity.
class Solution
{

private:
    bool isSafe(int row, int col, vector<string> board, int n)
    {
        int dupRow = row;
        int dupCol = col;

        // Checking Horizontally
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }

        // Checking upper diagonal
        row = dupRow;
        col = dupCol;
        while (col >= 0 && row >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }

        // Checking lower diagonal
        row = dupRow;
        col = dupCol;
        while (col >= 0 && row < n)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }

        return true;
    }

public:
    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        solve(0, ans, board, n);

        return ans;
    }
};

int main()
{

    return 0;
}