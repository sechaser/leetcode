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

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if(head == NULL)
        return head;

    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->next = head;

    ListNode* pm = node;
    ListNode* pn = node;

    int gap = n - m;
    while(gap > 0)
    {
        pn = pn->next;
        -- gap;
    }

    ListNode* pm_prev = pm;
    while(m > 0)
    {
        pm_prev = pm;
        pm = pm->next;
        pn = pn->next;

        -- m;
    }

    ListNode* pn_next = pn->next;
    ListNode* ppm = pm;

    ListNode* tmp;

    while(pm != pn_next)
    {
        tmp = pm->next;
        pm->next = pm_prev->next;
        pm_prev->next = pm;
        pm = tmp;
    }
    ppm->next = pn_next;

    return node->next;
}


int main()
{
    ListNode* node, *p, *lis1;
    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i+1;
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

    p = reverseBetween(lis1, 2, 2);
    while(p != NULL)
    {
        std::cout<<std::setw(4)<<p->val;
        p = p->next;
    }
    std::cout<<std::endl;

    system("pause");
    return 0;
}

