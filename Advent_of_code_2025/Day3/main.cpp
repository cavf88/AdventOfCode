#include <fstream>
#include <iostream>
#include <string>

using namespace std;

static const char ASCII_ZERO = 48;
static const char ASCII_NINE = 57;


int findHighestNumberInString(const string& s, const int highestNumber = 0, int pos1 = 0, int pos2 = 1)
{
    if(pos1 == s.length() - 2 && pos2 == s.length() - 1)
    {
        const int newHighNumber = ((s.at(pos1) - ASCII_ZERO) * 10) + (s.at(pos2) - ASCII_ZERO);
        return (highestNumber > newHighNumber) ? highestNumber : newHighNumber;
    }

    if(pos2 == s.length())
    {
        ++pos1;
        pos2 = pos1;
    }
    
    int newHighNumber = ((s.at(pos1) - ASCII_ZERO) * 10) + (s.at(pos2) - ASCII_ZERO);
    if(pos2 == pos1)
        newHighNumber = 0;
    //cout << newHighNumber << endl;
    return findHighestNumberInString(s, (highestNumber > newHighNumber) ? highestNumber : newHighNumber, pos1, ++pos2);
}

int main()
{
    string inputLine;
    fstream inputFile("test_input.txt");
    int firstHighesValPos = 0;
    int secondHighesValPos = 0;
    uint64_t sumPart1 = 0;
    while(getline(inputFile, inputLine))
    {
        {
            const int hightesNumberInString = findHighestNumberInString(inputLine);
            cout << "voltage: " << hightesNumberInString << endl;
            sumPart1 += hightesNumberInString;
        }
    }

    cout << "Part 1: " << sumPart1 << endl;

    return 0;
}