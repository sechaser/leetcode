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


ListNode* deleteDuplicates(ListNode* head)
{
    if(head == NULL)
        return head;

    ListNode* node = (ListNode *)malloc(sizeof(ListNode));
    node->next = head;
    node->val  = INT_MAX;

    ListNode* curr = head->next;
    ListNode* prev = head;
    ListNode* pp = node;

    while(curr != NULL)
    {
        while(curr != NULL && prev->val == curr->val)
            curr = curr->next;

        //Duplicate
        if(prev->next != curr)
        {
            if(curr == NULL)
            {
                pp->next = NULL;
                return node->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        else
        {
            pp->next = prev;
            pp = prev;

            prev = curr;
            curr = curr->next;
        }
    }

    pp->next = prev;

    return node->next;
}


int main()
{
    ListNode* node, *p, *lis1;
    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        if(i == 1)
            node->val = 0;
        else
            node->val = i;

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

    p = deleteDuplicates(lis1);
    while(p != NULL)
    {
        std::cout<<p->val<<std::endl;
        p = p->next;
    }


    system("pause");
    return 0;
}


//Case 1: 1->1->1->1->1->NULL
//Case 2: 0->1->2->3->4->NULL
//Case 3: 0->0->2->2->4->NULL
//Case 4: 0->0->2->3->4->NULL

