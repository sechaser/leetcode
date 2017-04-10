#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//int maxProfit(std::vector<int>& prices)
//{
//    if(prices.empty())
//        return 0;

//    int minValue = prices[0];

//    int res = 0;
//    for(int i = 1; i != prices.size(); ++ i)
//    {
//        if(prices[i] - minValue > res)
//            res = prices[i] - minValue;

//        minValue = std::min(minValue, prices[i]);
//    }

//    return res;
//}


int maxProfit(std::vector<int>& prices)
{
    if(prices.empty())
        return 0;

    int local = 0, global = 0;

    for(int i = 0; i < prices.size() - 1; ++ i)
    {
        local  = std::max(local + prices[i+1] - prices[i], 0);
        global = std::max(global, local);
    }

    return global;
}


int main()
{
    std::vector<int> prices{7, 6, 4, 3, 1};
    std::cout<<maxProfit(prices)<<std::endl;


    system("pause");
    return 0;
}

