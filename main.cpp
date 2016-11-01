#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <math.h>




bool isValid(std::vector<int>& state, int row, int col)
{
    for(std::vector<int>::size_type i = 0; i != row; ++ i)
    {
        if(state[i] == col || std::abs(row - i) == std::abs(col - state[i]))
            return false;
    }

    return true;
}

void solver(std::vector<int>& state, int& res, int row)
{
    if(row == state.size())
    {
        ++ res;
        return;
    }

    for(int col = 0; col != state.size(); ++ col)
    {
        if(isValid(state, row, col))
        {
            state[row] = col;
            solver(state, res, row + 1);
            state[row] = (-1);
        }
    }
}

int solveNQueens(int n)
{
    int res = 0;
    std::vector<int> state(n, -1);

    solver(state, res, 0);
    return res;
}




int main()
{
    int res = solveNQueens(5);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

