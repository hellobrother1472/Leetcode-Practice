#include <iostream>
#include <vector>
#include <map>
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

class Solution
{
public:
    //     Find the target in the tree
    //     make the tree two way
    //     and do radial traversal
    //     On every completion of for loop one unit of time increases

    TreeNode *target;
    void findTarget(TreeNode *curr, int start)
    {
        if (curr == NULL)
        {
            return;
        }
        if (curr->val == start)
        {
            target = curr;
            return;
        }
        findTarget(curr->left, start);
        findTarget(curr->right, start);
    }

    void makeTwoWay(TreeNode *root, map<TreeNode *, TreeNode *> &m)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        if (root->left)
            m[root->left] = root;
        if (root->right)
            m[root->right] = root;

        makeTwoWay(root->left, m);
        makeTwoWay(root->right, m);
    }

    int amountOfTime(TreeNode *root, int start)
    {
        // Finding the target
        findTarget(root, start);

        // Making the tree two way
        map<TreeNode *, TreeNode *> m;
        makeTwoWay(root, m);

        // Calculating the time using radial traversal
        int time = 0;
        queue<TreeNode *> q;
        map<TreeNode *, bool> visited;
        q.push(target);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                visited[curr] = true;
                if (curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                }
                // Right
                if (curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                }
                // top
                if (m[curr] && !visited[m[curr]])
                {
                    q.push(m[curr]);
                }
            }
            time++;
        }
        return time - 1;
    }
};

int main()
{

    return 0;
}