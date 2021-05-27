#include <iostream>
using namespace std;

class ListNode
{
public:
    ListNode *next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

public:
    struct mycom
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeTwoLL(ListNode *h1, ListNode *h2)
    {
        if (h1 == NULL || h2 == NULL)
        {
            return (h1 == NULL) ? h2 : h1;
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;

        ListNode *c1 = h1;
        ListNode *c2 = h2;

        while (c1 != NULL && c2 != NULL)
        {
            if (c1->val <= c2->val)
            {
                prev->next = c1;
                c1 = c1->next;
            }
            else
            {
                prev->next = c2;
                c2 = c2->next;
            }
            prev = prev->next;
        }

        prev->next = c1 != NULL ? c1 : c2;

        return dummy->next;

        //          if(h1 == NULL || h2 == NULL)
        //         {
        //              return (h1 == NULL) ? h2 : h1;
        //         }

        //         if(h1->val < h2->val)
        //         {
        //             h1->next  = mergeTwoLL(h1->next, h2);
        //             return h1;
        //         }
        //         else
        //         {
        //             h2->next  = mergeTwoLL(h1, h2->next);
        //             return h2;
        //         }
    }

    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l > r)
            return NULL;

        if (l == r)
            return lists[l];

        int mid = (l + r) / 2;

        ListNode *l1 = merge(lists, l, mid);
        ListNode *l2 = merge(lists, mid + 1, r);

        return mergeTwoLL(l1, l2);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
            return NULL;

        //int k = lists.size();

        auto cmp = [&](ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

        // Pushing the Head Nodes of all the lists in pq;

        // So, At a time, maximum K nodes are only present in the pq

        // We are pushing K nodes in pq, so T.C will Klog(k)

        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
                pq.push(lists[i]);
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;

        while (!pq.empty()) // This loop will run maximum Kn times b'coz Total element are Kn
        {
            ListNode *cur = pq.top();

            pq.pop(); // log(k)

            prev->next = cur;
            prev = cur;

            if (cur->next != NULL)
                pq.push(cur->next); // log(k)
        }

        return dummy->next;

        /*******************
        
        
            klog(k) + kn*(log(k) + log(k))
        
        =>  klog(k) + 2kn(log(k))
        
        T.C -----> O(KN(log(K)))
        
        S.C -----> O(K)
        
        
        ************************/
    }
};

int main()
{
    return 0;
}