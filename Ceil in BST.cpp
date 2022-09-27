#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    vector<int> d;
    int ans;
    // Your code here
    while (root)
    {
        if (root->data > input)
        {
            ans = root->data;
            root = root->left;
        }
        else
        {
            if (root->data == input)
                return root->data;

            root = root->right;
        }
    }
    // sort(d.begin(), d.end());
    return d[0];
}

int main()
{

    return 0;
}