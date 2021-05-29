#include <iostream>
using namespace std;

// T.C O(summation(Total no. of nodes))
// S.C O(1)

class Node
{
public:
    int data;
    Node *right;
    Node *down;

    Node()
    {
        data = 0;
        right = NULL;
        down = NULL;
    }

    Node(int data)
    {
        data = data;
        right = NULL;
        down = NULL;
    }
};

Node *mergeTwoLL(Node *a, Node *b)
{

    if (a == NULL || b == NULL)
    {
        return (a == NULL) ? b : a;
    }

    Node *dummy = new Node(-1);
    dummy->down = a;
    Node *prev = dummy;

    Node *c1 = a;
    Node *c2 = b;

    while (c1 != NULL && c2 != NULL)
    {
        if (c1->data < c2->data)
        {
            prev->down = c1;
            c1 = c1->down;
        }
        else
        {
            prev->down = c2;
            c2 = c2->down;
        }

        prev = prev->down;
    }

    prev->down = c1 != NULL ? c1 : c2;

    dummy->right = NULL;
    return dummy->down;
}

Node *flatten(Node *rt)
{
    // base condition
    if (rt == NULL || rt->right == NULL)
        return rt;

    rt->right = flatten(rt->right);

    rt = mergeTwoLL(rt, rt->right);

    rt->right = NULL;

    return rt;
}

int main()
{

    return 0;
}