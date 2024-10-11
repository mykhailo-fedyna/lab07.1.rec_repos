#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.1(rec).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int S = 0, k = 0;
			int** y = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				y[i] = new int[colCount];
			y[0][0] = 9; y[0][1] = 12; y[0][2] = 15;
			y[1][0] = 4; y[1][1] = 7;  y[1][2] = 3;
			y[2][0] = 5; y[2][1] = 11; y[2][2] = 6;
			Calc(y, rowCount, colCount, S, k, 0, 0);
			Assert::AreEqual(54, S);
			Assert::AreEqual(7, k);
			Assert::AreEqual(0, y[0][0]);
			Assert::AreEqual(0, y[0][2]);
			Assert::AreEqual(0, y[1][0]);
			Assert::AreEqual(0, y[1][1]);
			Assert::AreEqual(0, y[2][0]);
			Assert::AreEqual(0, y[2][1]);
			for (int i = 0; i < rowCount; i++)
				delete[] y[i];
			delete[] y;
		}
	};
}
