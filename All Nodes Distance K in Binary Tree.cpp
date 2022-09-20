#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void assignParent(map<TreeNode *, TreeNode *> &m, TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        if (root->left)
        {
            m[root->left] = root;
        }
        if (root->right)
        {
            m[root->right] = root;
        }
        assignParent(m, root->left);
        assignParent(m, root->right);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        map<TreeNode *, TreeNode *> m;
        // Assigning the parents to the node.
        assignParent(m, root);

        // taking the radial step in all direction one step at a time and visited array is taking care of what node we already visited.
        int distance = 0;
        queue<TreeNode *> q;
        vector<int> visited;
        q.push(target);
        while (distance < k)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                visited.push_back(curr->val);
                q.pop();
                // Left
                if (curr->left && !count(visited.begin(), visited.end(), curr->left->val))
                {
                    q.push(curr->left);
                }
                // Right
                if (curr->right && !count(visited.begin(), visited.end(), curr->right->val))
                {
                    q.push(curr->right);
                }
                // top
                if (m[curr] && !count(visited.begin(), visited.end(), m[curr]->val))
                {
                    q.push(m[curr]);
                }
            }

            distance++;
            if (distance == k)
            {
                break;
            }
        }
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};

// Using map instead of visited vector
class Solution
{
public:
    void assignParent(map<TreeNode *, TreeNode *> &m, TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        if (root->left)
        {
            m[root->left] = root;
        }
        if (root->right)
        {
            m[root->right] = root;
        }
        assignParent(m, root->left);
        assignParent(m, root->right);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        map<TreeNode *, TreeNode *> m;
        // Assigning the parents to the node.
        assignParent(m, root);

        // taking the radial step in all direction one step at a time and visited array is taking care of what node we already visited.
        int distance = 0;
        queue<TreeNode *> q;
        // vector<int>visited;
        map<TreeNode *, bool> visited;
        q.push(target);
        while (distance < k)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                visited[curr] = true;
                q.pop();
                // Left
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

            distance++;
            if (distance == k)
            {
                break;
            }
        }
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};

// Reccursive Solution
// Explanation link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/1126885/Recursion-time%3A-O(N)-or-memory%3A-O(N)

// Basically we are finding the root and returning 1 if we got the root. When we got the root we perform operation to get all value below it and return 1 (or distance from the target) and if parent get 1(or distance from the target)  from any child the it will perform operation to get elements at opposite node with desired distance and returns the distance+1 to it's parent (which is distance of parent from the target).
class Solution
{
public:
    std::vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        std::vector<int> res;

        distanceK(root, target, K, res);

        return res;
    }

private:
    int distanceK(TreeNode *node, TreeNode *target, int K, std::vector<int> &res)
    {
        if (node == nullptr)
        {
            return 0;
        }
        if (node == target)
        { // found the target for the current subtree
            traverseSubtree(node, K, res);
            return 1;
        }
        int distLeft = distanceK(node->left, target, K, res); // distance to target in the left subtree

        if (distLeft != 0)
        {
            if (distLeft == K)
            {
                res.push_back(node->val);
            }
            else if (distLeft < K)
            {
                traverseSubtree(node->right, K - distLeft - 1, res); // visit the right subtree looking for nodes at a given distance
            }
            return distLeft + 1; //  return distance to target + 1
        }
        int distRight = distanceK(node->right, target, K, res); // distance to target in the right subtree

        if (distRight != 0)
        {
            if (distRight == K)
            {
                res.push_back(node->val);
            }
            else if (distRight < K)
            {
                traverseSubtree(node->left, K - distRight - 1, res); // visit the left subtree looking for nodes at a given distance
            }
            return distRight + 1; //  return distance to target + 1
        }
        return 0; // if reached this place, then there is no target in the current subtree
    }

    void traverseSubtree(TreeNode *node, int K, std::vector<int> &res)
    {
        if (node == nullptr)
        {
            return;
        }
        if (K == 0)
        { // found a node at a given distance
            res.push_back(node->val);
            return;
        }
        traverseSubtree(node->left, K - 1, res);  // go down until we find a node at a distance of K
        traverseSubtree(node->right, K - 1, res); // (if the depth of the subtree allows us to do this)
    }
};

int main()
{

    return 0;
}