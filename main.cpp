#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>

int removeDuplicates(std::vector<int>& nums)
{
    std::vector<int>::iterator it = std::unique(nums.begin(), nums.end());

    return (it-nums.begin());
}

int main()
{
    std::vector<int> iv{1, 1, 2, 3, 4, 5, 5};
    int res = removeDuplicates(iv);

    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

