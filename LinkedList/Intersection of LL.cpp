#include <iostream>
using namespace std;

/**  Optimal Approach  **/
// T.C -- > O(2m)
// S.C -- > O(1)

// Other approaches
// 1. T.C -- > O(m*n)
// 2. T.c -- > O(m + n)  S.C --> O(n) [haspmap appraoch]
// 3. T.C -- > O(m)    +    O(m - n)    +      O(n)   S.C -- > O(1)
/*               /\            /\                /\ 
                  |             |                 |             
                  |             |                 |
    iterate simultaneously *  In order to      *  Traversing the
    to find th length of   *  move the ptr     *  remaining same
     2 LL's                *  of 2nd list by   *  length LL inorder
                           *  (diff) positions *  to find the 
                           *  ahead            *  intersection node





*/

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int x)
    {
        data = x;
        next = NULL;
    }

    Node(int x, Node *nxt)
    {
        data = x;
        next = nxt;
    }
};

void printlist(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

// void reverse(Node **head)
// {
//     if (*head == NULL || (*head)->next == NULL)
//     {
//         return;
//     }

//     Node *prev = NULL;
//     Node *cur = *head;
//     Node *nxt;

//     while (cur)
//     {
//         nxt = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = nxt;
//     }

//     *head = prev; // b'coz we have passed by reference
// }

Node *getBiggerLL(Node *h1, Node *h2)
{
    Node *a = h1;
    Node *b = h2;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data > h2->data)
        {
            return a;
        }
        else if (h1->data < h2->data)
        {
            return b;
        }

        h1 = h1->next;
        h2 = h2->next;
    }

    if (h1 == NULL)
        return b;

    return a;
}

Node *reverse(Node *h)
{
    if (h == NULL || h->next == NULL)
    {
        return h;
    }

    Node *prev = NULL;
    Node *cur = h;
    Node *nxt;
    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    return prev; // returning the head of the reversed LL
}

Node *findIntersection(Node *h1, Node *h2)
{
    if (h1 == NULL || h2 == NULL)
        return NULL;

    Node *a = h1;
    Node *b = h2;

    while (a != b)
    {
        a = a == NULL ? h2 : a->next;
        b = b == NULL ? h1 : b->next;
    }

    return a;
}

int main()
{

    Node *head1 = new Node(1);
    head1->next = new Node(5);
    head1->next->next = new Node(2);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(3);

    Node *head2 = new Node(9);
    head2->next = new Node(2);
    head2->next->next = new Node(12);
    head2->next->next->next = new Node(13);

    printlist(head1);
    printlist(head2);

    Node *ans = findIntersection(head1, head2);

    printlist(ans);

    return 0;
}