#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(!head)
        return head;

    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->next = head;
    ListNode* p = node, *q = node;

    while(n > 0)
    {
        p = p->next;
        -- n;
    }

    while(p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    q->next = q->next->next;

    //You can not return "head" pointer, because the deleted element may be the "head" points at.
    return node->next;
}

int main()
{
    ListNode* node;
    ListNode* head;
    ListNode* p;

    for(int i = 0; i != 5; ++ i)
    {
        if(i == 0)
        {
            node = (ListNode *)malloc(sizeof(ListNode));
            node->next = NULL;
            node->val  = i;
            head = node;
               p = node;
        }
        else
        {
            node = (ListNode *)malloc(sizeof(ListNode));
            node->next = NULL;
            node->val  = i;
            p->next    = node;
                   p   = node;

        }
    }

    head = removeNthFromEnd(head, 5);
    p = head;

    while(p != NULL)
    {
        std::cout<<p->val<<std::endl;
        p = p->next;
    }

    return 0;
}

