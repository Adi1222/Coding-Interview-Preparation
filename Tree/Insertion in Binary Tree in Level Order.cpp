#include <iostream>
#include <queue>
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

node *insertLevelOrder(node *root, int x)
{
    if (root == NULL) // if the tree is empty
    {
        root = new node(x);
        return root;
    }

    // ***NOTE**:  AS we are traversing in level order we use queue here

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp->left) // if present then just push it in the queue
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = new node(x); // creating node
            return root;
        }

        // similarly checking for right subtree node

        if (temp->right)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = new node(x);
            return root;
        }
    }
}

int main()
{
    // your code goes here
    return 0;
}