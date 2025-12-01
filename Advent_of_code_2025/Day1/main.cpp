#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int dialVal = 50;
    const uint16_t  DIAL_MAX_VAL = 100;
    string inputLine;
    fstream inputFile("test_input.txt");
    while(getline(inputFile, inputLine))
    {
        cout << inputLine << endl;
        uint16_t lineDialVal = 0;
        char dialDirection;

        sscanf(inputLine.c_str(), "%c%d", &dialDirection, &lineDialVal);

        if(dialDirection == 'L')
        {
            dialVal -= lineDialVal;
            if(dialVal < 0)
                dialVal = DIAL_MAX_VAL + dialVal;
        }
        
        if(dialDirection == 'R')
        {
            dialVal = (dialVal + lineDialVal) % DIAL_MAX_VAL;
        }

    }

    cout << "The final dial value is: " << dialVal << endl;

    return 0;
}