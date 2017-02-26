#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

//std::string minWindow(std::string s, std::string t)
//{
//    std::string::size_type ssz = s.size(), tsz = t.size();

//    //Record occurrences of every character in string "t".
//    std::unordered_map<char, int> Tcount;
//    for(std::string::size_type i = 0; i != tsz; ++ i)
//        ++ Tcount[t[i]];

//    //Record the minmum window conclude string "t"
//    int winStart = -1, winEnd = ssz;

//    //Record occurrences of every character in string "t" in window [beg, end]
//    std::unordered_map<char, int> foundCount;

//    //Record the number of characters in "t" we have found so far
//    int counter = 0;

//    for(int beg = 0, end = 0; end != ssz; ++ end)
//    {
//        //This character has occurred in string "t".
//        if(Tcount[s[end]] != 0)
//        {
//            ++ foundCount[s[end]];

//            //Find a character
//            if(foundCount[s[end]] <= Tcount[s[end]])
//                ++ counter;

//            //Find a window include "t"
//            if(counter == tsz)
//            {
//                while(Tcount[s[beg]] == 0 || foundCount[s[beg]] > Tcount[s[beg]])
//                {
//                    //Belong to the second solution "foundCount[s[beg]] > Tcount[s[beg]]"
//                    if(Tcount[s[beg]] != 0)
//                        -- foundCount[s[beg]];

//                    ++ beg;
//                }

//                //Update the minmum window
//                if(winEnd - winStart > end - beg)
//                {
//                    winStart = beg;
//                    winEnd   = end;
//                }

//                -- foundCount[s[beg]];
//                ++ beg;
//                -- counter;
//            }
//        }
//    }

//    return winStart == (-1) ?  "" : s.substr(winStart, winEnd - winStart + 1);
//}


std::string minWindow(std::string s, std::string t)
{
    std::unordered_map<char, int> Tcount;
    for(std::string::size_type i = 0; i != t.size(); ++ i)
        ++ Tcount[t[i]];

    int min_start = 0, min_end = s.size() - 1;
    std::unordered_map<char, int> foundCount;

    int cur_start = 0;
    int counter = 0;
    bool foundFlag = 0;

    for(int cur_end = 0; cur_end != s.size(); ++ cur_end)
    {
        if(Tcount[s[cur_end]] != 0)
        {
            ++ foundCount[s[cur_end]];

            if(foundCount[s[cur_end]] <= Tcount[s[cur_end]])
                ++ counter;

            if(counter == t.size())
            {
                foundFlag = 1;
                while(Tcount[s[cur_start]] == 0 || foundCount[s[cur_start]] > Tcount[s[cur_start]])
                {
                    if(Tcount[s[cur_start]] != 0)
                        --foundCount[s[cur_start]];
                    ++ cur_start;
                }

                if(min_end - min_start > cur_end - cur_start)
                {
                    min_end   = cur_end;
                    min_start = cur_start;
                }

                -- foundCount[s[cur_start]];
                ++ cur_start;
                -- counter;
            }
        }
    }

    std::string res;
    if(foundFlag)
        res = s.substr(min_start, min_end - min_start + 1);
    return res;
}


int main()
{
    std::string s = "a", t = "aa";
    std::string res = minWindow(s, t);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

