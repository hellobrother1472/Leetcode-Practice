#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> *root, int X)
{
    int ans = -1;
    while (root)
    {
        if (root->val < X)
        {
            if (root->val > ans)
                ans = root->val;
            root = root->right;
        }
        else
        {
            if (root->val == X)
                return X;
            root = root->left;
        }
    }
    return ans;
}

// Reccursive
int floorInBST(TreeNode<int> * root, int X)
{
    // Base condition
    if(root == NULL)
        return INT_MAX;
  
    if(root -> val == X)
        return root -> val;
  
    // If root -> data is greater than the 'X'
    if(root -> val > X)
        return floorInBST(root -> left, X);
  
    // Else, the floor may lie in right subtree or may be equal to the root
    int floorValue = floorInBST(root -> right, X);

    return (floorValue <= X) ? floorValue : root -> val;
}

int main()
{

    return 0;
}