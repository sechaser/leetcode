#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <string.h>

#define jiuGongGe 9

bool checkValid(bool vec[], int val)
{
    if(vec[val] == 1)
        return false;
    vec[val] = 1;
    return true;
}

bool isValidSudoku(std::vector<std::vector<char> >& board)
{
    bool rowValid[jiuGongGe+1] = {0};
    bool columnValid[jiuGongGe][jiuGongGe+1] = {0};
    bool subBoardValid[jiuGongGe][jiuGongGe+1] = {0};

    for(int i = 0; i != jiuGongGe; ++ i)
    {
        memset(rowValid, 0, sizeof(rowValid));
        for(int j = 0; j != jiuGongGe; ++ j)
        {
            if(board[i][j] != '.')
            {
                if(!checkValid(rowValid, board[i][j]-'0') ||
                   !checkValid(columnValid[j], board[i][j]-'0') ||
                   !checkValid(subBoardValid[i/3*3+j/3], board[i][j]-'0'))
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    system("pause");
    return 0;
}

