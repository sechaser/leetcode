#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<int> spiralOrder(std::vector<std::vector<int> >& matrix)
{
    std::vector<int> res;
    if(matrix.empty())
        return res;

    int row = matrix.size();
    int col = matrix[0].size();

    int ring = (row > col) ? (col + 1)/2 : (row + 1)/2;
    int cborder = col, rborder = row;

    for(int i = 0; i != ring; ++ i, cborder -= 2, rborder -= 2)
    {
        for(int j = i; j != i + cborder; ++ j)
            res.push_back(matrix[i][j]);
        for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
            std::cout<<std::setw(4)<<res[i];
        std::cout<<std::endl;


        for(int j = i+1; j != i + rborder; ++ j)
            res.push_back(matrix[j][i + cborder - 1]);
        for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
            std::cout<<std::setw(4)<<res[i];
        std::cout<<std::endl;


        if(cborder == 1 || rborder == 1)
            break;

        for(int j = i + cborder - 2; j >= i; -- j)
            res.push_back(matrix[i + rborder - 1][j]);
        for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
            std::cout<<std::setw(4)<<res[i];
        std::cout<<std::endl;


        for(int j = i + rborder - 2; j > i; -- j)
            res.push_back(matrix[j][i]);
        for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
            std::cout<<std::setw(4)<<res[i];
        std::cout<<std::endl;
    }

    return res;
}

int main()
{
    std::vector<std::vector<int> > matrix{{1,2,3}, {4,5,6}, {7,8,9}};
    std::vector<int> res = spiralOrder(matrix);

    for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<std::setw(4)<<res[i];
    std::cout<<std::endl;

    system("pause");
    return 0;
}

