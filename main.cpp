#include <iostream>
#include <map>
#include <string>
#include <vector>

//std::vector<std::string> letterCombinations(std::string digits)
//{
//    std::map<char, std::string> digitalpha = {{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"},
//                                            {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};

//    std::string::size_type sz = digits.size();
//    std::vector<std::string> res;
//    char ch;
//    std::string s;
//    for(std::string::size_type i = 0; i != sz; ++ i)
//    {
//        ch = digits[i];
//        if(i == 0)
//        {
//            for(std::string::size_type j = 0; j != digitalpha[ch].size(); ++ j)
//            {
//                s = digitalpha[ch][j];
//                res.push_back(s);
//            }
//        }
//        else
//        {
//            std::vector<std::string> tmp;
//            for(std::vector<std::string>::size_type j = 0; j != res.size(); ++ j)
//            {
//                for(std::string::size_type k = 0; k != digitalpha[ch].size(); ++ k)
//                    tmp.push_back(res[j]+digitalpha[ch][k]);
//            }
//            res = tmp;
//        }
//    }

//    return res;
//}

void solver(std::string& digits, int index, std::map<char, std::string>& digitalpha,
            std::string& tmp, std::vector<std::string>& res)
{
    if(index == digits.size())
    {
        res.push_back(tmp);
        return;
    }

    std::string letter = digitalpha[digits[index]];
    for(int i = 0; i != letter.size(); ++ i)
    {
        tmp += letter[i];
        solver(digits, index + 1, digitalpha, tmp, res);
        tmp.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits)
{
    std::map<char, std::string> digitalpha = {{'0', ""}, {'1', ""},{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"},
                                              {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};

    std::string tmp;
    std::vector<std::string> res;
    if(digits.empty())
        return res;

    solver(digits, 0, digitalpha, tmp, res);

    return res;
}

int main()
{
    std::string digits = "23";
    std::vector<std::string> res = letterCombinations(digits);
    for(std::vector<std::string>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<res[i]<<std::endl;

    system("pause");
    return 0;
}

