#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool isPrime(int n)
{
    for(int i = 2; i <= std::sqrt(n); ++ i)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}

int countPrimes(int n)
{
    if(n <= 2)
        return 0;

    int count = 0;
    for(int i = 2; i < n; ++ i)
    {
        if(isPrime(i))
            ++ count;
    }

    return count;
}


int main()
{
    std::cout<<countPrimes(6)<<std::endl;

    system("pause");
    return 0;
}

