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

ListNode* reverseList(ListNode* head)
{
    if(!head || head->next == NULL)
        return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy, *cur = head, *next = head->next;

    while(next)
    {
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;

        next = cur->next;
    }

    return dummy->next;
}
int main()
{
    ListNode* node, *p, *lis1, *lis2, *lis3;
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


    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i+5;
        node->next = NULL;

        if(i == 0)
        {
            lis2 = node;
            p    = node;
        }
        else
        {
            p->next = node;
            p       = node;
        }
    }

    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i;
        node->next = NULL;

        if(i == 0)
        {
            lis3 = node;
            p    = node;
        }
        else
        {
            p->next = node;
            p       = node;
        }
    }


    system("pause");
    return 0;
}

