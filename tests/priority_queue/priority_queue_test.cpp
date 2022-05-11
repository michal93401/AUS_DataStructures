#include "priority_queue_test.h"
#include "../../structures/priority_queue/heap.h"
#include "../../structures/priority_queue/priority_queue_limited_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_linked_list.h"
#include "../../structures/priority_queue/priority_queue_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_two_lists.h"
#include "../../structures/priority_queue/priority_queue_unsorted_array_list.h"

namespace tests
{
    PriorityQueueTestInterface::PriorityQueueTestInterface() :
        SimpleTest("Interface")
    {
    }

    void PriorityQueueTestInterface::test()
    {
        int x = 0;
        structures::PriorityQueue<int>* queue = this->makePriorityQueue();
        queue->push(0, x);
        queue->peek();
        queue->peekPriority();
        queue->pop();
        queue->assign(*queue);
        delete queue;
        this->logPass("Compiled.");
    }

    structures::PriorityQueue<int>* PriorityQueueUnsortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueUnsortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLimitedSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLimitedSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLinkedListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLinkedList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueTwoListsTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueTwoLists<int>();
    }

    structures::PriorityQueue<int>* HeapTestInterface::makePriorityQueue()
    {
        return new structures::Heap<int>();
    }

    /*PriorityQueueUnsortedArrayListTestOverall::PriorityQueueUnsortedArrayListTestOverall() :
        ComplexTest("PriorityQueueUnsortedArray")
    {
        addTest(new PriorityQueueUnsortedArrayListTestInterface());
    }*/

    PriorityQueueSortedArrayListTestOverall::PriorityQueueSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueSortedArrayList")
    {
        addTest(new PriorityQueueSortedArrayListTestInterface());
    }

    PriorityQueueLimitedSortedArrayListTestOverall::PriorityQueueLimitedSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueLimitedSortedArrayList")
    {
        addTest(new PriorityQueueLimitedSortedArrayListTestInterface());
    }

    /*PriorityQueueLinkedListTestOverall::PriorityQueueLinkedListTestOverall() :
        ComplexTest("PriorityQueueLinkedList")
    {
        addTest(new PriorityQueueLinkedListTestInterface());
    }*/

    PriorityQueueTwoListsTestOverall::PriorityQueueTwoListsTestOverall() :
        ComplexTest("PriorityQueueTwoLists")
    {
        addTest(new PriorityQueueTwoListsTestInterface());
        addTest(new PQTLMethodsTest());
    }

    HeapTestOverall::HeapTestOverall() :
        ComplexTest("Heap")
    {
        addTest(new HeapTestInterface());
        addTest(new HeapMethodsTest());
    }

    PriorityQueueTestOverall::PriorityQueueTestOverall() :
        ComplexTest("PriorityQueue")
    {
        //addTest(new PriorityQueueUnsortedArrayListTestOverall());
        addTest(new PriorityQueueSortedArrayListTestOverall());
        addTest(new PriorityQueueLimitedSortedArrayListTestOverall());
        //addTest(new PriorityQueueLinkedListTestOverall());
        addTest(new PriorityQueueTwoListsTestOverall());
        addTest(new HeapTestOverall());
        addTest(new PQLTestScenare());
        addTest(new PQLTimeTest());
    }

    //-------------------------------------------------------
    //-------------------------------------------------------

    HeapMethodsTest::HeapMethodsTest() :
        SimpleTest("HeapMethodsTest")
    {
    }

    void HeapMethodsTest::test()
    {
        structures::Heap<int>* testHeap = new structures::Heap<int>();
        srand((int)time(NULL));
        SimpleTest::logInfo("HeapMethodsTest");
        for (int i = 0; i < 10; i++)
        {
            testHeap->push((rand() % 100) + 1, i);
        }
        SimpleTest::assertTrue(testHeap->size() == 10, "Size 10");

        testHeap->push(0, 999);
        SimpleTest::assertTrue(testHeap->peekPriority() == 0, "PeekPriority = 0");
        SimpleTest::assertTrue(testHeap->size() == 11, "Size 11");

        SimpleTest::assertTrue(testHeap->peek() == 999, "Peek returned data with value of 999");
        int data = testHeap->pop();
        SimpleTest::assertTrue(data == 999, "Pop returned data with value of 999");
        for (int i = 0; i < 9; i++)
        {
            testHeap->pop();
        }
        SimpleTest::assertTrue(testHeap->size() == 1, "Size 1");
        testHeap->pop();

        for (int i = 0; i < 10; i++)
        {
            testHeap->push((rand() % 100) + 1, i);
        }
        structures::Heap<int>* testHeap2 = new structures::Heap<int>(*testHeap);
        SimpleTest::assertTrue(testHeap2->size() == 10, "Copied heap size 10");
        SimpleTest::assertTrue(testHeap2->peek() == testHeap->peek(), "Peek()_1 = Peek()_2");
        SimpleTest::assertTrue(testHeap2->peekPriority() == testHeap->peekPriority(), "PeekPriority()_1 = PeekPriority_2");
        for (int i = 0; i < 10; i++)
        {
            testHeap->pop();
        }
        SimpleTest::assertTrue(testHeap->size() == 0, "Size 0");
        SimpleTest::assertTrue(testHeap2->size() == 10, "Size 10");
        delete testHeap;
        delete testHeap2;
    }

    PQTLMethodsTest::PQTLMethodsTest() :
        SimpleTest("PQTLMethodsTest")
    {
    }

    void PQTLMethodsTest::test()
    {
        structures::PriorityQueueTwoLists<int>* testPQTL = new structures::PriorityQueueTwoLists<int>();
        srand((int)time(NULL));
        SimpleTest::logInfo("PriorityQueueTwoLists");
        for (int i = 0; i < 10; i++)
        {
            testPQTL->push((rand() % 100) + 1, i);
        }
        SimpleTest::assertTrue(testPQTL->size() == 10, "Size 10");

        testPQTL->push(0, 999);
        SimpleTest::assertTrue(testPQTL->peekPriority() == 0, "PeekPriority = 0");
        SimpleTest::assertTrue(testPQTL->size() == 11, "Size 11");

        SimpleTest::assertTrue(testPQTL->peek() == 999, "Peek returned data with value of 999");
        int data = testPQTL->pop();
        SimpleTest::assertTrue(data == 999, "Pop returned data with value of 999");
        for (int i = 0; i < 9; i++)
        {
            testPQTL->pop();
        }
        SimpleTest::assertTrue(testPQTL->size() == 1, "Size 1");
        testPQTL->pop();

        for (int i = 0; i < 10; i++)
        {
            testPQTL->push((rand() % 100) + 1, i);
        }
        structures::PriorityQueueTwoLists<int>* testPQTL2 = new structures::PriorityQueueTwoLists<int>(*testPQTL);
        SimpleTest::assertTrue(testPQTL2->size() == 10, "Copied heap size 10");
        SimpleTest::assertTrue(testPQTL2->peek() == testPQTL->peek(), "Peek()_1 = Peek()_2");
        SimpleTest::assertTrue(testPQTL2->peekPriority() == testPQTL->peekPriority(), "PeekPriority()_1 = PeekPriority_2");
        for (int i = 0; i < 10; i++)
        {
            testPQTL->pop();
        }
        SimpleTest::assertTrue(testPQTL->size() == 0, "Size 0");
        SimpleTest::assertTrue(testPQTL2->size() == 10, "Size 10");
        delete testPQTL;
        delete testPQTL2;
    }

    //-------------------------------------------------------

    PQLTestScenare::PQLTestScenare() :
        ComplexTest("PQTLTestScenare")
    {
        addTest(new TestScenarAheap());
        addTest(new TestScenarBheap());
        addTest(new TestScenarCheap());
        addTest(new TestScenarAPQTL());
        addTest(new TestScenarBPQTL());
        addTest(new TestScenarCPQTL());
    }

    PQLTestScenar::PQLTestScenar(const char* testNazov) :
        SimpleTest(testNazov)
    {
    }

    void PQLTestScenar::testScenar(structures::PriorityQueue<int>* list, float push, float pop, float peek)
    {
        srand((int)time(NULL));
        int opCounter = 0;
        int pushCounter = 0;
        int popCounter = 0;
        int peekCounter = 0;
        int k = 0;
        auto timeCounter = SimpleTest::getElapsedTime();
        while (opCounter < 100000) {
            k = rand() % 100;
            if (k < 100 * push) {
                if (pushCounter < 100000 * push) {
                    int x = rand() % 100000;
                    SimpleTest::startStopwatch();
                    list->push(x, pushCounter);
                    SimpleTest::stopStopwatch();
                    timeCounter += SimpleTest::getElapsedTime();
                    pushCounter++;
                }
            }
            if (k >= 100 * push && k < 100 * (push + pop)) {
                if (popCounter < 100000 * pop) {
                    SimpleTest::startStopwatch();
                    list->pop();
                    SimpleTest::stopStopwatch();
                    timeCounter += SimpleTest::getElapsedTime();
                    popCounter++;
                }
            }
            if (k >= 100 * (push + pop) && k < 100) {
                if (peekCounter < 100000 * peek) {
                    SimpleTest::startStopwatch();
                    list->peek();
                    SimpleTest::stopStopwatch();
                    timeCounter += SimpleTest::getElapsedTime();
                    peekCounter++;
                }
            }
            opCounter = pushCounter + popCounter + peekCounter;
        }
        structures::Logger::getInstance().logDuration(list->size(), timeCounter,
            SimpleTest::getName());
    }

    TestScenarAheap::TestScenarAheap() :
        PQLTestScenar("TestScenarAheap")
    {
    }

    void TestScenarAheap::test()
    {
        auto testList = new structures::Heap<int>();
        for (int i = 0; i < 15000; i++)
        {
            testList->push(rand() % 100000, i);
        }
        testScenar(testList, 0.35, 0.35, 0.30);
        delete testList;
    }


    TestScenarBheap::TestScenarBheap() :
        PQLTestScenar("TestScenarBheap")
    {
    }

    void TestScenarBheap::test()
    {
        auto testList = new structures::Heap<int>();
        for (int i = 0; i < 15000; i++)
        {
            testList->push(rand() % 100000, i);
        }
        testScenar(testList, 0.50, 0.30, 0.20);
        delete testList;
    }


    TestScenarCheap::TestScenarCheap() :
        PQLTestScenar("TestScenarCheap")
    {
    }

    void TestScenarCheap::test()
    {
        auto testList = new structures::Heap<int>();
        for (int i = 0; i < 15000; i++)
        {
            testList->push(rand() % 100000, i);
        }
        testScenar(testList, 0.70, 0.25, 0.5);
        delete testList;
    }


    TestScenarAPQTL::TestScenarAPQTL() :
        PQLTestScenar("TestScenarAPQTL")
    {
    }

    void TestScenarAPQTL::test()
    {
        auto testList = new structures::PriorityQueueTwoLists<int>();
        for (int i = 0; i < 15000; i++)
        {
            testList->push(rand() % 100000, i);
        }
        testScenar(testList, 0.35, 0.35, 0.30);
        delete testList;
    }


    TestScenarBPQTL::TestScenarBPQTL() :
        PQLTestScenar("TestScenarBPQTL")
    {
    }

    void TestScenarBPQTL::test()
    {
        auto testList = new structures::PriorityQueueTwoLists<int>();
        for (int i = 0; i < 15000; i++)
        {
            testList->push(rand() % 100000, i);
        }
        testScenar(testList, 0.50, 0.30, 0.20);
        delete testList;
    }


    TestScenarCPQTL::TestScenarCPQTL() :
        PQLTestScenar("TestScenarCPQTL")
    {
    }

    void TestScenarCPQTL::test()
    {
        auto testList = new structures::PriorityQueueTwoLists<int>();
        for (int i = 0; i < 15000; i++)
        {
            testList->push(rand() % 100000, i);
        }
        testScenar(testList, 0.70, 0.25, 0.5);
        delete testList;
    }

    //-------------------------------------------------------

    PQLTimeTest::PQLTimeTest() :
        ComplexTest("PQLTimeTest")
    {
        addTest(new TimeTestHeapPush());
        addTest(new TimeTestHeapPop());
        addTest(new TimeTestHeapPeek());
        addTest(new TimeTestPQTLPush());
        addTest(new TimeTestPQTLPop());
        addTest(new TimeTestPQTLPeek());
    }


    TimeTestHeapPush::TimeTestHeapPush() :
        SimpleTest("TimeTestHeapPush")
    {
    }

    void TimeTestHeapPush::test()
    {
        srand((int)time(NULL));
        structures::Heap<int>* testHeap = new structures::Heap<int>();
        structures::Logger::getInstance().logInfo("Casova zlozitost Heap::push");

        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                testHeap->push(i + j + 1000, i);
            }
            SimpleTest::startStopwatch();
            testHeap->push(1000 - i, i);
            SimpleTest::stopStopwatch();
            structures::Logger::getInstance().logDuration(testHeap->size(), SimpleTest::getElapsedTime(), "");
        }

        delete testHeap;
    }


    TimeTestHeapPop::TimeTestHeapPop() :
        SimpleTest("TimeTestHeapPop")
    {
    }

    void TimeTestHeapPop::test()
    {
        srand((int)time(NULL));
        structures::Heap<int>* testHeap = new structures::Heap<int>();
        structures::Logger::getInstance().logInfo("Casova zlozitost Heap::pop");

        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                testHeap->push(rand() % (i + j + 1), i);
            }
            SimpleTest::startStopwatch();
            testHeap->pop();
            SimpleTest::stopStopwatch();
            structures::Logger::getInstance().logDuration(testHeap->size(), SimpleTest::getElapsedTime(), "");
        }

        delete testHeap;
    }


    TimeTestHeapPeek::TimeTestHeapPeek() :
        SimpleTest("TimeTestHeapPeek")
    {
    }

    void TimeTestHeapPeek::test()
    {
        srand((int)time(NULL));
        structures::Heap<int>* testHeap = new structures::Heap<int>();
        structures::Logger::getInstance().logInfo("Casova zlozitost Heap::peek");

        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                testHeap->push(rand() % (i + j + 1), i);
            }
            SimpleTest::startStopwatch();
            testHeap->peek();
            SimpleTest::stopStopwatch();
            structures::Logger::getInstance().logDuration(testHeap->size(), SimpleTest::getElapsedTime(), "");
        }

        delete testHeap;
    }


    TimeTestPQTLPush::TimeTestPQTLPush() :
        SimpleTest("TimeTestPQTLPush")
    {
    }

    void TimeTestPQTLPush::test()
    {
        srand((int)time(NULL));
        structures::PriorityQueueTwoLists<int>* testPQTL = new structures::PriorityQueueTwoLists<int>();
        structures::Logger::getInstance().logInfo("Casova zlozitost PriorityQueueTwoLists::push");

        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                testPQTL->push(i + j + 1000, i);
            }
            SimpleTest::startStopwatch();
            testPQTL->push(1000 - i, i);
            SimpleTest::stopStopwatch();
            structures::Logger::getInstance().logDuration(testPQTL->size(), SimpleTest::getElapsedTime(), "");
        }

        delete testPQTL;
    }


    TimeTestPQTLPop::TimeTestPQTLPop() :
        SimpleTest("TimeTestPQTLPop")
    {
    }

    void TimeTestPQTLPop::test()
    {
        structures::PriorityQueueTwoLists<int>* testPQTL = new structures::PriorityQueueTwoLists<int>();
        structures::Logger::getInstance().logInfo("Casova zlozitost PriorityQueueTwoLists::pop");

        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                testPQTL->push(i + j + 1, i);
            }
            SimpleTest::startStopwatch();
            testPQTL->pop();
            SimpleTest::stopStopwatch();
            structures::Logger::getInstance().logDuration(testPQTL->size(), SimpleTest::getElapsedTime(), "");
        }

        delete testPQTL;
    }


    TimeTestPQTLPeek::TimeTestPQTLPeek() :
        SimpleTest("TimeTestPQTLPeek")
    {
    }

    void TimeTestPQTLPeek::test()
    {
        srand((int)time(NULL));
        structures::PriorityQueueTwoLists<int>* testPQTL = new structures::PriorityQueueTwoLists<int>();
        structures::Logger::getInstance().logInfo("Casova zlozitost PriorityQueueTwoLists::peek");

        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                testPQTL->push(rand() % (i + j + 1), i);
            }
            SimpleTest::startStopwatch();
            testPQTL->peek();
            SimpleTest::stopStopwatch();
            structures::Logger::getInstance().logDuration(testPQTL->size(), SimpleTest::getElapsedTime(), "");
        }

        delete testPQTL;
    }
}