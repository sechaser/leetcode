#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int candy(std::vector<int>& ratings)
{
    std::vector<int> candyNum(ratings.size(), 1);

    for(int i = 1; i != ratings.size(); ++ i)
    {
        if(ratings[i] > ratings[i - 1])
            candyNum[i] = candyNum[i-1] + 1;
    }

    for(int i = ratings.size() - 2; i >= 0; -- i)
    {
        if((ratings[i] > ratings[i+1]) && (candyNum[i] <= candyNum[i+1]))
            candyNum[i] = candyNum[i+1] + 1;
    }

    int res = std::accumulate(candyNum.begin(), candyNum.end(), 0);

    return res;
}


int main()
{
    std::vector<int> ratings{1, 3, 2, 4, 6, 3};
    std::cout<<candy(ratings)<<std::endl;

    system("pause");
    return 0;
}

