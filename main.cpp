#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int solver(int n)
{
    int sum = 0;
    while(n)
    {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }

    return sum;
}

bool isHappy(int n )
{
    int slow = n, fast = n;
    do
    {
        slow = solver(slow);
        fast = solver(fast);
        fast = solver(fast);
    }while(slow != fast);

    return slow==1;
}

int main()
{
    std::cout<<isHappy(19)<<std::endl;

    system("pause");
    return 0;
}

