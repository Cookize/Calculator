#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{		
	TEST_CLASS(Test)
	{
	public:
		Calculator* calc;

		TEST_METHOD_INITIALIZE(initCal) 
		{
			calc = new Calculator();
		}

		TEST_METHOD_CLEANUP(CleanCal)
		{
			delete calc;
			calc = NULL;
		}

		/*
			简单测试
		*/

		TEST_METHOD(SimpleADD)
		{
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");
		}

		TEST_METHOD(SimpleSUB)
		{
			string ret = calc->Solve("77-33");
			Assert::AreEqual(ret, (string)"77-33=44");
		}

		TEST_METHOD(SimpleMUL)
		{
			string ret = calc->Solve("55*66");
			Assert::AreEqual(ret, (string)"55*66=3630");
		}

		TEST_METHOD(SimpleDIV)
		{
			string ret = calc->Solve("99/33");
			Assert::AreEqual(ret, (string)"99/33=3");
		}

		/*
			组合测试
		*/

		TEST_METHOD(ADD_ADD)
		{
			string ret = calc->Solve("22+33+11");
			Assert::AreEqual(ret, (string)"22+33+11=66");
		}

		TEST_METHOD(ADD_SUB)
		{
			string ret = calc->Solve("22+33-11");
			Assert::AreEqual(ret, (string)"22+33-11=44");
		}

		TEST_METHOD(ADD_MUL)
		{
			string ret = calc->Solve("22+33*11");
			Assert::AreEqual(ret, (string)"22+33*11=385");
		}

		TEST_METHOD(ADD_DIV)
		{
			string ret = calc->Solve("22+33/11");
			Assert::AreEqual(ret, (string)"22+33/11=25");
		}

		TEST_METHOD(SUB_ADD)
		{
			string ret = calc->Solve("99-66+77");
			Assert::AreEqual(ret, (string)"99-66+77=110");
		}

		TEST_METHOD(SUB_SUB)
		{
			string ret = calc->Solve("99-22-55");
			Assert::AreEqual(ret, (string)"99-22-55=22");
		}

		TEST_METHOD(SUB_MUL)
		{
			string ret = calc->Solve("77-6*11");
			Assert::AreEqual(ret, (string)"77-6*11=11");
		}

		TEST_METHOD(SUB_DIV)
		{
			string ret = calc->Solve("77-88/2");
			Assert::AreEqual(ret, (string)"77-88/2=33");
		}

		TEST_METHOD(MUL_ADD)
		{
			string ret = calc->Solve("22*33+11");
			Assert::AreEqual(ret, (string)"22*33+11=737");
		}

		TEST_METHOD(MUL_SUB)
		{
			string ret = calc->Solve("22*33-11");
			Assert::AreEqual(ret, (string)"22*33-11=715");
		}

		TEST_METHOD(MUL_MUL)
		{
			string ret = calc->Solve("22*33*99");
			Assert::AreEqual(ret, (string)"22*33*99=71874");
		}

		TEST_METHOD(MUL_DIV)
		{
			string ret = calc->Solve("22*33/11");
			Assert::AreEqual(ret, (string)"22*33/11=66");
		}

		TEST_METHOD(DIV_ADD)
		{
			string ret = calc->Solve("99/9+11");
			Assert::AreEqual(ret, (string)"99/9+11=22");
		}

		TEST_METHOD(DIV_SUB)
		{
			string ret = calc->Solve("99/9-10");
			Assert::AreEqual(ret, (string)"99/9-10=1");
		}

		TEST_METHOD(DIV_MUL)
		{
			string ret = calc->Solve("99/9*22");
			Assert::AreEqual(ret, (string)"99/9*22=242");
		}

		TEST_METHOD(DIV_DIV)
		{
			string ret = calc->Solve("99/9/11");
			Assert::AreEqual(ret, (string)"99/9/11=1");
		}

		/*
			运算数长度
		*/
		TEST_METHOD(Length_1)
		{
			string ret = calc->Solve("9/3*2+8");
			Assert::AreEqual(ret, (string)"9/3*2+8=14");
		}

		TEST_METHOD(Length_2)
		{
			string ret = calc->Solve("90/3*22+8");
			Assert::AreEqual(ret, (string)"90/3*22+8=668");
		}

		TEST_METHOD(Length_3)
		{
			string ret = calc->Solve("90/30*2+89");
			Assert::AreEqual(ret, (string)"90/30*2+89=95");
		}
	};

}