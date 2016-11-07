#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool searchMatrix(std::vector<std::vector<int> >& matrix, int target)
{
    if(matrix.empty())
        return false;

    int row = matrix.size(), col = matrix[0].size();
    int num = row * col;

    int l = 0, r = num - 1;

    int m;
    while(l <= r)
    {
        m = l + (r - l)/2;
        std::cout<<l<<" "<<m<<" "<<r<<std::endl;

        if(matrix[m/col][m%col] == target)
            return true;
        else if(matrix[m/col][m%col] < target)
            l = m + 1;
        else
            r = m - 1;
    }

    return false;
}


int main()
{
    std::vector<std::vector<int> > matrix{{1, 7}, {8, 10}};
    std::cout<<searchMatrix(matrix, 90)<<std::endl;


    system("pause");
    return 0;
}

