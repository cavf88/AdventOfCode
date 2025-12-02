
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


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
    uint64_t invalidIdsSum = 0;

    const vector<string> ranges = parseRanges(inputLine);

    for(auto it = ranges.begin(); it != ranges.end(); ++it)
    {
        //cout << *it << endl;
        pair<string, string> range = parseRange(*it);
        //cout << range.first << "-" << range.second << endl;

        while(range.first != range.second)
        {
            unsigned long long firstInt = stoull(range.first.c_str(), nullptr, 0);

            if(range.first.length() % 2 == 0)
            {

                invalidIdsSum += getInvalidIdPart1(range);
            }
            //const long int firstInt = atol(range.first.c_str());4
            stringstream ss;
            ss << firstInt + 1;
            range.first = ss.str();
            //cout << range.first << "-" << range.second << endl;
        }
        // use case last number of the range for [X, Y] instead ot [X,Y>
        invalidIdsSum += getInvalidIdPart1(range);
    }


    cout << inputLine << endl;
    cout << "Values of ID: " << invalidIdsSum;

    return 0;
}