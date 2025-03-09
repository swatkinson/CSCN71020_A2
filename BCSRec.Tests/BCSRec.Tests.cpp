#include "pch.h"
#include "CppUnitTest.h"


extern "C" int getPerimeter(int* length, int* width);
extern "C" int getArea(int* length, int* width);
extern "C" void setLength(int input, int* length);
extern "C" void setWidth(int input, int* width);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecTests
{
	TEST_CLASS(RectPerimeterTests)
	{
	public:
		
		/// Tests that perimeter is correctly calculated
		TEST_METHOD(getPerimeter_Length5Width10_Returns30)
		{
			int length = 5;
			int width = 10;
			
			int result = getPerimeter(&length, &width);
			int expected = 30;

			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(RectAreaTests)
	{
	public:

		/// Tests that area is correctly calculated
		TEST_METHOD(getArea_Length5Width10_Returns50)
		{
			int length = 5;
			int width = 10;

			int result = getArea(&length, &width);
			int expected = 50;

			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(RectSetLengthTests)
	{
	public:

		// Tests that length can be changed to a valid 1-99 number
		TEST_METHOD(setLength_CurLen5NewLen50_ReturnsLength50)
		{
			int curLength = 5;
			int newLength = 50;

			setLength(newLength, &curLength);

			Assert::AreEqual(curLength, newLength);
		}

		// Tests that length wont be changed to an invalid above-boundary range (100)
		TEST_METHOD(setLength_CurLen50NewLen100_ReturnsLength50)
		{
			int curLength = 50;
			int newLength = 100;

			setLength(newLength, &curLength);

			Assert::AreNotEqual(curLength, newLength);
		}

		// Tests that length wont be changed to an invalid below-boundary range (-1)
		TEST_METHOD(setLength_CurLen75NewLenNegative1_ReturnsLength75)
		{
			int curLength = 75;
			int newLength = -1;

			setLength(newLength, &curLength);

			Assert::AreNotEqual(curLength, newLength);
		}
	};

	TEST_CLASS(RectSetWidthTests)
	{
	public:

		// Tests that width can be changed to a valid 1-99 number
		TEST_METHOD(setWidth_CurWidth5NewWidth50_ReturnsWidth50)
		{
			int curWidth = 5;
			int newWidth = 50;

			setLength(newWidth, &curWidth);

			Assert::AreEqual(curWidth, newWidth);
		}

		// Tests that width wont be changed to an invalid above-boundary range (100)
		TEST_METHOD(setWidth_CurWidth50NewWidth100_ReturnsWidth50)
		{
			int curWidth = 50;
			int newWidth = 100;

			setLength(newWidth, &curWidth);

			Assert::AreNotEqual(curWidth, newWidth);
		}

		// Tests that width wont be changed to an invalid below-boundary range (-1)
		TEST_METHOD(setWidth_CurWidth75NewWidthNegative1_ReturnsWidth75)
		{
			int curWidth = 75;
			int newWidth = -1;

			setLength(newWidth, &curWidth);

			Assert::AreNotEqual(curWidth, newWidth);
		}
	};
}
