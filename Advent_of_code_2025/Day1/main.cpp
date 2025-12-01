#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inputLine;
    fstream inputFile("input.txt");
    while(getline(inputFile, inputLine))
    {
        cout << inputLine << endl;
    }
    
    return 0;
}