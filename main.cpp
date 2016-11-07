#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

void setZeros(std::vector<std::vector<int> >& matrix)
{
    if(matrix.empty())
        return;

    int m = matrix.size(), n = matrix[0].size();
    std::vector<std::vector<int> > dp;
    dp.reserve(m);

    for(int i = 0; i != m; ++ i)
    {
        std::vector<int> onerow;
        for(int j = 0; j != n; ++ j)
        {
            if(matrix[i][j] == 0)
                onerow.push_back(j);
        }
        dp.push_back(onerow);
    }
    std::cout<<"hello"<<std::endl;

    for(int i = 0; i != m; ++ i)
    {
        if(!dp[i].empty())
        {
            //set row to zeros
            for(int j = 0; j != n; ++ j)
                matrix[i][j] = 0;

            //set col to zeros
            for(int j = 0; j != m; ++ j)
                matrix[j][dp[i][0]] = 0;

            for(int j = 1; j < dp[i].size(); ++ j)
            {
                for(int k = 0; k != m; ++ k)
                    matrix[k][dp[i][j]] = 0;
            }
        }
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

