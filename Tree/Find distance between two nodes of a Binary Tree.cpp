#include <iostream>
using namespace std;

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

node *LCA(node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    node *L = LCA(root->left, n1, n2);
    node *R = LCA(root->right, n1, n2);

    if (L && R)
    {
        return root;
    }

    return (L != NULL) ? L : R;
}

int findLevel(node *root, int k, int level = 0)
{
    if (root == NULL)
    {
        return -1; // i.e the node which we are looking for is not present in the tree
    }

    if (root->data == k)
    {
        // if we found the node
        return level;
    }

    // we have to search the node in left and right subtree

    int left = findLevel(root->left, k, level + 1);

    if (left == -1) // i.e we didn't find the node in the left subtree then go for searching in the right subtree
    {
        return findLevel(root->right, k, level + 1); // return is used to return the level directly if found in the right subtree
    }

    return left; // if node found in the left subtree
}

int findDistance(node *root, int n1, int n2)
{
    node *lca_root = LCA(root, n1, n2);

    int d1 = findLevel(lca_root, n1, 0);
    int d2 = findLevel(lca_root, n2, 0);

    return d1 + d2;
}

int main()
{
    // your code goes here
    return 0;
}