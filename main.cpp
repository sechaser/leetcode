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

//Time limit exceed
//ListNode* mergeKList(std::vector<ListNode*> lists)
//{
//    std::vector<ListNode*>::size_type sz = lists.size();

//    ListNode* node = (ListNode *)malloc(sizeof(ListNode));
//    node->next = NULL;

//    ListNode* nList = node;
//    for(int i = 0; i != sz; ++ i)
//    {
//        ListNode* head1 = lists[i];
//        ListNode* head2 = nList->next;
//        ListNode* p     = nList;

//        while(head1 != NULL && head2 != NULL)
//        {
//            if(head1->val <= head2->val)
//            {
//                p->next = head1;
//                head1   = head1->next;
//                p       = p->next;
//            }
//            else
//            {
//                p->next = head2;
//                head2   = head2->next;
//                p       = p->next;
//            }
//        }

//        while(head1 != NULL)
//        {
//            p->next = head1;
//            head1   = head1->next;
//            p       = p->next;
//        }

//        while(head2 != NULL)
//        {
//            p->next = head2;
//            head2   = head2->next;
//            p       = p->next;
//        }
//    }

//    return nList->next;
//}


//ListNode* merge2List(ListNode* list1, ListNode* list2);
//ListNode* mergeKList(std::vector<ListNode*>& lists)
//{
//    int sz = lists.size();
//    if(sz == 0)
//        return NULL;

//    while(sz > 1)
//    {
//        int k = (sz + 1)/2;
//        for(int i = 0; i != sz/2; ++ i)
//            lists[i] = merge2List(lists[i], lists[i+k]);
//        sz = k;
//    }

//    return lists[0];
//}

//ListNode* merge2List(ListNode* list1, ListNode* list2)
//{
//    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//    node->next = NULL;
//    ListNode* p = node;

//    while(list1 != NULL && list2 != NULL)
//    {
//        if(list1->val <= list2->val)
//        {
//            p->next = list1;
//            list1   = list1->next;
//        }
//        else
//        {
//            p->next = list2;
//            list2   = list2->next;
//        }

//        p = p->next;
//    }

//    while(list1 != NULL)
//    {
//        p->next = list1;
//        list1   = list1->next;
//        p       = p->next;
//    }

//    while(list2 != NULL)
//    {
//        p->next = list2;
//        list2   = list2->next;
//        p       = p->next;
//    }

//    if(list1 != NULL)
//        p->next = list1;
//    else
//        p->next = list2;

//    return node->next;
//}

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

    std::vector<ListNode*> lv{lis1, lis2, lis3};
    ListNode* newList = mergeKList(lv);

    while(newList != NULL)
    {
        std::cout<<std::setw(4)<<newList->val;
        newList = newList->next;
    }
    std::cout<<std::endl;

    system("pause");
    return 0;
}

