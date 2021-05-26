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

int findcount(Node *h1, Node *h2)
{
    int cnt = 0;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data == h2->data)
        {
            cnt += 1;
        }
        else
        {
            break;
        }

        h1 = h1->next;
        h2 = h2->next;
    }

    return cnt;
}

int solve(Node *head)
{
    // base case
    if (head == NULL)
    {
        return 0;
    }

    if (head->next == NULL)
    {
        return 1;
    }

    int ans = 0;

    Node *prev = NULL;
    Node *cur = head;
    Node *nxt;

    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;

        ans = max(ans, 2 * findcount(prev, nxt) + 1);

        ans = max(ans, 2 * findcount(cur, nxt));

        prev = cur;
        cur = nxt;
    }

    return ans;
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

    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(15);

    // printlist(head);

    cout << solve(head);

    // printlist(head);

    return 0;
}