#include "pch.h"
#include "CppUnitTest.h"


extern "C" int getPerimeter(int* length, int* width);
extern "C" int getArea(int* length, int* width);
extern "C" void setLength(int input, int* length);
extern "C" void setWidth(int input, int* width);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecTests
{
	TEST_CLASS(BCSRecTests)
	{
	public:
		
		TEST_METHOD(getPerimeterTest)
		{
			int length = 5;
			int width = 10;
			
			int result = getPerimeter(&length, &width);
			int expected = 30;

			Assert::AreEqual(expected, result);
		}
	};
}
