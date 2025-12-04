#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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


int Part1(int matrix[][MATRIX_W + PADDING_SIZE], int inputWidth, int inputHeight, vector<int>& removeRows, vector<int>& removeCols)
{
    int sum = 0;
    removeRows.clear();
    removeCols.clear();

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
                // Part 2: remove the roll of paper and mark it as zero
                //matrix[i][k] = 0; 
                removeRows.push_back(i);
                removeCols.push_back(k);
                sum++; 
            }
            //else
            //{
            //    matrix[i][k]
            //    cout << "@";
            //}
            
        }
        //cout << endl;
    }

    return sum;
}

void RemoveValuesFromMatrix(int matrix[][MATRIX_W + PADDING_SIZE], vector<int>& removeRows, vector<int>& removeCols)
{
    for(int i = 0; i < removeRows.size(); i++)
    {
        matrix[removeRows[i]][removeCols[i]] = 0;
    }

    removeRows.clear();
    removeCols.clear();
}


int main()
{
    int matrix[MATRIX_H + PADDING_SIZE][MATRIX_W + PADDING_SIZE];
    int inputWidth = 0;
    int inputHeight = 0;

    vector<int> removeRows;
    vector<int> removeCols;

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

    int sumPart1 = Part1(matrix, inputWidth, inputHeight, removeRows, removeCols);
    int removedRolls = sumPart1;
    int sumPart2 = removedRolls;
    RemoveValuesFromMatrix(matrix, removeRows, removeCols);
    //cout << "Removes Rolls: " << removedRolls << endl;
    do
    {

        removedRolls = Part1(matrix, inputWidth, inputHeight, removeRows, removeCols);
        sumPart2 += removedRolls;
        cout << "Removes Rolls: " << removedRolls << endl;
        RemoveValuesFromMatrix(matrix, removeRows, removeCols);
    } while (removedRolls != 0);
    

    cout << "Part1: " << sumPart1 << endl;
    cout << "Part2: " << sumPart2 << endl;

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