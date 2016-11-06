#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//***************************************Method 1 : Time limit error******************************
//void solver(int& ways, int n)
//{
//    if(n == 0)
//    {
//        ++ ways;
//        return;
//    }
//    if(n < 0)
//        return ;

//    -- n;
//    solver(ways, n);
//    ++ n;

//    n -= 2;
//    solver(ways, n);
//    n += 2;
//}

//*********************************************Method 2*******************************************
//int climbStairs(int n)
//{
//    std::vector<int> dp(n+1, 0);
//    dp[0] = 1;
//    dp[1] = 1;

//    for(int i = 2; i <= n; ++ i)
//        dp[i] = dp[i-1] + dp[i-2];

//    return dp[n];
//}


int climbStairs(int n)
{
    int step0 = 1, step1 = 1;
    int step2;

    for(int i = 2; i <= n; ++ i)
    {
        step2 = step0 + step1;
        step0 = step1;
        step1 = step2;
    }

    return step1;
}

int main()
{
    std::cout<<climbStairs(4)<<std::endl;


    system("pause");
    return 0;
}

