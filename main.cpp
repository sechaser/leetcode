#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<int> plusOne(std::vector<int>& digits)
{
    std::vector<int>::size_type sz = digits.size();

    int carry = 0;
    for(int i = sz - 1; i >= 0; -- i)
    {
        if(i == sz - 1)
        {
            carry = (digits[i] + 1) / 10;
            digits[i] = (digits[i] + 1) % 10;
        }
        else
        {
            int tmp = carry;
            carry = (digits[i] + carry) / 10;
            digits[i] = (digits[i] + tmp) % 10;
        }
    }

    if(carry)
        digits.insert(digits.begin(), carry);

    return digits;
}


int main()
{
    std::vector<int> digits{9, 8};
    std::vector<int> res = plusOne(digits);

    for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<res[i]<<std::endl;

    system("pause");
    return 0;
}

