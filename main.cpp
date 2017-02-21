#include <iostream>
#include <regex>

//bool isMatch(std::string s, std::string p)
//{
//    std::regex pattern(p);

//    if(std::regex_match(s, pattern))
//        return true;
//    else
//        return false;
//}


bool isMatch(std::string s, std::string p) {
    /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
    int m = s.size(), n = p.size();
    std::vector<std::vector<bool>> f(m + 1, std::vector<bool>(n + 1, 0));

    f[0][0] = true;
    for (int i = 1; i <= m; i++)
        f[i][0] = false;

    for (int j = 1; j <= n; j++)
        f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] != '*')
                f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
            else
                f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
        }
    }

    return f[m][n];
}

int main()
{
    std::string p = "c*a*b";
    std::string s = "aab";
    bool res;
    res = isMatch(s, p);
    std::cout<<res<<std::endl;

    return 0;
}

