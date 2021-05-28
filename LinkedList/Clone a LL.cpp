#include <iostream>
#include <map>
using namespace std;

// T.C O(N)
//SC O(N)

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node()
    {
        data = 0;
        random = NULL;
        next = NULL;
    }

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void printlist(Node *head)
{

    Node *h = head;
    while (head != NULL)
    {
        Node *random = head->random;

        int r = (random != NULL) ? random->data : -1;

        cout << "data:" << head->data << " ";
        cout << "random:" << r << " ";

        head = head->next;
    }

    cout << endl;
}

Node *cloneLL(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *cur = head;
    Node *nxt = NULL;

    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = new Node(cur->data);
        cur->next->next = nxt;

        cur = nxt;
    }

    cur = head;

    while (cur != NULL)
    {
        cur->next->random = cur->random->next;
        cur = cur->next != NULL ? cur->next->next : cur->next;
    }

    cur = head;

    Node *sec = head->next;
    Node *ans = head;

    while (cur != NULL && sec != NULL)
    {
        cur->next = cur->next != NULL ? cur->next->next : cur->next;
        sec->next = sec->next != NULL ? sec->next->next : sec->next;

        cur = cur->next;
        sec = sec->next;
    }

    return ans;
}

Node *cloneLLusingHashMap(Node *head)
{
    if (head == NULL)
        return head;

    map<Node *, Node *> mp;

    Node *cur = head;

    while (cur != NULL)
    {
        Node *newNode = new Node(cur->data);

        mp.insert({cur, newNode});

        cur = cur->next;
    }

    cur = head;
    Node *clonecur;

    while (cur != NULL)
    {
        clonecur = mp[cur];
        clonecur->next = mp[cur->next];
        clonecur->random = mp[cur->random];
        cur = cur->next;
    }

    return mp[head];
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next;
    head->next->next->next->next->random = head->next;

    printlist(head);
    Node *ans = cloneLL(head);
    Node *ans2 = cloneLLusingHashMap(head);

    printlist(ans);

    printlist(ans2);

    return 0;
}