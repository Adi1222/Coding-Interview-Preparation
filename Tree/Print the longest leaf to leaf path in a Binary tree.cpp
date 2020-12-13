#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// This Problem uses the concepts of diameter of tree, calculation of height of a tree, printing the largest path from root to leaf of a tree

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int height(node *root, int &ans, node *(&k))
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left, ans, k);
    int right = height(root->right, ans, k);

    // for each node updations

    if (left + right + 1 > ans)
    {
        ans = max(ans, left + right + 1);

        k = root; // storing the node also which is included in the diameter of tree i.e the root of the diameter of the tree
    }

    return 1 + max(left, right);
}

vector<int> longestPath(node *root)
{
    if (!root)
    {
        return {};
    }

    vector<int> L = longestPath(root->left);
    vector<int> R = longestPath(root->right);

    if (L.size() > R.size())
    {
        L.push_back(root->data);
    }
    else
    {
        R.push_back(root->data);
    }

    return (L.size() > R.size() ? L : R);
}

void diameter(node *root)
{
    if (!root)
    {
        return;
    }

    int ans = INT_MIN;
    node *k;

    int temp = height(root, ans, k);

    // now considering k as the root , print the longest path from root to leaf (left subtree and right subtree both)

    vector<int> l = longestPath(k->left);

    vector<int> r = longestPath(k->right);

    // printing logic

    for (int i = 0; i < l.size(); i++)
    {
        cout << l[i] << " ";
    }

    cout << k->data << " ";

    for (int i = r.size() - 1; i >= 0; i--)
    {
        cout << r[i] << " ";
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);
    root->left->left->right = new node(8);
    root->left->left->right->left = new node(9);

    diameter(root);

    return 0;
}