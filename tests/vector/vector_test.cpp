#include "vector_test.h"
#include "../../structures/vector/vector.h"

namespace tests
{
// VectorTestInterface:

    VectorTestInterface::VectorTestInterface() :
        SimpleTest("Interface")
    {
    }

    void VectorTestInterface::test()
    {
        structures::Vector* vector = new structures::Vector(10);
        vector->size();
        vector->assign(*vector);
        vector->equals(*vector);
        vector->at(0);
        vector->getBytePointer(0);
        //structures::Vector::copy(*vector, 0, *vector, 0, 1);
        delete vector;
        SimpleTest::logPass("Compiled.");
    }

    VectorTestAt::VectorTestAt()
        : SimpleTest("Vector test at")
    {
    }

    void VectorTestAt::test()
    {
        structures::Logger::getInstance().logInfo("Zacal test vektor at");
        SimpleTest::startStopwatch();

        structures::Vector* testVector = new structures::Vector(10);
        SimpleTest::assertTrue(testVector->size() == 10, "Testujem Vector::size()");
        for (int i = 0; i < 10; i++)
        {
            testVector->at(i) = i;
        }
        for (int i = 0; i < 10; i++)
        {
            SimpleTest::assertTrue(testVector->at(i) == i, "Testujem Vecotr::at(" + std::to_string(i) + ")");
            SimpleTest::assertTrue(*(testVector->getBytePointer(i)) == i, "Testujem Vecotr::getBytePointer(" + std::to_string(i) + ")");

        }
        delete testVector;
        SimpleTest::stopStopwatch();
        structures::Logger::getInstance().logDuration(0, SimpleTest::getElapsedTime(), "... a trval:");
    }

// VectorTestOverall:

    VectorTestOverall::VectorTestOverall() :
        ComplexTest("Vector")
    {
        addTest(new VectorTestInterface());
        addTest(new VectorTestAt());
        addTest(new VectorTestCopyConstruct());
    }


    VectorTestCopyConstruct::VectorTestCopyConstruct()
        : SimpleTest("Vector test copy construct")
    {
    }

    void VectorTestCopyConstruct::test()
    {
        structures::Vector* testVector = new structures::Vector(10);
        for (int i = 0; i < 10; i++)
        {
            testVector->at(i) = i;
        }
        structures::Vector* testVector2 = new structures::Vector(*testVector);
        SimpleTest::assertTrue(testVector->equals(*testVector2), "Testujem Vector1.equals(Vector2) pri =");
        testVector2->at(0) = 10;
        SimpleTest::assertFalse(testVector->equals(*testVector2), "Testujem Vector1.equals(Vector2) pri zmene prveho prvku");
        testVector->assign(*testVector2);
        SimpleTest::assertTrue(testVector->equals(*testVector2), "Testujem Vector1.equals(Vector2) pri spatnom vlozeni kopie do originalu");
        delete testVector;
        delete testVector2;
    }

}