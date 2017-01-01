#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//Method 1 : run time error
//int maxProfit(std::vector<int>& prices)
//{
//    if(prices.empty())
//        return 0;

//    std::vector<int> res;
//    std::vector<int>::size_type sz = prices.size();

//    prices.push_back(-1);
//    int i = 0;
//    while(i != sz)
//    {
//        int beg = i;
//        while(i != sz && prices[i+1] >= prices[i])
//            ++ i;

//        if(i != sz)
//        {
//            res.push_back(prices[i]-prices[beg]);
//            ++ i;
//        }
//    }

//    prices.pop_back();

//    std::sort(res.begin(), res.end(), [](const int& lhs, const int& rhs){
//        return lhs <= rhs;
//    });

//    if(res.size() == 1)
//        return res[0];
//    else
//        return res[res.size()-1] + res[res.size()-2];
//}


int maxProfit(std::vector<int>& prices)
{
    if(prices.size() <= 1)
        return 0;

    std::vector<int>::size_type sz = prices.size();
    std::vector<int> leftProfit(sz, 0);

    int leftMaxProfit = 0, minPrice = prices[0];
    for(int i = 1; i != sz; ++ i)
    {
        if(prices[i] < minPrice)
            minPrice = prices[i];
        else
            leftMaxProfit = std::max(leftMaxProfit, prices[i] - minPrice);
        leftProfit[i] = leftMaxProfit;
    }

    for(std::vector<int>::size_type i = 0; i != sz; ++ i)
        std::cout<<std::setw(4)<<leftProfit[i];
    std::cout<<std::endl;

    int res = leftProfit[sz - 1];
    int rightMaxProfit = 0, maxPrice = prices[sz - 1];
    for(int i = (sz - 2); i >= 0; -- i)
    {
        if(prices[i] > maxPrice)
            maxPrice = prices[i];
        else
            rightMaxProfit = std::max(rightMaxProfit, maxPrice - prices[i]);
        res = std::max(res, rightMaxProfit + leftProfit[i]);
    }

    return res;
}

int main()
{
    std::vector<int> prices{1, 2, 3, 5, 4, 6, 7};
    std::cout<<maxProfit(prices)<<std::endl;


    system("pause");
    return 0;
}

