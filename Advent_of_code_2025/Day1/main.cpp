#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int dialVal = 50;
    const uint16_t  DIAL_MAX_VAL = 100;
    int passwordValue = 0;
    string inputLine;
    fstream inputFile("input.txt");
    while(getline(inputFile, inputLine))
    {
        cout << inputLine << endl;
        uint16_t lineDialVal = 0;
        char dialDirection;

        sscanf(inputLine.c_str(), "%c%d", &dialDirection, &lineDialVal);

        if(dialDirection == 'L')
        {
            dialVal -= lineDialVal;
            //if(dialVal < 0)
            //{
            //    dialVal = DIAL_MAX_VAL + dialVal;
            //}   
        }
        
        if(dialDirection == 'R')
        {
            dialVal += lineDialVal;
        }

        dialVal = dialVal % DIAL_MAX_VAL;

        if(dialVal == 0)
            passwordValue++;

    }

    cout << "The final dial value is: " << dialVal << endl;
    cout << "The password is: " << passwordValue << endl;

    return 0;
}