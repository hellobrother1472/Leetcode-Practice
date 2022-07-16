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
    // void insert(ListNode *p, int n)
    // {

    //     ListNode *t = new ListNode();
    //     t->val = n;
    //     t->next = nullptr;

    //     if (sol == nullptr)
    //     {
    //         sol = t;
    //     }
    //     else
    //     {
    //         while (sol != nullptr)
    //         {
    //             sol = sol->next;
    //         }
    //         sol = t;
    //     }
    // }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if(list1 == NULL){
			return list2;
		}
		if(list2 == NULL){
			return list1;
		}
        ListNode *p = list1;
        ListNode *q = list2;
        ListNode *sol = new ListNode();

        while (p != nullptr && q != nullptr)
        {
            if (p->val < q->val)
            {
                ListNode *t = new ListNode();
                t->val = p->val;
                t->next = nullptr;

                if (sol == nullptr)
                {
                    sol = t;
                }
                else
                {
                    while (sol != nullptr)
                    {
                        sol = sol->next;
                    }
                    sol = t;
                };
                p = p->next;
            }
            else if (p->val > q->val)
            {
                ListNode *t = new ListNode();
                t->val = q->val;
                t->next = nullptr;

                if (sol == nullptr)
                {
                    sol = t;
                }
                else
                {
                    while (sol != nullptr)
                    {
                        sol = sol->next;
                    }
                    sol = t;
                };
                q = q->next;
            }
            else
            {
                ListNode *t = new ListNode();
                t->val = p->val;
                t->next = nullptr;

                if (sol == nullptr)
                {
                    sol = t;
                }
                else
                {
                    while (sol != nullptr)
                    {
                        sol = sol->next;
                    }
                    sol = t;
                };
                
                p = p->next;
                
            }
        }

        if (p != nullptr)
        {
            while (p != nullptr)
            {
                ListNode *t = new ListNode();
                t->val = p->val;
                t->next = nullptr;

                if (sol == nullptr)
                {
                    sol = t;
                }
                else
                {
                    while (sol != nullptr)
                    {
                        sol = sol->next;
                    }
                    sol = t;
                };
                p = p->next;
            }
        }
        if (q != nullptr)
        {
            while (q != nullptr)
            {
                ListNode *t = new ListNode();
                t->val = q->val;
                t->next = nullptr;

                if (sol == nullptr)
                {
                    sol = t;
                }
                else
                {
                    while (sol != nullptr)
                    {
                        sol = sol->next;
                    }
                    sol = t;
                };
                q = q->next;
            }
        }
        return sol;
    }
};

int main()
{

    return 0;
}