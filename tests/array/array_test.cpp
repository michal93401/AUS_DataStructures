#include "array_test.h"
#include "../../structures/array/array.h"


namespace tests
{
// ArrayTestInterface:

	ArrayTestInterface::ArrayTestInterface() :
		SimpleTest("Interface")
	{
	}

	void ArrayTestInterface::test()
	{
		structures::Array<int>* testArray = new structures::Array<int>(10);
		testArray->copy(*testArray, 0, *testArray, 0, 1);
		testArray->isEmpty();
		testArray->assign(*testArray);
		testArray->equals(*testArray);
		testArray->at(0);
		testArray->size();
		delete testArray;
		SimpleTest::logPass("Compiled.");
	}

// ArrayTestOverall:

    ArrayTestOverall::ArrayTestOverall() :
        ComplexTest("Array")
    {
        addTest(new ArrayTestInterface());
        addTest(new ArrayTestAt());
        addTest(new ArrayTestCopyConstruct());
    }

    ArrayTestAt::ArrayTestAt() :SimpleTest("Test AT")
    {
    }


    void ArrayTestAt::test()
    {
        structures::Logger::getInstance().logInfo("test stopiek vo array test");
        SimpleTest::startStopwatch();

        structures::Array<int>* test_array = new structures::Array<int>(10);
        //SimpleTest::assertTrue(test_vector->size() == 10);
        SimpleTest::assertTrue(test_array->size() == 10, "test size");
        for (int i = 0; i < 10; i++)
        {
            test_array->at(i) = i;
        }
        for (int i = 0; i < 10; i++) {
            SimpleTest::assertTrue(test_array->at(i) == i, "tetsujem ci na " + std::to_string(i) +
                "tej pozicii je hodnota " + std::to_string(i));
        }
        delete test_array;
        SimpleTest::stopStopwatch();
        structures::Logger::getInstance().logDuration(0, SimpleTest::getElapsedTime(),
            "stop stopwatch watch stop");
    }

    ArrayTestCopyConstruct::ArrayTestCopyConstruct() :SimpleTest("Test copy construct")
    {
    }


    void ArrayTestCopyConstruct::test()
    {
        structures::Array<int>* test_array = new structures::Array<int>(10);
        for (int i = 0; i < 10; i++)
        {
            test_array->at(i) = i;
        }
        structures::Array<int>* test_array_copy = new structures::Array<int>(*test_array);
        SimpleTest::assertTrue(test_array->equals(*test_array_copy),
            "Kontrola ci su arrays rovnake");
        test_array->at(0) = 10;
        SimpleTest::assertTrue(!(test_array->equals(*test_array_copy)),
            "Kontrola ci su arrays rozdielne");
        test_array->assign(*test_array_copy);
        SimpleTest::assertTrue(test_array_copy->equals(*test_array),
            "Kontrola ci je skopirovany array rovnaky ako povodny");

        delete test_array_copy;
        delete test_array;
    }
}

