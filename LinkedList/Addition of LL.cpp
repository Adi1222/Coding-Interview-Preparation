#include <iostream>
using namespace std;

// O(max(len(LL1), len(LL2))) T.C

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

Node *add(Node *h1, Node *h2)
{

    Node *a = reverse(h1);
    Node *b = reverse(h2);

    Node *dummy = new Node(-1);
    Node *prev = dummy;

    Node *temp;

    int carry = 0;

    while (a != NULL || b != NULL)
    {
        int add = carry;

        if (a != NULL)
        {
            add += a->data;
        }
        if (b != NULL)
        {
            add += b->data;
        }

        if (add >= 10)
        {
            carry = add / 10;
            temp = new Node(add % 10);
        }
        else
        {
            carry = 0;
            temp = new Node(add);
        }

        prev->next = temp;

        prev = temp;

        if (a != NULL)
            a = a->next;

        if (b != NULL)
            b = b->next;
    }

    if (carry)
    {
        prev->next = new Node(carry);
    }

    Node *ans = reverse(dummy->next);

    return ans;
}

int main()
{

    Node *head1 = new Node(5);
    head1->next = new Node(6);
    head1->next->next = new Node(3);

    Node *head2 = new Node(6);
    head2->next = new Node(3);

    printlist(head1);
    printlist(head2);

    Node *ans = add(head1, head2);

    printlist(ans);

    return 0;
}