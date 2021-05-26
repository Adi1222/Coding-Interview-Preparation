#include <iostream>
using namespace std;

// O(N) T.C

/* C Lang*/

// struct Node* newNode(int x)
// {
// 	struct Node* temp = malloc(sizeof(struct Node));
// 	temp->data = x;
// 	temp->next = NULL;
// 	return temp;
// }

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

void reverse(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;

    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    *head = prev; // b'coz we have passed by reference
}

void solve(Node **head) // we are going to modify the LL
{
    Node *sp = *head;
    Node *fp = *head;

    while (fp && fp->next)
    {
        sp = sp->next;
        fp = fp->next;
    }

    Node *h1 = *head;
    Node *h2 = sp->next;
    sp->next = NULL;

    reverse(&h2); // passing by refernce to modify the LL

    printlist(*head);

    Node *c1 = h1;
    Node *c2 = h2;

    Node *b1;
    Node *b2;

    while (c2)
    {
        b1 = c1->next;
        b2 = c2->next;

        c1->next = c2;
        c2->next = b1;

        c1 = b1;
        c2 = b2;
    }
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *left = head;

    printlist(head);

    solve(&head);

    //printlist(head);

    return 0;
}