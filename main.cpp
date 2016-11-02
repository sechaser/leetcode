#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <math.h>

//******************************************Method 1*******************************************
//bool isValid(std::vector<std::string>& curr, int row, int col)
//{
//    //Check if every column is OK
//    for(int i = 0; i != row; ++ i)
//    {
//        if(curr[i][col] == 'Q')
//            return false;
//    }

//    //left diagonal line
//    for(int i = row-1, j = col - 1; i >= 0 && j >= 0; -- i, -- j)
//    {
//        if(curr[i][j] == 'Q')
//            return false;
//    }

//    //right diagonal line
//    for(int i = row - 1, j = col + 1; i >= 0 && j < curr.size(); -- i, ++ j)
//    {
//        if(curr[i][j] == 'Q')
//            return false;
//    }

//    return true;
//}

//void solver(std::vector<std::string>& curr, std::vector<std::vector<std::string> >& res, int row)
//{
//    if(row == curr.size())
//    {
//        res.push_back(curr);
//        return;
//    }

//    for(int col = 0; col != curr.size(); ++ col)
//    {
//        if(isValid(curr, row, col))
//        {
//            curr[row][col] = 'Q';
//            solver(curr, res, row+1);
//            curr[row][col] = '.';
//        }
//    }
//}

//std::vector<std::vector<std::string> > solveNQueens(int n)
//{
//    std::vector<std::vector<std::string> > res;
//    std::vector<std::string> curr(n, std::string(n, '.'));

//    solver(curr, res, 0);
//    return res;
//}



//*****************************************Method 2******************************************

//bool isValid(std::vector<int>& state, int row, int col)
//{
//    for(std::vector<int>::size_type i = 0; i != row; ++ i)
//    {
//        if(state[i] == col || std::abs(row - i) == std::abs(col - state[i]))
//            return false;
//    }

//    return true;
//}

//void solver(std::vector<int>& state, std::vector<std::vector<std::string> >& res, int row)
//{
//    if(row == state.size())
//    {
//        std::vector<std::string> curr(state.size(), std::string(state.size(), '.'));
//        for(std::vector<int>::size_type i = 0; i != state.size(); ++ i)
//            curr[i][state[i]] = 'Q';
//        res.push_back(curr);
//        return;
//    }

//    for(int col = 0; col != state.size(); ++ col)
//    {
//        if(isValid(state, row, col))
//        {
//            state[row] = col;
//            solver(state, res, row + 1);
//            state[row] = (-1);
//        }
//    }
//}

//std::vector<std::vector<std::string> > solveNQueens(int n)
//{
//    std::vector<std::vector<std::string> > res;
//    std::vector<int> state(n, -1);

//    solver(state, res, 0);
//    return res;
//}


//************************************************Method 3******************************************

//bool isValid(std::vector<int>& state, int row,  int col)
//{
//    for(std::vector<int>::size_type i = 0; i != row; ++ i)
//    {
//        if(state[i] == col || std::abs(row - i) == std::abs(col - state[i]))
//            return false;
//    }

//    return true;
//}

//std::vector<std::vector<std::string> > solveNQueens(int n)
//{
//    std::vector<int> state(n, -1);
//    std::vector<std::vector<std::string> > res;

//    for(int row = 0, col; ;)
//    {
//        for(col = state[row] + 1; col != n; ++ col)
//        {
//            if(isValid(state, row, col))
//            {
//                state[row] = col;
//                if(row == n -1)
//                {
//                    std::vector<std::string> curr(n, std::string(n, '.'));
//                    for(int i = 0; i != n; ++ i)
//                        curr[i][state[i]] = 'Q';
//                    res.push_back(curr);
//                }
//                else
//                {
//                    ++ row;
//                    break;
//                }
//            }
//        }

//        if(col == n)
//        {
//            if(row == 0)
//                break;
//            state[row] = -1;
//            -- row;
//        }
//    }

//    return res;
//}

//std::vector<std::vector<std::string> > solveNQueens(int n)
//{
//    std::vector<std::vector<std::string> > res;
//    std::vector<int> state(n, -1);

//    int row = 0, col = 0;
//    while(row != n)
//    {
          //对第row行的每一列进行探测
//        while(col != n)
//        {
              //可以放置皇后
//            if(isValid(state, row, col))
//            {
//                state[row] = col;    //第row行的皇后放置在第col列
                  //第row行放置皇后后，继续探测下一行皇后的位置，此时要把col清零，从下一行的第0列开始
//                col = 0;
//                break;
//            }
//            else
//                ++ col;     //如果第row行的第col列无效，继续探测下一列
//        }

//        if(state[row] < 0)  //第row行没有找到可以放置皇后的位置
//        {
              //回溯到第1行，仍然无法找到可以放置皇后的位置，说明已经找到所有的解，终止程序
//            if(row == 0)
//                break;
              //回溯，修改上一行皇后的位置，继续下一次探测
//            else
//            {
//                -- row;
//                col = state[row] + 1;
//                state[row] = (-1);
//                continue;
//            }
//        }

//        if(row == n - 1)
//        {
//            std::vector<std::string> curr(n, std::string(n, '.'));
//            for(std::vector<int>::size_type i = 0; i != n; ++ i)
//                curr[i][state[i]] = 'Q';
//            res.push_back(curr);

             //从最后一行放置皇后列数的下一列继续探测
//            col = state[row] + 1;
//            state[row] = -1;
//            continue;
//        }

//        ++ row;
//    }

//    return res;
//}


//*******************************************Method 4*****************************************
int upperlim;

void setQueen(std::vector<std::string>& curr, int row, int p, char val)
{
    int col = 0;
    while(!(p & 1))
    {
        p >>= 1;
        ++ col;
    }
    curr[row][col] = val;
}

void solver(int row, int ld, int rd, int index, std::vector<std::string>& curr, std::vector<std::vector<std::string> >& res)
{
    int pos, p;

    if(row != upperlim)
    {
        pos = upperlim & (~(row | ld | rd));

        while(pos)
        {
            p = pos & (~pos + 1);
            pos = pos - p;
            setQueen(curr, index, p, 'Q');
            solver(row | p, (ld | p) << 1, (rd | p) >> 1, index + 1, curr, res);
            setQueen(curr, index, p, '.');
        }
    }
    else
        res.push_back(curr);
}

std::vector<std::vector<std::string> > solveNQueens(int n)
{
    upperlim = (1 << n) - 1;                 //低n位全部置1
    std::vector<std::vector<std::string> > res;
    std::vector<std::string> curr(n, std::string(n, '.'));
    solver(0, 0, 0, 0, curr, res);

    return res;
}


int main()
{
    std::vector<std::vector<std::string> > res = solveNQueens(5);

    for(std::vector<std::vector<std::string> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<std::string>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<res[i][j]<<std::endl;
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

