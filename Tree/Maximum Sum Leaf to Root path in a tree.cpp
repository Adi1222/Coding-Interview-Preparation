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

// NOTE: initially ans will be INT_MIN

void solve(node *nod, int &ans, node *(&leaf), int cur = 0)
{
    if (nod == NULL)
    {
        return;
    }

    cur += nod->data;

    // checking if we are at leaf node so that we can update the answer

    if (nod->left == NULL && nod->right == NULL)
    {
        if (cur > ans)
        {
            ans = cur;
            leaf = nod; // storing the leaf also so that we can use this later to print the path from root to this leaf
        }
    }

    solve(nod->left, ans, leaf, cur);

    solve(nod->right, ans, leaf, cur);
}

int main()
{
    // your code goes here
    return 0;
}