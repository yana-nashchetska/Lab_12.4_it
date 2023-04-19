#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.4/Lab_12.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest124іт
{
	TEST_CLASS(UnitTest124іт)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int num = 1;

			for (int i = 1; i < 4; i++)
			{
				num++;
				Insert(L, num);
			} 
			insertAfter(L, 2);
			int expected = 2;
			int actual = L->link->info;
			Assert::AreEqual(actual, expected);

		}
	};
}
