#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//************************************Time O(n^2) Space O(n^2)***************************************
//void rotate(std::vector<std::vector<int> >& matrix)
//{
//    size_t n = matrix.size();
//    if(n == 0)
//        return ;

//    std::vector<std::vector<int> > temp(matrix);
//    for(std::vector<std::vector<int> >::size_type i = 0; i != n; ++ i)
//    {
//        for(int j = 0; j != n; ++ j)
//            matrix[i][j] = temp[n-j-1][i];
//    }
//}


//Time:O(n^2), Space:O(1)
void rotate(std::vector<std::vector<int> >& matrix)
{
    size_t n = matrix.size();
    if(n == 0)
        return;

    int temp;
    for(int i = 0; i < n; ++ i)
    {
        for(int j = i + 1; j < n; ++ j)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(int i = 0; i < n; ++ i)
        std::reverse(matrix[i].begin(), matrix[i].end());
}

int main()
{
    std::vector<std::vector<int> > matrix{{1,2,3}, {4,5,6}, {7,8,9}};
    rotate(matrix);

    for(std::vector<std::vector<int> >::size_type i = 0; i != matrix.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != matrix[i].size(); ++ j)
            std::cout<<matrix[i][j]<<" ";
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

