#include <fstream>
#include <iostream>
#include <string>

const static int MATRIX_H = 140;
const static int MATRIX_W = 140;
const static int PADDING_SIZE = 10;
const static int PADDING_VAL = 0;

const static int DIRECTIONS_NUM = 8;
const static int dr[DIRECTIONS_NUM] = {-1, -1, -1, 0, 0, 1, 1, 1};
const static int dc[DIRECTIONS_NUM] = {-1, 0, 1, -1, 1, -1, 0, 1};

using namespace std;

void initializeMatrix(int matrix[][MATRIX_W + PADDING_SIZE])
{
    for(int i = 0; i < MATRIX_H + PADDING_SIZE; i++)
    {
        for(int k = 0; k < MATRIX_W + PADDING_SIZE; k++)
        {
            matrix[i][k] = PADDING_VAL;
        }
    }
}

int NeighboursSum(const int matrix[MATRIX_H + PADDING_SIZE][MATRIX_W + PADDING_SIZE], int eRow, int eCol)
{
    int sum = 0;
    for(int i = 0; i < DIRECTIONS_NUM; i++)
    {
        const int neighbour_row = eRow + dr[i];
        const int neighbour_col = eCol + dc[i];

        if(matrix[neighbour_row][neighbour_col] == 1)
            sum++;
        //cout << "Nrow: " << neighbour_row << "Ncol: " << neighbour_col  << endl;
    }
    //cout << "sum: " << sum;
    return sum;
}


int Part1(const int matrix[][MATRIX_W + PADDING_SIZE], int inputWidth, int inputHeight)
{
    int sum = 0;

    for (int i = PADDING_SIZE; i < inputWidth + PADDING_SIZE; i++)
    {
        for(int k = PADDING_SIZE; k < inputHeight + PADDING_SIZE; k++)
        {
            if(matrix[i][k] == 0)
            {
                //cout << ".";
                continue;
            }
            //cout << matrix[i][k];
            //cout << "row: " << i << "col: " << k  << endl;
            if(NeighboursSum(matrix, i, k) < 4)
            {
                //cout << "X";
                sum++; 
            }
            //else
            //{
            //    cout << "@";
            //}
            
        }
        //cout << endl;
    }

    return sum;
}


int main()
{
    int matrix[MATRIX_H + PADDING_SIZE][MATRIX_W + PADDING_SIZE];
    int inputWidth = 0;
    int inputHeight = 0;

    string inputLine;
    fstream inputFile("input.txt");
    
    initializeMatrix(matrix);

    while(getline(inputFile, inputLine))
    {
        inputWidth = inputLine.length();
        for(int i = 0; i < inputWidth ; i++)
        {
            if(inputLine.at(i) == '@')
                matrix[PADDING_SIZE + inputHeight][PADDING_SIZE + i] = 1;
        }
        inputHeight++;
    }

    int SumPart1 = Part1(matrix, inputWidth, inputHeight);

    cout << "Part1: " << SumPart1 << endl;

    //for (int i = PADDING_SIZE; i < inputWidth + PADDING_SIZE; i++)
    //{
    //    for(int k = PADDING_SIZE; k < inputHeight + PADDING_SIZE; k++)
    //    {
    //        cout << matrix[i][k];
    //    }
    //    cout << endl;
    //}

    return 0;
}