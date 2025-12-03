#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inputLine;
    fstream inputFile("test_input.txt");
    while(getline(inputFile, inputLine))
    {
        cout << inputLine << endl;
    }
    return 0;
}