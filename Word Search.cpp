#include <bits/stdc++.h>
using namespace std;

// First I am finding the 0th index of the string in the matrix as soon as I got the zeroth index I am calling an helper
// In Helper function first I am storing the index in map so that their is no repetition
// Then find the next element by checking up, down, left and right and reccursion continue from that index further.
// If even one of them is true it means we got the answer return true.

// Step 1: Find the first character of the given string.

// Step 2: Start Backtracking in all four directions until we find all the letters of sequentially adjacent cells.

// Step 3: At the end, If we found our result then return true else return false.

// With using map matrix
class Solution
{
public:
    bool helper(int i, int j, int index, string word, vector<vector<char>> board, vector<vector<int>> &mp)
    {
        if (board[i][j] != word[index])
            return false;
        if (index >= word.length() - 1)
            return true;
        mp[i][j]++;
        bool up = false, down = false, left = false, right = false;
        if (i > 0 && mp[i - 1][j] == 0)
            up = helper(i - 1, j, index + 1, word, board, mp);
        if (i < board.size() - 1 && mp[i + 1][j] == 0)
            down = helper(i + 1, j, index + 1, word, board, mp);
        if (j > 0 && mp[i][j - 1] == 0)
            left = helper(i, j - 1, index + 1, word, board, mp);
        if (j < board[0].size() - 1 && mp[i][j + 1] == 0)
            right = helper(i, j + 1, index + 1, word, board, mp);

        mp[i][j]--;
        return up || down || left || right;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.size() * board[0].size() < word.length())
            return false;
        vector<vector<int>> mp(board.size(), vector<int>(board[0].size(), 0));
        int index = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (word[index] == board[i][j])
                {
                    bool res = helper(i, j, index, word, board, mp);
                    if (res)
                        return true;
                }
            }
        }
        return false;
    }
};

// Without using map matrix just altering and reseting the board itself.
class Solution
{
public:
    bool helper(int i, int j, int index, string word, vector<vector<char>>& board)
    {
        if (board[i][j] != word[index])
            return false;
        if (index >= word.length() - 1)
            return true;
        char c = board[i][j];
        board[i][j] = '!';
        bool up = false, down = false, left = false, right = false;
        if (i > 0)
            up = helper(i - 1, j, index + 1, word, board);
        if (i < board.size() - 1)
            down = helper(i + 1, j, index + 1, word, board);
        if (j > 0)
            left = helper(i, j - 1, index + 1, word, board);
        if (j < board[0].size() - 1)
            right = helper(i, j + 1, index + 1, word, board);

        board[i][j] = c;
        return up || down || left || right;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.size() * board[0].size() < word.length())
            return false;
        // vector<vector<int>(board.size(), vector<int>(board[0].size(), 0));
        int index = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (word[index] == board[i][j])
                {
                    bool res = helper(i, j, index, word, board);
                    if (res)
                        return true;
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