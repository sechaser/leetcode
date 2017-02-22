#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

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
//    if(lists.size() == 0)
//        return NULL;

//    int end = lists.size() - 1;
//    while(end > 0)
//    {
//        int beg = 0;
//        while(beg < end)
//        {
//            lists[beg] = merge2List(lists[beg], lists[end]);
//            ++ beg;
//            -- end;
//        }
//    }

//    return lists[0];
//}

//ListNode* merge2List(ListNode* list1, ListNode* list2)
//{
//    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
//    dummy->next = NULL;
//    ListNode* p = node;

//    while(list1 && list2)
//    {
//        if(list1->val <= list2->val)
//        {
//            p->next = list1;
//            list1 = list1->next;
//        }
//        else
//        {
//            p->next = list2;
//            list2 = list2->next;
//        }
//        p = p->next;
//    }

//    p->next = list1 ? list1 : list2;

//    return dummy->next;
//}

struct cmp
{
    bool operator()(const ListNode* l1, const ListNode* l2)
    {
        return l1->val > l2->val;
    }
};

ListNode* mergeKList(std::vector<ListNode*>& lists)
{
    if(lists.size() == 0)
        return NULL;

    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    ListNode* p = dummy;

    std::priority_queue<ListNode*, std::vector<ListNode*>, cmp> pq;
    for(int i = 0; i != lists.size(); ++ i)
    {
        if(lists[i])
            pq.push(lists[i]);
    }

    while(!pq.empty())
    {
        ListNode* root = pq.top();
        pq.pop();

        p->next = root;
        p = root;

        if(root->next)
            pq.push(root->next);
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

