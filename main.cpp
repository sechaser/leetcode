#include <iostream>

using namespace std;

#include <math.h>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x = 0):val(x), next(NULL){}
};

int main()
{
    int i = 0, value;
    ListNode* p1, *p2;
    ListNode lis11(2), lis12(4), lis13(3);
    ListNode lis21(5), lis22(6), lis23(4);

    p1 = &lis11;
    lis11.next = &lis12;
    lis12.next = &lis13;

    p2 = &lis21;
    lis21.next = &lis22;
    lis22.next = &lis23;

    long sum1 = 0, sum2 = 0;
    while(p1 != NULL)
    {
        value = p1->val;
        sum1 = sum1 + value * pow(10, i);
        p1 = p1->next;
        ++ i;
    }

    i = 0;
    while(p2 != NULL)
    {
        value = p2->val;
        sum2 = sum2 + value * pow(10, i);
        p2 = p2->next;
        ++ i;
    }

    long sum = sum1 + sum2;
    ListNode* p, *pp, *l;
    bool first = 1;

    while(sum != 0)
    {
        if(first == 1)
        {
            l = (ListNode*)malloc(sizeof(ListNode));
            l->val  = (sum % 10);
            l->next = NULL;
            sum = sum / 10;
            p   = l;
            pp  = l;
            first = 0;
        }
        else
        {
            l = (ListNode*)malloc(sizeof(ListNode));
            l->val  = (sum % 10);
            l->next = NULL;
            sum = sum / 10;
            pp->next = l;
            pp = pp->next;
        }
    }
    pp->next = NULL;

    while(p != NULL)
    {
        std::cout<<(p->val)<<" ";
        p = p->next;
    }

    return 0;
}

