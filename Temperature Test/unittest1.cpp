#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Day 1 and 2 - A class/Temperature.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TemperatureTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(IntersectAtNeg40)
		{
			Temperature unit(-40.0f);
			Assert::AreEqual(-40.0f, unit.getCelsius(), L"Celsius wasn't -40", LINE_INFO());
			Assert::AreEqual(-40.0f, unit.getFahrenheit(), L"Fahrenheit wasn't -40", LINE_INFO());
		}
	};
}
