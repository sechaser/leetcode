#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>

struct Interval
{
    int start;
    int end;

    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//*************************************Time:O(n), Space:O(n)*************************************
//std::vector<Interval> merge(std::vector<Interval>& intervals)
//{
//    std::sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs){
//        return lhs.start < rhs.start;
//    });

//    std::vector<Interval> res;
//    for(std::vector<Interval>::size_type i = 0; i != intervals.size(); ++ i)
//    {
//        if(i == 0)
//        {
//            res.push_back(intervals[i]);
//            continue;
//        }

//        if(res[res.size() - 1].end < intervals[i].start)
//            res.push_back(intervals[i]);
//        else if(res[res.size() - 1].end >= intervals[i].start && res[res.size() - 1].end < intervals[i].end)
//            res[res.size() - 1].end = intervals[i].end;
//        else
//            continue;
//    }

//    return res;
//}

//*******************************************Time:O(n),space:O(1)*******************************
std::vector<Interval> merge(std::vector<Interval>& intervals)
{
    std::sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs){
        return lhs.start < rhs.start;
    });

    std::vector<Interval>::iterator it = intervals.begin();
    while(it != intervals.end())
    {
        if(it == intervals.begin())
        {
            ++ it;
            continue;
        }

        if((it-1)->end < it->start)
            ++ it;
        else if((it-1)->end >= it->start && (it-1)->end < it->end)
        {
            (it-1)->end = it->end;
            it = intervals.erase(it);
        }
        else
            it = intervals.erase(it);
    }

    return intervals;
}


int main()
{
    std::vector<Interval> intervals{Interval(1,3), Interval(2,6), Interval(8, 10), Interval(15,18)};
    std::vector<Interval> res = merge(intervals);

    for(std::vector<Interval>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<res[i].start<<" "<<res[i].end<<std::endl;

    system("pause");
    return 0;
}

