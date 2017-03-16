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

int calculateTimeDifference(std::string& time1, std::string& time2)
{
    std::cout<<time1<<" "<<time2<<std::endl;

    int h1 = std::stoi(time1.substr(0, 2));
    int m1 = std::stoi(time1.substr(3));

    int h2 = std::stoi(time2.substr(0,2));
    int m2 = std::stoi(time2.substr(3));

    return (h2 - h1) * 60 + (m2 - m1);
}

int findMinDifference(std::vector<std::string>& timePoints)
{
    std::sort(timePoints.begin(), timePoints.end());
    std::string t;
    t = std::to_string(std::stoi(timePoints[0].substr(0,2)) + 24) + timePoints[0].substr(2);
    timePoints.push_back(t);
    //std::cout<<"hello"<<std::endl;

    int minDiff = INT_MAX, curDiff;
    for(int i = 0; i < timePoints.size() - 1; ++ i)
    {
        curDiff = calculateTimeDifference(timePoints[i], timePoints[i+1]);
        if(curDiff < minDiff)
            minDiff = curDiff;
    }

    return minDiff;
}

int main()
{
    std::vector<std::string> timePoints{"00:00", "23:59"};
    std::cout<<findMinDifference(timePoints)<<std::endl;
    system("pause");
    return 0;
}

