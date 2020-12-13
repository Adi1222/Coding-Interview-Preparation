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

int main()
{
    // your code goes here
    return 0;
}