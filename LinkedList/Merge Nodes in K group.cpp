/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int calculateLength(ListNode *head)
    {
        int cnt = 0;

        while (head)
        {
            cnt++;
            head = head->next;
        }

        return cnt;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {

        int len = calculateLength(head);

        ListNode *th = NULL;
        ListNode *tt = NULL;
        ListNode *oh = NULL;
        ListNode *ot = NULL;

        ListNode *cur = head;

        int tempk;

        while (len >= k)
        {
            tempk = k;
            while (tempk-- > 0)
            {
                ListNode *temp = cur->next;
                cur->next = NULL;

                if (tt == NULL)
                {
                    cur->next = th;
                    th = cur;
                    tt = cur;
                }
                else
                {
                    cur->next = th;
                    th = cur;
                }

                cur = temp;
            }

            if (oh == NULL && ot == NULL)
            {
                oh = th;
                ot = tt;
            }
            else
            {
                ot->next = th;
                ot = tt;
            }

            tt = NULL;
            th = NULL;
            len -= k;
        }

        ot->next = cur;

        return oh;
    }
};