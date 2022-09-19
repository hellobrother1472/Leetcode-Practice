#include <iostream>
#include <vector>
#include <queue>
#include <utility>

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

// The idea is to give index to every node. such that we can subtract the indexes of first and last node to get the index. For giving index we are using the property of tree i.e.. for left child (2i+1) and for right child (2i+2). That's how we are giving the index. Now everything is fine, but the only problem is the overflow due to large numbers as an index. For tackling that we are taking i as i-min(min is the minimum index of the level). Such that we solved overflow problem. 


// In this approach I am storing the present indexes in the array according to their level and then traversing the array and getting the answer.
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        vector<vector<int>> arr;
        int ans = -1;
        queue<pair<TreeNode *, int>> q; // <Node,index>
        q.push({root, 1});

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            int min = q.front().second; // min of the present level

            // Level order
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front().first;
                int index = q.front().second;
                q.pop();
                if (node->left != NULL)
                    q.push({node->left, 2 * ((long long)index - min) + 1}); // Using formula (2(i-min)+1)
                if (node->right != NULL)
                    q.push({node->right, 2 * ((long long)index - min) + 2}); // Using formula (2(i-min)+2)
                level.push_back(index);  // pushing the index of every node
            }
            arr.push_back(level);
        }

        // Traversing and comparing for getting the ans.
        for (int i = 0; i < arr.size(); i++)
        {
            int val =(*(arr[i].end()-1) - *arr[i].begin())+1;
            if(val>ans){
                ans = val;
            }
        }

        return ans;
    }
};

// here we are taking first and second during the traversal and comparing after the end of for loop.
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int ans = -1;
        queue<pair<TreeNode *, int>> q; // Node,index
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            int min = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front().first;
                int index = q.front().second - min;
                q.pop();
                if (i == 0)
                    first = index;
                if (i == size - 1)
                    last = index;
                if (node->left)
                    q.push({node->left, (long long)index * 2 + 1});
                if (node->right)
                    q.push({node->right, (long long)index * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};

int main()
{

    return 0;
}