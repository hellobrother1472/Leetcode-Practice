#include <bits/stdc++.h>
using namespace std;

// To solve the problem the solution is to try the values between 1-9 which is valid and try it on the empty place and move forward.
// To do this we are using reccursion as we try every single possiblility.
// In the answer we have to manupilate the board itself.

// Step 1- If the current element is not empty then find the next empty element.

// Step 2- Now that we got that element we will run for loop to try every single number from 1-9 which is valid. If it is valid then make that change in the board and call reccursively for further. So if the we got answer we will return true (as we are not manipulating the board as it is the answer). If we thier is no value which is valid from 1-9 then return false.

// So at last as we got true we backtrack without manipulating the board and we got our answer.

class Solution
{
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c) // vertical checking
                return false;

            if (board[row][i] == c) // Horizontal checking
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) // checking in box
                return false;
        }
        return true;
    }

    bool findSol(int row, int col, vector<vector<char>> &board)
    {
        if (board[row][col] != '.') // Finding the next empty
        {
            bool brek = false;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] == '.')
                    {
                        brek = true;
                        row = i;
                        col = j;
                        break;
                    }
                }
                if (brek)
                    break;
            }
        }
        if (board[row][col] == '.')
        {
            for (char c = '1'; c <= '9'; c++) // for loop trying every single value
            {
                if (isValid(board, row, col, c)) // If valid then perform reccursion
                {
                    board[row][col] = c;
                    if (findSol(row, col, board)) // Keep the manipulation if the solution is true
                        return true;
                    else // Otherwise make board as previous and move further.
                        board[row][col] = '.';
                }
            }
            return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        findSol(0, 0, board);
    }
};

// This is more easy to understand approach, here we are not searching seperately we are doing operation while iteration only.
class Solution
{
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)
                return false;

            if (board[row][i] == c)
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    bool findSol(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if (findSol(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        findSol(board);
    }
};

int main()
{

    return 0;
}