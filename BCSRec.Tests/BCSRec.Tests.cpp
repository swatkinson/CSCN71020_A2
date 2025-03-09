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

		TEST_METHOD(getArea_Length5Width10_Returns50)
		{
			int length = 5;
			int width = 10;

			int result = getArea(&length, &width);
			int expected = 50;

			Assert::AreEqual(expected, result);
		}
	};
}
