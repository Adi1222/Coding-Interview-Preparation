#include <iostream>
using namespace std;

/*struct Node* newNode(int x)
{
	struct Node* temp = malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	return temp;
}*/

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

void solve(Node *head)
{
    Node *a = head;
    Node *b = head->next;

    Node *p = head;
    Node *q = head->next;

    while (q != NULL && q->next != NULL)
    {
        Node *temp = q->next;

        p->next = q->next;
        q->next = p->next->next;

        p = temp;
        q = temp->next;
    }

    // Reversing the other LL

    Node *prev = NULL;
    Node *cur = b;
    Node *nxt;

    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    Node *h2 = prev;

    while (h2)
    {
        p->next = h2;
        h2 = h2->next;
        p = p->next;
    }
}

void printlist(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(3);

    Node *left = head;

    printlist(head);

    cout << endl;
    solve(head);

    cout << endl;
    printlist(head);

    return 0;
}