#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_07.3-rec/lab_07.3-rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMatrix
{
    TEST_CLASS(UnitTestMatrix)
    {
    public:

        TEST_METHOD(TestCountPositivesInColsWithZero)
        {
            int rowCount = 3, colCount = 3;
            int** testMatrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                testMatrix[i] = new int[colCount];

            // Ініціалізація матриці, де є нульові елементи та додатні
            testMatrix[0][0] = 0; testMatrix[0][1] = -2; testMatrix[0][2] = 3;
            testMatrix[1][0] = 1; testMatrix[1][1] = 0; testMatrix[1][2] = -1;
            testMatrix[2][0] = 2; testMatrix[2][1] = 5; testMatrix[2][2] = 0;

            int count = 0;
            bool result = false;
            Part1_CountCols(testMatrix, rowCount, colCount, count, result, 0);

            Assert::IsTrue(result); // Перевірка, що є нульові елементи
            Assert::AreEqual(3, count); // Очікувана кількість додатних елементів = 3

            for (int i = 0; i < rowCount; i++)
                delete[] testMatrix[i];
            delete[] testMatrix;
        }

        TEST_METHOD(TestSaddlePoints)
        {
            int rowCount = 3, colCount = 3;
            int** testMatrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                testMatrix[i] = new int[colCount];

            // Ініціалізація матриці, де є сідлова точка
            testMatrix[0][0] = 3; testMatrix[0][1] = 8; testMatrix[0][2] = 4;
            testMatrix[1][0] = 9; testMatrix[1][1] = 7; testMatrix[1][2] = 5;
            testMatrix[2][0] = 6; testMatrix[2][1] = 2; testMatrix[2][2] = 1;

            int No = 0;
            Part2_SaddlePointRows(testMatrix, rowCount, colCount, No, 0);

            Assert::AreEqual(1, No); // Очікується 1 сідлова точка

            for (int i = 0; i < rowCount; i++)
                delete[] testMatrix[i];
            delete[] testMatrix;
        }
    };
}
