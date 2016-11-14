#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool solver(std::vector<std::vector<char> >& board, std::string word, int index, int row, int col, std::vector<std::vector<bool> >& used)
{
    if(index == word.size())
        return true;

    if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || used[row][col] || board[row][col] != word[index])
        return false;

    //used[row][col] = true;
    char tmp = board[row][col];
    board[row][col] = '#';

    //Up
    if(solver(board, word, index + 1, row - 1, col, used))
        return true;

    //Down
    if(solver(board, word, index + 1, row + 1, col, used))
        return true;

    //Left
    if(solver(board, word, index + 1, row, col - 1, used))
        return true;

    //Right
    if(solver(board, word, index + 1, row, col + 1, used))
        return true;

    //used[row][col] = false;
    board[row][col] = tmp;

    return false;
}

bool exist(std::vector<std::vector<char> >& board, std::string word)
{
    if(word.empty())
        return true;
    if(board.empty())
        return false;

    std::vector<std::vector<bool> > used(board.size(), std::vector<bool>(board[0].size(), 0));
    for(std::vector<std::vector<char> >::size_type row = 0; row != board.size(); ++ row)
    {
        for(std::vector<char>::size_type col = 0; col != board[0].size(); ++ col)
        {
            if(solver(board, word, 0, row, col, used))
                return true;
        }
    }

    return false;
}

int main()
{
    std::vector<std::vector<char> > board{std::vector<char>{'A', 'B', 'C', 'E'}, std::vector<char>{'S', 'F', 'C', 'S'},
                                         std::vector<char>{'A', 'D', 'E', 'E'}};
    std::cout<<exist(board, "ABCB")<<std::endl;

    system("pause");
    return 0;
}

