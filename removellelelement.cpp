#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }
        if (head->next == nullptr && head->val == val)
        {
            head = nullptr;
            return head;
        }
        if (head->next == nullptr && head->val != val)
        {
            return head;
        }

        ListNode *p;
        ListNode *q;
        p = head;
        q = nullptr;
        while (p != nullptr)
        {

            if (p->val == val && q != nullptr)
            {
                q->next = p->next;
                p = p->next;
            }
            else if (p->val == val && q == nullptr)
            {
                head = p->next;
                p = head;
            }

            else
            {
                q = p;
                p = p->next;
            }
        }
        return head;
    }
};

int main()
{

    return 0;
}