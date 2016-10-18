#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};

ListNode* reverse(ListNode* pre, ListNode* end)
{
    if(pre == NULL || pre->next == NULL)
        return pre;

    ListNode* head = pre->next;
    ListNode* cur  = pre->next->next;

    while(cur != end)
    {
        ListNode* next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = next;
    }

    head->next = end;
    return head;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    if(head == NULL)
        return NULL;

    ListNode* node = new ListNode(0);
    node->next = head;
    int count = 0;

    ListNode* pre = node;
    ListNode* cur = head;

    while(cur != NULL)
    {
        ++ count;
        ListNode* next = cur->next;

        if(count == k)
        {
            pre = reverse(pre, next);
            count = 0;
        }

        cur = next;
    }

    return node->next;
}

int main()
{
    ListNode* node, *p, *lis1;
    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i;
        node->next = NULL;

        if(i == 0)
        {
            lis1 = node;
            p    = node;
        }
        else
        {
            p->next = node;
            p       = node;
        }
    }

    ListNode* newList = reverseKGroup(lis1, 2);
    while(newList != NULL)
    {
        std::cout<<std::setw(4)<<newList->val;
        newList = newList->next;
    }
    std::cout<<std::endl;

    system("pause");
    return 0;
}

