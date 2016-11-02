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


std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval)
{
    std::sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs){
        return lhs.start < rhs.start;
    });

    auto it = intervals.begin();
    while(it != intervals.end() && it->start < newInterval.start)
        ++ it;
    intervals.insert(it, newInterval);


    it = intervals.begin();
    while(it != intervals.end())
    {
        if(it == intervals.begin())
        {
            ++ it;
            continue;
        }

        if((it-1)->end < it->start)
            ++ it;
        else if(((it-1)->end >= it->start) && ((it-1)->end < it->end))
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
    std::vector<Interval> intervals{Interval(1,2), Interval(3,5), Interval(6,7), Interval(8,10), Interval(12,16)};
    Interval newInterval(4,9);
    std::vector<Interval> res = insert(intervals, newInterval);

    for(std::vector<Interval>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<res[i].start<<" "<<res[i].end<<std::endl;

    system("pause");
    return 0;
}

