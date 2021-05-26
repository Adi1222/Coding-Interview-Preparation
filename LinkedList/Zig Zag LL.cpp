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

void zigzag(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    bool flag = true; // less ( < ) relation is expected

    Node *cur = head;

    Node *a;
    Node *b;
    Node *prev = NULL;

    while (cur->next != NULL)
    {
        if (flag)
        {
            if (cur->data > cur->next->data)
            {
                a = cur;
                b = cur->next;

                a->next = b->next;
                b->next = a;

                if (prev)
                    prev->next = b;

                prev = b;
                cur = a;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        else
        {
            if (cur->data < cur->next->data)
            {
                a = cur;
                b = cur->next;

                a->next = b->next;
                b->next = a;

                if (prev)
                    prev->next = b;

                prev = b;
                cur = a;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }

        flag = !flag;
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

    Node *head = new Node(11);
    head->next = new Node(15);
    head->next->next = new Node(20);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(10);
    //     head->next->next->next->next->next = new Node(6);

    printlist(head);

    zigzag(head);

    printlist(head);

    return 0;
}