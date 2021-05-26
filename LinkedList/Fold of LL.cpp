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

void solve(Node **left, Node *right)
{
    if (right == NULL) // This is BASE CASE
    {
        return;
    }

    solve(left, right->next);

    if ((*left)->next == NULL) // This is TERMINATING condition
    {
        return;
    }

    if ((*left) != right && (*left)->next != right)
    {
        Node *temp = (*left)->next;
        (*left)->next = right;
        right->next = temp;
        *left = temp;
    }
    else
    {
        // if((*left) != right)
        // {
        // 	*left = (*left)->next;
        // }

        right->next = NULL;
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
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *left = head;

    printlist(head);

    solve(&left, head);

    printlist(head);

    return 0;
}