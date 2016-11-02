#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//********************************************Time limit exceed*****************************************
//void swap(std::string& s, int i, int j)
//{
//    char ch = s[i];
//    s[i] = s[j];
//    s[j] = ch;
//}

//void allRange(std::string& s, std::vector<std::string>& res, int beg, int n)
//{
//    if(beg == n)
//    {
//        res.push_back(s);
//        return;
//    }

//    for(int i = beg; i < n; ++ i)
//    {
//        swap(s, beg, i);
//        allRange(s, res, beg+1, n);
//        swap(s, beg, i);
//    }
//}

//std::string getPermutation(int n, int k)
//{
//    std::vector<std::string> res;
//    std::stringstream ss;
//    for(int i = 1; i <= n; ++ i)
//        ss<<i;
//    std::string s = ss.str();

//    allRange(s, res, 0, n);
//    std::sort(res.begin(), res.end());
//    return res[k-1];
//}

int factorial(int n)
{
    if(n <= 1)
        return 1;

    return n * factorial(n - 1);
}


char solver(std::string& s, int& k)
{
    int jiecheng = factorial(s.size() - 1);
    int num = (k-1) / jiecheng;

    char res = s[num];
    s.erase(num, 1);
    k  -= num * jiecheng;

    return res;
}

std::string getPermutation(int n, int k)
{
    std::string str = std::string("123456789").substr(0, n);
    std::string res(n, '0');

    for(int i = 0; i < n; ++ i)
        res[i] = solver(str, k);

    return res;
}

int main()
{
    std::string res = getPermutation(9, 2111);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

