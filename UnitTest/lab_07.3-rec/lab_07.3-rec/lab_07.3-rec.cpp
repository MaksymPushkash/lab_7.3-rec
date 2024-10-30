#include <iostream>
#include <iomanip>
using namespace std;

void InputRow(int** a, int rowNo, int colCount, int colNo)
{
    cout << "a[" << rowNo << "][" << colNo << "] = ";
    cin >> a[rowNo][colNo];
    if (colNo < colCount - 1)
        InputRow(a, rowNo, colCount, colNo + 1);
}

void InputRows(int** a, int rowCount, int colCount, int rowNo)
{
    InputRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        InputRows(a, rowCount, colCount, rowNo + 1);
}

void PrintRow(int** a, int rowNo, int colCount, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, int rowCount, int colCount, int rowNo)
{
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
}

void Part1_ZeroCol(int** a, int rowCount, bool& result, int colNo, int rowNo, int& k_zero)
{
    if (a[rowNo][colNo] == 0)
    {
        result = true;
        k_zero++;
    }
    else if (rowNo < rowCount - 1)
        Part1_ZeroCol(a, rowCount, result, colNo, rowNo + 1, k_zero);
}

void Part1_CountCol(int** a, int rowCount, int& count, int colNo, int rowNo)
{
    if (a[rowNo][colNo] > 0)
        count++;
    if (rowNo < rowCount - 1)
        Part1_CountCol(a, rowCount, count, colNo, rowNo + 1);
}

void Part1_CountCols(int** a, int rowCount, int colCount, int& count, bool& result, int colNo)
{
    int k_zero = 0;
    Part1_ZeroCol(a, rowCount, result, colNo, 0, k_zero);
    if (k_zero > 0)
        Part1_CountCol(a, rowCount, count, colNo, 0);
    if (colNo < colCount - 1)
        Part1_CountCols(a, rowCount, colCount, count, result, colNo + 1);
}

bool IsMaxInRowN(int** a, int rowNo, int max, int colCount, int colNo)
{
    if (a[rowNo][colNo] > max)
        return false;
    if (colNo < colCount - 1)
        return IsMaxInRowN(a, rowNo, max, colCount, colNo + 1);
    else
        return true;
}

bool IsMinInColK(int** a, int colNo, int min, int rowCount, int rowNo)
{
    if (a[rowNo][colNo] < min)
        return false;
    if (rowNo < rowCount - 1)
        return IsMinInColK(a, colNo, min, rowCount, rowNo + 1);
    else
        return true;
}

void Part2_SaddlePointRow(int** a, int rowCount, int colCount, int& No, int rowNo, int colNo)
{
    if (IsMaxInRowN(a, rowNo, a[rowNo][colNo], colCount, 0) && IsMinInColK(a, colNo, a[rowNo][colNo], rowCount, 0))
    {
        cout << setw(4) << ++No << setw(6) << rowNo << setw(6) << colNo << endl;
    }
    if (colNo < colCount - 1)
        Part2_SaddlePointRow(a, rowCount, colCount, No, rowNo, colNo + 1);
}

void Part2_SaddlePointRows(int** a, int rowCount, int colCount, int& No, int rowNo)
{
    Part2_SaddlePointRow(a, rowCount, colCount, No, rowNo, 0);
    if (rowNo < rowCount - 1)
        Part2_SaddlePointRows(a, rowCount, colCount, No, rowNo + 1);
}

int main()
{
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    InputRows(a, rowCount, colCount, 0);
    cout << "Matrix:" << endl;
    PrintRows(a, rowCount, colCount, 0);

    int count = 0;
    bool result = false;
    Part1_CountCols(a, rowCount, colCount, count, result, 0);

    if (result)
        cout << "Count of positive elements in columns with zeroes: " << count << endl;
    else
        cout << "There are no zero elements" << endl;

    cout << "Saddle points: max in row & min in col" << endl;
    cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
    int No = 0;
    Part2_SaddlePointRows(a, rowCount, colCount, No, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
