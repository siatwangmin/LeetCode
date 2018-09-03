#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
			Logger::WriteMessage("开始测试一");
			Assert::AreEqual(1,1);
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO:  在此输入测试代码
			Logger::WriteMessage("开始测试二");
			Assert::AreEqual(1, 1);
		}

	};
}