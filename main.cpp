#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<int> getRow(int rowIndex)
{
    std::vector<int> res(rowIndex+1, 1);
    for(int row = 1; row <= rowIndex; ++ row)
    {
        int prev = 1;
        for(int i = 1; i < row; ++ i)
        {
            int temp = res[i];
            res[i] += prev;
            prev = temp;
        }
    }

    return res;
}


int main()
{
    std::vector<int> res = getRow(3);
    for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<std::setw(4)<<res[i];
    std::cout<<std::endl;

    system("pause");
    return 0;
}

