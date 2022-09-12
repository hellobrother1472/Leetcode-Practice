#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>

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

// The logic is that we have to normally do the levelorder traversal but along with that we just have to take care of the zig-zag pattern which requires the adding and removing elements from diffrent sides as per condition for that I used deque
class Solution1
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }

        deque<TreeNode *> q;
        q.push_back(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            if (ans.size() % 2 == 0)
            {
                for (int i = 0; i < size; i++)
                {
                    TreeNode *node = q.back();
                    q.pop_back();
                    if (node->left != NULL)
                        q.push_front(node->left);
                    if (node->right != NULL)
                        q.push_front(node->right);
                    level.push_back(node->val);
                }
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    TreeNode *node = q.front();
                    q.pop_front();
                    if (node->right != NULL)
                        q.push_back(node->right);
                    if (node->left != NULL)
                        q.push_back(node->left);
                    level.push_back(node->val);
                }
            }

            ans.push_back(level);
        }
        return ans;
    }
};

// The meathod is short but it takes time
class Solution2
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }

        deque<TreeNode *> q;
        q.push_back(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                if (ans.size() % 2 == 0)
                {
                    TreeNode *node = q.back();
                    q.pop_back();
                    if (node->left != NULL)
                        q.push_front(node->left);
                    if (node->right != NULL)
                        q.push_front(node->right);
                    level.push_back(node->val);
                }
                else
                {
                    TreeNode *node = q.front();
                    q.pop_front();
                    if (node->right != NULL)
                        q.push_back(node->right);
                    if (node->left != NULL)
                        q.push_back(node->left);
                    level.push_back(node->val);
                }
            }

            ans.push_back(level);
        }
        return ans;
    }
};

// Just make the normal level order and after that seperately reverse the array on the required index
class Solution
{
public:
    void helper(TreeNode *root, vector<vector<int>> &res, int level)
    {
        if (!root)
            return;
        if (level >= res.size())
            res.push_back({});
        res[level].push_back(root->val);
        helper(root->left, res, level + 1);
        helper(root->right, res, level + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        helper(root, res, 0);
        for (int i = 1; i < res.size(); i = i + 2)
        {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};

// Just using queue and reversing on the spot on the basis of condition
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);      // Push the root to the queue
        while (!q.empty()) // Until the queue is empty traverse
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                level.push_back(node->val);
            }
            if(ans.size() % 2 != 0){
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);
        }
        return ans;
    }
};

// Using the queue and just inserting in the level array on the spot accordingly on the basis of flag
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);      // Push the root to the queue
        bool leftToRight = true; // This is flag
        while (!q.empty()) // Until the queue is empty traverse
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                int index = leftToRight ? i : size-1-i;
                level.push_back(node->val);
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            if(ans.size() % 2 != 0){
                reverse(level.begin(), level.end());
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        return ans;
    }
};


int main()
{

    return 0;
}