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

unsigned long long findHighestNumberTwelveBlock(const string& s,
                                                const unsigned long long highestNumber = 0, 
                                                int pos1 = 0,
                                                int pos2 = 1,
                                                int pos3 = 2,
                                                int pos4 = 3,
                                                int pos5 = 4,
                                                int pos6 = 5,
                                                int pos7 = 6,
                                                int pos8 = 7,
                                                int pos9 = 8,
                                                int pos10 = 9,
                                                int pos11 = 10,
                                                int pos12 = 11)
{

    if(pos1 == s.length() - 12)
    {

        const unsigned long long newHighNumber =  stoull(  
                    s.substr(pos1, 1) +
                    s.substr(pos2, 1) +
                    s.substr(pos3, 1) +
                    s.substr(pos4, 1) +
                    s.substr(pos5, 1) +
                    s.substr(pos6, 1) +
                    s.substr(pos7, 1) +
                    s.substr(pos8, 1) +
                    s.substr(pos9, 1) +
                    s.substr(pos10, 1) +
                    s.substr(pos11, 1) + 
                    s.substr(pos12, 1));
        //cout << "newHighNumber : " << newHighNumber << endl;
        //cout << "highestNumber: " << highestNumber << endl;
        return (highestNumber > newHighNumber) ? highestNumber : newHighNumber;
    }

    
    //unsigned long long newHighNumber =  stoull(  s.substr(pos1, 1) +
    //                s.substr(pos2, 1) +
    //                s.substr(pos3, 1) +
    //                s.substr(pos4, 1) +
    //                s.substr(pos5, 1) +
    //                s.substr(pos6, 1) +
    //                s.substr(pos7, 1) +
    //                s.substr(pos8, 1) +
    //                s.substr(pos9, 1) +
    //                s.substr(pos10, 1) +
    //                s.substr(pos11, 1) + 
    //                s.substr(pos12, 1));

    if(pos12 == s.length() - 1)
    {
        ++pos11;
        pos12 = pos11 + 1;
    }

    if(pos11 == s.length() - 2)
    {
        ++pos10;
        pos11 = pos10 + 1;
        pos12 = pos11 + 1;
    }

    if(pos10 == s.length() - 3)
    {
        ++pos9;
        pos10 = pos9 + 1;
        pos11 = pos10 + 1;
        pos12 = pos11 + 1;
    }

    if(pos9 == s.length() - 4)
    {
        ++pos8;
        pos9 = pos8 + 1;
        pos10 = pos9 + 1;
        pos11 = pos10 + 1;
        pos12 = pos11 + 1;
    }

    if(pos8 == s.length() - 5)
    {
        ++pos7;
        pos8 = pos7 + 1;
        pos9 = pos8 + 1;
        pos10 = pos9 + 1;
        pos11 = pos10 + 1;
        pos12 = pos11 + 1;
    }

    if(pos7 == s.length() - 6)
    {
        ++pos6;
        pos7 = pos6 + 1;
        pos8 = pos7 + 1;
        pos9 = pos8 + 1;
        pos10 = pos9 + 1;
        pos11 = pos10 + 1;
        pos12 = pos11 + 1;
    }

    if(pos6 == s.length() - 7)
    {
        ++pos5;
        pos6 = pos5 + 1;
        pos7 = pos6 + 1;
        pos8 = pos7 + 1;
        pos9 = pos8 + 1;
        pos10 = pos9 + 1;
        pos11 = pos10 + 1;
        pos12 = pos11 + 1;
    }

    if(pos5 == s.length() - 8)
    {
        ++pos4;
        pos5 = pos4 + 1;
        pos6 = pos5 + 1;
        pos7 = pos6 + 1;
        pos8 = pos7 + 1;
        pos9 = pos8 + 1;
        pos10 = pos9 + 1;
        pos11 = pos10 + 1;
        pos12 = pos11 + 1;
    }

    if(pos4 == s.length() - 9)
    {
        ++pos3;
        pos4 = pos3 + 1;
        pos5 = pos4 + 1;
        pos6 = pos5 + 1;
        pos7 = pos6 + 1;
        pos8 = pos7 + 1;
        pos9 = pos8 + 1;
        pos10 = pos9 + 1;
        pos11 = pos10 + 1;
        pos12 = pos11 + 1;
    }

    if(pos3 == s.length() - 10)
    {
        ++pos2;
        pos3 = pos2 + 1;
        pos4 = pos3 + 1;
        pos5 = pos4 + 1;
        pos6 = pos5 + 1;
        pos7 = pos6 + 1;
        pos8 = pos7 + 1;
        pos9 = pos8 + 1;
        pos10 = pos9 + 1;
        pos11 = pos10 + 1;
        pos12 = pos11 + 1;
    }

    if(pos2 == s.length() - 11)
    {
        ++pos1;
        pos2 = pos1 + 1;
        pos3 = pos2 + 1;
        pos4 = pos3 + 1;
        pos5 = pos4 + 1;
        pos6 = pos5 + 1;
        pos7 = pos6 + 1;
        pos8 = pos7 + 1;
        pos9 = pos8 + 1;
        pos10 = pos9 + 1;
        pos11 = pos10 + 1;
        pos12 = pos11 + 1;
    }
    
    //cout << "p: " << pos1 <<
    //" p: " << pos2 <<
    //" p: " << pos3 <<
    //" p: " << pos4 <<
    //" p: " << pos5 <<
    //" p: " << pos6 <<
    //" p: " << pos7 <<
    //" p: " << pos8 <<
    //" p: " << pos9 <<
    //" p: " << pos10 <<
    //" p: " << pos11 <<
    //" p: " << pos12 << " ";
    //cout << newHighNumber << endl;

    unsigned long long newHighNumber =  stoull(  s.substr(pos1, 1) +
                    s.substr(pos2, 1) +
                    s.substr(pos3, 1) +
                    s.substr(pos4, 1) +
                    s.substr(pos5, 1) +
                    s.substr(pos6, 1) +
                    s.substr(pos7, 1) +
                    s.substr(pos8, 1) +
                    s.substr(pos9, 1) +
                    s.substr(pos10, 1) +
                    s.substr(pos11, 1) + 
                    s.substr(pos12, 1));
    
    //if(newnewHighNumber > newHighNumber)
    //    newHighNumber = newnewHighNumber;

    //cout << "newHighNumber : " << newHighNumber << endl;
    //cout << "highestNumber: " << highestNumber << endl;
    return findHighestNumberTwelveBlock(s, (highestNumber > newHighNumber) ? highestNumber : newHighNumber, pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, pos10, pos11, ++pos12);
}

int main()
{
    string inputLine;
    fstream inputFile("test_input.txt");
    int firstHighesValPos = 0;
    int secondHighesValPos = 0;
    uint64_t sumPart1 = 0;
    uint64_t sumPart2 = 0;
    while(getline(inputFile, inputLine))
    {
        {
            const int hightesNumberInString = findHighestNumberInString(inputLine);
            cout << "voltage(2v): " << hightesNumberInString << endl;
            sumPart1 += hightesNumberInString;
            const unsigned long long highestTwelveBlock = findHighestNumberTwelveBlock(inputLine);
            cout << "volatage(12): " << highestTwelveBlock << endl;
            sumPart2 += highestTwelveBlock;
        }
    }

    cout << "Part 1: " << sumPart1 << endl;
    cout << "Part 2: " << sumPart2 << endl;

    return 0;
}