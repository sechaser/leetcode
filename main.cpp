#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

struct Point{
    int x;
    int y;

    Point():x(0),y(0) {}
    Point(int a, int b):x(a), y(b) {}
};


int maxPoints(std::vector<Point>& points)
{
    int maxPts = 0;

    for(std::vector<int>::size_type i = 0; i != points.size(); ++ i)
    {
        int nSame = 0, nInf = 0, nMax = 0;
        std::unordered_map<float, int> mp;

        for(std::vector<int>::size_type j = i+1; j != points.size(); ++ j)
        {
            if(points[j].x == points[i].x)
            {
                if(points[j].y == points[j].y)
                    ++ nSame;
                else
                    ++ nInf;
                continue;
            }

            float slope = (float)(points[j].y - points[i].y)/(float)(points[j].x - points[i].x);
            ++ mp[slope];
            nMax = std::max(nMax, mp[slope]);
        }

        nMax = std::max(nMax, nInf) + nSame + 1;
        maxPts = std::max(maxPts, nMax);
    }

    return maxPts;
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

