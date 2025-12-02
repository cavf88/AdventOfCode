
#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// PARSING
vector<string> parseRanges(const string& line)
{
    vector<string> parsedRange;

    size_t pos = 0;
    while(1)
    {
        auto newPos = line.find(",", pos);
        const string tempStr = line.substr(pos, newPos-pos);
        parsedRange.push_back(tempStr.c_str());
        pos = newPos+1;

        if(newPos == string::npos)
        {
            break;
        }
    }

    return parsedRange;
}

pair<string, string> parseRange(const string& line)
{
    size_t pos = 0;
    auto newPos = line.find("-", pos);
    const string firstHalf = line.substr(0, newPos-pos);
    const string secondHalf = line.substr(newPos+1, line.length());

    return pair<string,string>(firstHalf, secondHalf);

}


// PART 1

const unsigned long long getInvalidIdPart1(const pair<string, string> range)
{
    unsigned long long retVal = 0;
    const string firstHalf = range.first.substr(0, range.first.length() / 2);
    const string secondHalf = range.first.substr(range.first.length() / 2, range.first.length());
    if(firstHalf == secondHalf)
    {
        retVal = stoull(range.first.c_str(), nullptr, 0);
        cout << "Invalid ID: " << retVal << endl;
    }

    return retVal;
}

int main()
{

    string inputLine;
    fstream inputFile("input.txt");
    getline(inputFile, inputLine);
    uint64_t invalidIdsSumPart1 = 0;
    uint64_t invalidIdsSumPart2 = 0;

    const regex expression(R"(^(\d+)\1+$)");

    const vector<string> ranges = parseRanges(inputLine);

    for(auto it = ranges.begin(); it != ranges.end(); ++it)
    {
        pair<string, string> range = parseRange(*it);

        while(range.first != range.second)
        {
            unsigned long long firstInt = stoull(range.first.c_str(), nullptr, 0);

            // Part1
            if(range.first.length() % 2 == 0)
            {

                invalidIdsSumPart1 += getInvalidIdPart1(range);
            }

            // Part 2
            {
                smatch matchStr;
                if(regex_match(range.first, expression))
                {
                    invalidIdsSumPart2 += firstInt;
                }
            }

            stringstream ss;
            ss << firstInt + 1;
            range.first = ss.str();
        }
        // use case last number of the range for [X, Y] instead ot [X,Y>
        invalidIdsSumPart1 += getInvalidIdPart1(range);
    }


    cout << inputLine << endl;
    cout << "Part1: Values of ID: " << invalidIdsSumPart1;
    cout << "Part2: Values of ID: " << invalidIdsSumPart2;

    return 0;
}