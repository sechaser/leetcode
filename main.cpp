#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <utility>

void fill(std::vector<std::vector<char> >& board, int i, int j, char oldc, char newc)
{
    int row = board.size(), col = board[0].size();
    if(i < 0 || j < 0 || i >= row || j >= col || board[i][j] != oldc)
        return;

    std::stack<std::pair<int, int> > s;
    s.push(std::make_pair(i, j));

    while(!s.empty())
    {
        i = s.top().first;
        j = s.top().second;
        s.pop();

        board[i][j] = newc;

        if(i > 0 && board[i-1][j] == oldc)
            s.push(std::make_pair(i-1, j));
        if(i < row-1 && board[i+1][j] == oldc)
            s.push(std::make_pair(i+1, j));
        if(j > 0 && board[i][j-1] == oldc)
            s.push(std::make_pair(i, j-1));
        if(j < col-1 && board[i][j+1] == oldc)
            s.push(std::make_pair(i, j+1));
    }
}

void fillBoarders(std::vector<std::vector<char> >& board, char oldc, char newc)
{
    int row = board.size(), col = board[0].size();

    for(int i = 0; i != row; ++ i)
    {
        if(board[i][0] == oldc)
            fill(board, i, 0, oldc, newc);
        if(board[i][col-1] == oldc)
            fill(board, i, col-1, oldc, newc);
    }

    for(int i = 0; i != col; ++ i)
    {
        if(board[0][i] == oldc)
            fill(board, 0, i, oldc, newc);
        if(board[row-1][i] == oldc)
            fill(board, row-1, i, oldc, newc);
    }
}

void replace(std::vector<std::vector<char> >& board, char oldc, char newc)
{
    int row = board.size(), col = board[0].size();
    for(int i = 0; i != row; ++ i)
    {
        for(int j = 0; j != col; ++ j)
        {
            if(board[i][j] == oldc)
                board[i][j] = newc;
        }
    }
}

void solve(std::vector<std::vector<char> >& board)
{
    if(board.size() < 3 || board[0].size() < 3)
        return;

    fillBoarders(board, 'O', 'Y');
    replace(board, 'O', 'X');
    fillBoarders(board, 'Y', 'O');
}

int main()
{
    std::vector<std::vector<char> > board{{'X','X','X','X'}, {'X','O','O','X'}, {'X','X','O','X'}, {'X','O','X','X'}};
    solve(board);

    for(int i = 0; i != board.size(); ++ i)
    {
        for(int j = 0; j != board[0].size(); ++ j)
            std::cout<<std::setw(4)<<board[i][j];
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

