#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

// class Solution
// {
// public:
// bool isValidSudoku(vector<vector<char>> &board)
// {
//     // 48 < i < 58 || i == 46  -48
//     vector<int> ht(10, 0);

//     // fill(ht.begin(),ht.end(),0);

//     for (int i = 0; i < board.size(); i++) // for rows
//     {
//         for (int j = 0; j < board[0].size(); j++)
//         {
//             if (48 < int(board[i][j]) < 58 || 0 < board[i][j] < 10 || int(board[i][j]) == 46)
//             {
//                 if (48 < int(board[i][j]) < 58)
//                 {
//                     ht[int(board[i][j]) - 48]++;
//                 }
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         for (int k = 0; k < 10; k++)
//         {
//             if (ht[k] > 1)
//             {
//                 return false;
//             }
//         }

//         fill(ht.begin(), ht.end(), 0);
//     }

//     for (int i = 0; i < board[0].size(); i++) // for columns
//     {
//         for (int j = 0; j < board.size(); j++)
//         {
//             if (48 < int(board[j][i]) < 58 || 0 < board[j][i] < 10 || int(board[j][i]) == 46)
//             {
//                 if (48 < int(board[j][i]) < 58)
//                 {
//                     ht[int(board[j][i]) - 48]++;
//                 }
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         for (int k = 0; k < 10; k++)
//         {
//             if (ht[k] > 1)
//             {
//                 return false;
//             }
//         }

//         fill(ht.begin(), ht.end(), 0);
//     }

//     for (int a = 3; a < 10; a += 3)
//     {
//         for (int i = a - 3; i < a; i++)
//         {
//             for (int j = a; j < a - 3; j++)
//             {
//                 if (48 < int(board[j][i]) < 58 || 0 < board[j][i] < 10 || int(board[j][i]) == 46)
//                 {
//                     if (48 < int(board[j][i]) < 58)
//                     {
//                         ht[int(board[j][i]) - 48]++;
//                     }
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }

//             for (int k = 0; k < 10; k++)
//             {
//                 if (ht[k] > 1)
//                 {
//                     return false;
//                 }
//             }

//             fill(ht.begin(), ht.end(), 0);
//         }
//     }

//     return true;

// }

// };

// I don't know why the above code is not working

// Here is the correct code

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // since we have to verify that each element is appears once or not... for that purpose here we use
        // vector of sets since set stores only unique entries
        vector<set<int>> rows(9), cols(9), blocks(9);

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // if board[i][j] entry is '.' then we just continue as we only care about the duplicate values
                if (board[i][j] == '.')
                {
                    continue;
                }

                int curr = board[i][j]; // we can get the value at given index to check that if it is already
                // present in set or not

                // here our count function returns 1 if value is already present in row or column or block otherwise it will return 0

                // for block try this formula using pen and paper you will get it..
                if (rows[i].count(curr) || cols[j].count(curr) ||
                    blocks[(i / 3) * 3 + j / 3].count(curr))
                {
                    return false; // we return false because the value currently we have is already present in set
                }
                // if we don't found the value then after that we must enter this value in our set
                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[(i / 3 * 3) + j / 3].insert(curr);
            }
        }
        return true; // after loop finishes our control reaches here that means our sudoko is valid...
    }
};

int main()
{

    return 0;
}