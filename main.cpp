#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//**************************************Method 1*************************************
//void solver(int& res, int row, int col)
//{
//    if(row == 0 && col == 0)
//    {
//        ++ res;
//        return;
//    }

//    if(row > 0)
//        solver(res, row - 1, col);

//    if(col > 0)
//        solver(res, row, col - 1);
//}


//int uniquePaths(int m, int n)
//{
//    int res = 0;
//    solver(res, m - 1, n - 1);

//    return res;
//}

//*******************************Method 2********************************
//int uniquePaths(int m, int n)
//{
//    if(m == 1 || n == 1)
//        return 1;

//    return uniquePaths(m, n-1) + uniquePaths(m-1, n);
//}


//*********************************Dynamic programming**********************************
//int uniquePaths(int m, int n)
//{
//    std::vector<std::vector<int> > dp(m+1, std::vector<int>(n+1, 1));
//    for(int i = 2; i <= m; ++ i)
//    {
//        for(int j = 2; j <= n; ++ j)
//            dp[i][j] = dp[i][j-1] + dp[i-1][j];
//    }

//    return dp[m][n];
//}

//int uniquePaths(int m, int n)
//{
//    std::vector<int> dp(n+1, 1);
//    for(int i = 2; i <= m; ++ i)
//    {
//        for(int j = 2; j <= n; ++ j)
//            dp[j] = dp[j] + dp[j-1];
//    }

//    return dp[n];
//}


//**************************************combination****************************|
int uniquePaths(int m, int n)
{
    double fenzi = 1;
    double fenmu = 1;

    int small = m < n ? m-1 : n-1;
    int big   = m < n ? n-1 : m-1;

    for(int i = 1; i <= small; ++ i)
    {
        fenmu *= i;
        fenzi *= small + big + 1 - i;
    }

    return (int)(fenzi/fenmu);
}

int main()
{
    std::cout<<uniquePaths(23, 12)<<std::endl;

    system("pause");
    return 0;
}

