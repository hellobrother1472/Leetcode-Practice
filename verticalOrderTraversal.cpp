#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // getting all the values with its col and row. Using multiset with row because to get the sorted value 
    void solve(int row, int col, map<int, map<int, multiset<int>>> &m, TreeNode *root)
    {
        if (root == NULL)
            return;

        m[col][row].insert(root->val);

        solve(row + 1, col - 1, m, root->left);
        solve(row + 1, col + 1, m, root->right);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> m;
        solve(0, 0, m, root);
        // After getting everything from the solve function we just put it in ans using iteration.
        for (auto i = m.begin(); i != m.end(); i++)
        {
            vector<int> res;
            for (auto j = i->second.begin(); j != i->second.end(); j++)
            {
                for (auto itr = j->second.begin(); itr != j->second.end(); itr++)
                {
                    res.push_back(*itr);
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};

// With insert function
class Solution
{
public:
    // getting all the values with its col and row. Using multiset with row because to get the sorted value 
    void solve(int row, int col, map<int, map<int, multiset<int>>> &m, TreeNode *root)
    {
        if (root == NULL)
            return;

        m[col][row].insert(root->val);

        solve(row + 1, col - 1, m, root->left);
        solve(row + 1, col + 1, m, root->right);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> m;
        solve(0, 0, m, root);
        // After getting everything from the solve function we just put it in ans using iteration.
        for (auto i = m.begin(); i != m.end(); i++)
        {
            vector<int> res;
            for (auto j = i->second.begin(); j != i->second.end(); j++)
            {
                res.insert(res.end(), j->second.begin(), j->second.end());
            }
            ans.push_back(res);
        }

        return ans;
    }
};

int main()
{

    return 0;
}