#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


//*********************************Dynamic programming**********************************
int uniquePaths(int m, int n)
{
    std::vector<int> dp(n+1, 1);
    for(int i = 2; i <= m; ++ i)
    {
        for(int j = 2; j <= n; ++ j)
            dp[j] = dp[j] + dp[j-1];
    }

    return dp[n];
}


//**************************************combination****************************|
//int uniquePaths(int m, int n)
//{
//    double fenzi = 1;
//    double fenmu = 1;

//    int small = m < n ? m-1 : n-1;
//    int big   = m < n ? n-1 : m-1;

//    for(int i = 1; i <= small; ++ i)
//    {
//        fenmu *= i;
//        fenzi *= small + big + 1 - i;
//    }

//    return (int)(fenzi/fenmu);
//}

int main()
{
    std::cout<<uniquePaths(2, 2)<<std::endl;

    system("pause");
    return 0;
}

