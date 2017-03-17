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

int findPosionedDuration(std::vector<int>& timeSeries, int duration)
{
    if(timeSeries.empty())
        return 0;

    int res = 0;
    for(int i = 1; i < timeSeries.size(); ++ i)
    {
        if(timeSeries[i] - timeSeries[i-1] < duration)
            res += (timeSeries[i] - timeSeries[i-1]);
        else
            res += duration;
    }

    res += duration;

    return res;
}

int main()
{
    std::vector<int> timeSeries{1, 3, 6};
    std::cout<<findPosionedDuration(timeSeries, 3)<<std::endl;


    system("pause");
    return 0;
}

