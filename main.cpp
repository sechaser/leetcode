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


ListNode* insertionSortList(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* dummy = new ListNode(INT_MIN);

    ListNode* pre = dummy;
    ListNode* cur = head;

    while(cur)
    {
        ListNode* next = cur->next;
        pre = dummy;

        while(pre->next != NULL && pre->next->val <= cur->val)
                pre = pre->next;

        cur->next = pre->next;
        pre->next = cur;
        cur = next;
    }

    return dummy->next;
}


int main()
{
    ListNode* node, *p, *lis1, *lis2, *lis3;
    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = 5-i;
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


    ListNode* res = insertionSortList(lis1);

//    while(res != NULL)
//    {
//        std::cout<<res->val<<" ";
//        res = res->next;
//    }


    system("pause");
    return 0;
}

