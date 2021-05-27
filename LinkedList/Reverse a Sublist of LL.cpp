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

Node *revserseSublist(Node *head, int m, int n)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *tt = NULL;
    Node *th = NULL;
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *prev = dummy;

    int cnt = 1;
    Node *cur = head;

    while (cnt != m)
    {
        cur = cur->next;
        prev = prev->next;
        cnt += 1;
    }

    cnt = n - m + 1;
    Node *temp = NULL;

    while (cnt > 0)
    {
        temp = cur->next;
        cur->next = NULL;

        if (tt == NULL)
        {
            cur->next = th;
            th = cur;
            tt = cur;
            //	cout<<th<<" "<<tt<<" ";
        }
        else
        {
            cur->next = th;
            th = cur;
            //cout<<th<<"th";
        }
        cur = temp;
        cnt -= 1;
    }

    tt->next = cur;
    prev->next = th;

    return dummy->next;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    int m = 2, n = 4;

    printlist(head);

    Node *ans = revserseSublist(head, m, n);

    printlist(ans);

    return 0;
}