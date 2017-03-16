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

int compareVersion(std::string version1, std::string version2)
{
    int i = 0;
    std::vector<int> res1, res2;
    int start = 0;

    while(i < version1.size())
    {
        while(i < version1.size() && version1[i] != '.')
            ++ i;
        std::string t = version1.substr(start, i-start);
        res1.push_back(std::stoi(t));

        i = i + 1;
        start = i;
    }

    i = 0;
    start = 0;

    while(i < version2.size())
    {
        while(i < version2.size() && version2[i] != '.')
            ++ i;
        std::string t = version2.substr(start, i-start);
        res2.push_back(std::stoi(t));

        i = i + 1;
        start = i;
    }

    int minSZ = std::min(res1.size(), res2.size());
    for(i = 0; i < minSZ; ++ i)
    {
        if(res1[i] > res2[i])
            return 1;
        else if(res1[i] < res2[i])
            return -1;
        else
            continue;
    }

    for(i = minSZ; i < res1.size(); ++ i)
    {
        if(res1[i] != 0)
            return 1;
    }

    for(i = minSZ; i < res2.size(); ++ i)
    {
        if(res2[i] != 0)
            return -1;
    }

    return 0;
}

int main()
{
    std::string version1 = "1.0.1", version2 = "1";
    std::cout<<compareVersion(version1, version2)<<std::endl;


    system("pause");
    return 0;
}

