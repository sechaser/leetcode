#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>

//Method 1
//double myPow(double x, int n)
//{
//    return std::pow(x, n);
//}


//Method 2
//double helper(double x, int n)
//{
//    if(n == 0)
//        return 1;

//    double res = helper(x, n/2);
//    res *= res;
//    if(n%2)
//        res *= x;

//    return res;
//}

//double myPow(double x, int n)
//{
//    if(n >= 0)
//        return helper(x, n);
//    else
//        return 1.0/helper(x, -n);
//}



int main()
{
    long double res = myPow(1.2, 2);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

