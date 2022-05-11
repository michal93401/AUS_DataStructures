#pragma once

#include "../test.h"
#include "../../structures/priority_queue/priority_queue.h"
#include "../../structures/priority_queue/priority_queue_list.h"
#include "../../structures/priority_queue/heap.h"
#include "../../structures/priority_queue/priority_queue_two_lists.h"

namespace tests
{
    /// <summary>
    /// Zavola vsetky metody z rozhrania prioritneho frontu avsak nekontroluje ich spravnost.
    /// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
    /// </summary>
    class PriorityQueueTestInterface
        : public SimpleTest
    {
    public:
        PriorityQueueTestInterface();
        void test() override;

    protected:
        virtual structures::PriorityQueue<int>* makePriorityQueue() = 0;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLinkedListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueTwoListsTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class HeapTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /*/// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueUnsortedArrayListTestOverall();
    };*/

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueSortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLimitedSortedArrayListTestOverall();
    };

    /*/// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLinkedListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLinkedListTestOverall();
    };*/

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueTwoListsTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTwoListsTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class HeapTestOverall
        : public ComplexTest
    {
    public:
        HeapTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju prioritny front.
    /// </summary>
    class PriorityQueueTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTestOverall();
    };

    //-------------------------------------------------------
    //-------------------------------------------------------

    class HeapMethodsTest :
        public SimpleTest
    {
    public:
        HeapMethodsTest();
        void test() override;
    };

    class PQTLMethodsTest :
        public SimpleTest
    {
    public:
        PQTLMethodsTest();
        void test() override;
    };

    //-------------------------------------------------------

    class PQLTestScenare :
        public ComplexTest
    {
    public:
        PQLTestScenare();
    };

    class PQLTestScenar
        : public SimpleTest
    {
    public:
        PQLTestScenar(const char* testNazov);
        void testScenar(structures::PriorityQueue<int>* list, float push, float pop, float peek);
    };

    class TestScenarAheap
        : public PQLTestScenar
    {
    public:
        TestScenarAheap();
        void test() override;
    };

    class TestScenarBheap
        : public PQLTestScenar
    {
    public:
        TestScenarBheap();
        void test() override;
    };

    class TestScenarCheap
        : public PQLTestScenar
    {
    public:
        TestScenarCheap();
        void test() override;
    };

    class TestScenarAPQTL
        : public PQLTestScenar
    {
    public:
        TestScenarAPQTL();
        void test() override;
    };

    class TestScenarBPQTL
        : public PQLTestScenar
    {
    public:
        TestScenarBPQTL();
        void test() override;
    };

    class TestScenarCPQTL
        : public PQLTestScenar
    {
    public:
        TestScenarCPQTL();
        void test() override;
    };

    //-------------------------------------------------------

    class PQLTimeTest :
        public ComplexTest
    {
    public:
        PQLTimeTest();
    };

    class TimeTestHeapPush :
        public SimpleTest
    {
    public:
        TimeTestHeapPush();
        void test() override;
    };

    class TimeTestHeapPop :
        public SimpleTest
    {
    public:
        TimeTestHeapPop();
        void test() override;
    };

    class TimeTestHeapPeek :
        public SimpleTest
    {
    public:
        TimeTestHeapPeek();
        void test() override;
    };

    class TimeTestPQTLPush :
        public SimpleTest
    {
    public:
        TimeTestPQTLPush();
        void test() override;
    };

    class TimeTestPQTLPop :
        public SimpleTest
    {
    public:
        TimeTestPQTLPop();
        void test() override;
    };

    class TimeTestPQTLPeek :
        public SimpleTest
    {
    public:
        TimeTestPQTLPeek();
        void test() override;
    };
}