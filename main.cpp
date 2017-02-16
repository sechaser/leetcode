#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
{
    int sz = gas.size();

    int start = 0, netGasSum = 0, curGasSum = 0;
    for(int i = 0; i != sz; ++ i)
    {
        netGasSum += (gas[i] - cost[i]);
        curGasSum += (gas[i] - cost[i]);

        if(curGasSum < 0)
        {
            start = i + 1;
            curGasSum = 0;
        }
    }

    if(netGasSum < 0)
        return -1;
    else
        return start;
}


int main()
{
    std::vector<int> gas{3, 2, 1, 5};
    std::vector<int> cost{2, 3, 2, 1};

    std::cout<<canCompleteCircuit(gas, cost)<<std::endl;

    system("pause");
    return 0;
}

