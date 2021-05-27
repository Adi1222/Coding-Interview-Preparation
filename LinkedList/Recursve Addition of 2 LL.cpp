#include <iostream>
using namespace std;

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

Node *addRecursive(Node *h1, Node *h2, int *carry) // carry is passwd by reference
{
    // base condition

    if (h1 == NULL) // I am assuming both lists are of same size
    {
        return NULL; // i.e this solution will work only for same size lists
    }

    int sum;

    Node *temp = new Node();

    temp->next = addRecursive(h1->next, h2->next, carry);

    sum = h1->data + h2->data + *carry;

    *carry = sum / 10;

    sum = sum % 10;

    temp->data = sum;

    return temp;
}

int main()
{

    Node *head1 = new Node(1);
    head1->next = new Node(1);
    //head1->next->next = new Node(3);

    Node *head2 = new Node(1);
    head2->next = new Node(1);

    printlist(head1);
    printlist(head2);

    int carry = 0;
    Node *ans = addRecursive(head1, head2, &carry); /// passing carry by refernce

    if (carry)
    {
        Node *node = new Node(carry);
        node->next = ans;
        ans = node;
    }

    printlist(ans);

    return 0;
}