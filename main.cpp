#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<std::vector<int> > generate(int numRows)
{
    std::vector<std::vector<int> > res;
    if(numRows <= 0)
        return res;

    for(int row = 1; row <= numRows; ++ row)
    {
        std::vector<int> rowRes(row, 1);
        if(row <= 2)
            res.push_back(rowRes);
        else
        {
            for(int i = 1; i < row-1; ++ i)
                rowRes[i] = res[row-2][i-1] + res[row-2][i];
            res.push_back(rowRes);
        }
    }

    return res;
}

int main()
{
    std::vector<std::vector<int> > res = generate(5);
    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<std::setw(4)<<res[i][j];
        std::cout<<std::endl;
    }


    system("pause");
    return 0;
}

