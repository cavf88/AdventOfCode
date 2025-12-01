#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int dialPosition = 50;
    int lastPosition = dialPosition;
    const uint16_t  DIAL_MAX_VAL = 100;
    int passwordValue = 0;
    string inputLine;
    fstream inputFile("input.txt");
    while(getline(inputFile, inputLine))
    {
        cout << inputLine << endl;
        int lineDialVal = 0;
        char dialDirection;

        sscanf(inputLine.c_str(), "%c%d", &dialDirection, &lineDialVal);

        for(int i = 0; i < lineDialVal; i++)
        {
            if(dialDirection == 'L')
                dialPosition--;
            else
                dialPosition++;

            dialPosition = dialPosition % DIAL_MAX_VAL;

            if(dialPosition == 0)
            {
                cout << "CLICK" << endl;
                passwordValue++;
            }
        }
        // verbose
        //cout << dialPosition << endl;
        
        // Old Part 1 Solution
        //if(dialDirection == 'L')
        //
        //   dialVal -= lineDialVal;
        //   //if(dialVal < 0)
        //   //{
        //   //    dialVal = DIAL_MAX_VAL + dialVal;
        //   //}   
        //
        //
        //if(dialDirection == 'R')
        //
        //   dialVal += lineDialVal;
        //

        //dialVal = dialVal % DIAL_MAX_VAL;
        //
        //if(dialVal == 0)
        //
        //   passwordValue++;
        //
    }

    cout << "The final dial value is: " << dialPosition << endl;
    cout << "The password is: " << passwordValue << endl;

    return 0;
}