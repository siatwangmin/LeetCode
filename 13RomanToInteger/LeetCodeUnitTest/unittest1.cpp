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
			// TODO:  �ڴ�������Դ���
			Logger::WriteMessage("��ʼ����һ");
			Assert::AreEqual(1,1);
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO:  �ڴ�������Դ���
			Logger::WriteMessage("��ʼ���Զ�");
			Assert::AreEqual(1, 1);
		}

	};
}