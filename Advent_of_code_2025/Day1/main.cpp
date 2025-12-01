#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int dialPosition = 50;
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

        if(dialDirection == 'L')
            lineDialVal *= -1;


        //passwordValue += (abs(dialPosition) + abs(lineDialVal))/ DIAL_MAX_VAL;
        dialPosition += lineDialVal;
        dialPosition = dialPosition % DIAL_MAX_VAL;
        if(dialPosition == 0)
            passwordValue++;

        //const uint16_t absoluteDialVal = dialVal + abs(lineDialVal);
        //cout << "absoluteDialVal:" << absoluteDialVal << endl;
        //dialVal += lineDialVal;
//
        //if(dialVal < 0)
        //{
        //    //uint16_t absoluteDialVal = abs(dialVal);
        //    //passwordValue += absoluteDialVal / DIAL_MAX_VAL;
        //    dialVal = DIAL_MAX_VAL - (absoluteDialVal % DIAL_MAX_VAL);
        //}
        //
        //if(dialVal >= DIAL_MAX_VAL)
        //{
        //    //uint16_t absoluteDialVal = abs(dialVal);
        //    //passwordValue += absoluteDialVal / DIAL_MAX_VAL;
        //    dialVal = absoluteDialVal % DIAL_MAX_VAL;
        //}
//
        ////if(absoluteDialVal >= DIAL_MAX_VAL)
        ////    passwordValue += absoluteDialVal % DIAL_MAX_VAL;
//
        //if(dialVal == 0)
        //    passwordValue++;
        //else if(absoluteDialVal > DIAL_MAX_VAL)
        //{
        //    cout << "HERE" << endl;
        //    passwordValue += absoluteDialVal / DIAL_MAX_VAL;
        //}


        //if(dialVal == DIAL_MAX_VAL)
        //{
        //    dialVal = dialVal % DIAL_MAX_VAL;
        //    passwordValue++;
        //}
        
        cout << dialPosition << endl;

        //if(lineDialVal > dialVal)
        //    dialVal += lineDialVal;
        //else
        //    dialVal -= lineDialVal;
        //passwordValue += dialVal / DIAL_MAX_VAL;
        //if(dialVal > DIAL_MAX_VAL)
        //    dialVal = DIAL_MAX_VAL - (dialVal % DIAL_MAX_VAL);
        //cout << dialVal << endl;


        
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