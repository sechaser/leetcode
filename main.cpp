#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
    int left = 0, right = numbers.size() - 1;
    std::vector<int> res;

    while(left < right)
    {
        if(numbers[left] + numbers[right] == target)
        {
            res.push_back(left+1);
            res.push_back(right+1);
            return res;
        }
        else if(numbers[left] + numbers[right] > target)
            -- right;
        else
            ++ left;
    }
}

int main()
{
    std::vector<int> numbers = {2, 7, 11, 15};
    std::vector<int> res = twoSum(numbers, 13);

    std::cout<<res[0]<<" "<<res[1]<<std::endl;

    system("pause");
    return 0;
}

