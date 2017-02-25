#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//void setZeros(std::vector<std::vector<int> >& matrix)
//{
//    if(matrix.empty())
//        return;

//    int m = matrix.size(), n = matrix[0].size();
//    std::vector<std::vector<int> > dp;
//    dp.reserve(m);

//    for(int i = 0; i != m; ++ i)
//    {
//        std::vector<int> onerow;
//        for(int j = 0; j != n; ++ j)
//        {
//            if(matrix[i][j] == 0)
//                onerow.push_back(j);
//        }
//        dp.push_back(onerow);
//    }
//    std::cout<<"hello"<<std::endl;

//    for(int i = 0; i != m; ++ i)
//    {
//        if(!dp[i].empty())
//        {
//            //set row to zeros
//            for(int j = 0; j != n; ++ j)
//                matrix[i][j] = 0;

//            //set column to zeros
//            for(int j = 0; j != m; ++ j)
//                matrix[j][dp[i][0]] = 0;

//            for(int j = 1; j < dp[i].size(); ++ j)
//            {
//                for(int k = 0; k != m; ++ k)
//                    matrix[k][dp[i][j]] = 0;
//            }
//        }
//    }
//}

void setZeroes(std::vector<std::vector<int> >& matrix)
{
    if(matrix.empty())
        return;

    int row = matrix.size(), col = matrix[0].size();
    bool firstRow = false, firstCol = false;

    for(int i = 0; i != row; ++ i)
    {
        if(matrix[i][0] == 0)
        {
            firstCol = 1;
            break;
        }
    }

    for(int i = 0; i != col; ++ i)
    {
        if(matrix[0][i] == 0)
        {
            firstRow = 1;
            break;
        }
    }

    for(int i = 1; i != row; ++ i)
    {
        for(int j = 1; j != col; ++ j)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][i] = 0;
            }
        }
    }

    for(int i = 1; i != row; ++ i)
    {
        for(int j = 1; j != col; ++ j)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if(firstRow)
    {
        for(int i = 0; i != col; ++ i)
            matrix[0][i] = 0;
    }

    if(firstCol)
    {
        for(int i = 0; i != row; ++ i)
            matrix[i][0] = 0;
    }
}

int main()
{
    std::vector<std::vector<int> > matrix{{1,0,0,1}, {2,0,1,1}, {1,1,1,1}};
    setZeros(matrix);

    for(std::vector<std::vector<int> >::size_type i = 0; i != matrix.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != matrix[i].size(); ++ j)
            std::cout<<std::setw(4)<<matrix[i][j];
        std::cout<<std::endl;
    }


    system("pause");
    return 0;
}

