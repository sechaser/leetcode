#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::string createLine(std::vector<std::string>& words, int L, int start, int end, int totLen, bool isLast)
{
    std::string res;
    if(start < 0 || end >= words.size() || start > end)
        return res;
    res.append(words[start]);

    int num = end - start + 1;    //The number of words in this line

    //This line only has one word or it is the last line
    if(num == 1 || isLast)
    {
        for(int i = start + 1; i <= end; ++ i)
            res.append(" " + words[i]);

        int j = L - totLen - (num-1);
        res.append(j, ' ');
        return res;
    }

    int k = (L - totLen) / (num-1), m = (L - totLen) % (num-1);
    for(int i = start + 1; i <= end; ++ i)
    {
        int nspace = i - start <= m ? k+1 : k;
        res.append(nspace, ' ');
        res.append(words[i]);
    }

    return res;
}

std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth)
{
    int start = 0, end = -1, totLen = 0;

    std::vector<std::string> res;
    int i = 0;

    while(i < words.size())
    {
        int newLen = totLen + (end - start + 1) + words[i].size();
        if(newLen <= maxWidth)
        {
            end = i;
            totLen += words[i].size();
            ++ i;
        }
        else
        {
            std::string line = createLine(words, maxWidth, start, end, totLen, false);
            res.push_back(line);
            start = i;
            end   = i - 1;
            totLen = 0;
        }
    }

    std::string lastLine = createLine(words, maxWidth, start, end, totLen, true);
    res.push_back(lastLine);

    return res;
}

int main()
{
    std::vector<std::string> words{"This", "is", "an", "example", "of", "text", "justification."};
    std::vector<std::string> res = fullJustify(words, 16);

    for(std::vector<std::string>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<res[i]<<std::endl;

    system("pause");
    return 0;
}

