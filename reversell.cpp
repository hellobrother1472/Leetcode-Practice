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
    ListNode *reverseList(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *p = head;
        ListNode *q = nullptr;
        ListNode *r = nullptr;

        while (p != nullptr)
        {
            r = q;
            q = p;
            p = p->next;

            q->next = r;
        }

        head = q;
        
        return head;
    }
};

int main(){
    

    return 0;
}
