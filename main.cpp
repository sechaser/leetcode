#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int maxProfit(std::vector<int>& prices)
{
    if(prices.empty())
        return 0;

    int res = 0;
    int i = 0;

    std::string::size_type sz = prices.size();
    prices.push_back(-1);

    while(i != sz)
    {
        int beg = i;
        while(prices[i+1] > prices[i])
            ++ i;

        res = res + (prices[i] - prices[beg]);
        ++ i;
    }
    prices.pop_back();

    return res;
}



int main()
{
    std::vector<int> prices{9, 8};
    std::cout<<maxProfit(prices)<<std::endl;

    system("pause");
    return 0;
}

