#include "list_test.h"

namespace tests
{
	// ListTestInterface:

	ListTestInterface::ListTestInterface(std::string name) :
		SimpleTest(std::move(name))
	{
	}

	void ListTestInterface::test()
	{
		int x = 0;
		structures::List<int>* list = this->makeList();
		list->add(x);
		list->assign(*list);
		list->clear();
		delete list->getBeginIterator();
		delete list->getEndIterator();
		list->getIndexOf(x);
		list->insert(x, x);
		list->isEmpty();
		list->operator[](0);
		list->removeAt(0);
		list->size();
		list->tryRemove(x);
		delete list;
		this->logPass("Compiled.");
	}

	// ArrayListTestInterface:

	ArrayListTestInterface::ArrayListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* ArrayListTestInterface::makeList() const
	{
		return new structures::ArrayList<int>();
	}

	// LinkedListTestInterface:

	LinkedListTestInterface::LinkedListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* LinkedListTestInterface::makeList() const
	{
		return new structures::LinkedList<int>();
	}

	// ArrayListTestOverall:

	ArrayListTestOverall::ArrayListTestOverall() :
		ComplexTest("ArrayList")
	{
		addTest(new ArrayListTestInterface());
		addTest(new ArrayListTestInsert());
		addTest(new ArrayListTestRemove());
	}

	// LinkedListTestOverall:

	LinkedListTestOverall::LinkedListTestOverall() :
		ComplexTest("LinkedList")
	{
		addTest(new LinkedListTestInterface());
		addTest(new DoubleLinkedListTestInsert());
		addTest(new DoubleLinkedListTestRemove());
	}

	// ListTestOverall:

	ListTestOverall::ListTestOverall() :
		ComplexTest("List")
	{
		addTest(new ArrayListTestOverall());
		addTest(new LinkedListTestOverall());
		addTest(new ListTestScenare());
		addTest(new ListTestTime());
	}

	//-------------------------------------------------------
	//-------------------------------------------------------

	ArrayListTestInsert::ArrayListTestInsert() :
		SimpleTest("ArrayListInsert")
	{
	}

	void ArrayListTestInsert::test()
	{
		structures::ArrayList<int>* testArray = new structures::ArrayList<int>;
		testArray->add(10);
		testArray->add(20);
		testArray->add(30);
		testArray->add(40);
		SimpleTest::assertTrue(testArray->size() == 4, "Size 4");
		testArray->add(100);
		testArray->add(200);
		testArray->add(300);
		testArray->add(400);
		SimpleTest::assertTrue(testArray->size() == 8, "Size 8");

		for (size_t i = 0; i < 9; i++)
		{
			testArray->insert(1, 0);
		}
		SimpleTest::assertTrue(testArray->size() == 17, "Size 17");

		testArray->insert(7, 0);
		testArray->insert(77, 4);
		testArray->insert(777, 18);
		testArray->insert(7777, 20);
		SimpleTest::assertTrue(testArray->size() == 21, "Size 21");

		structures::ArrayList<int>* porovArray = new structures::ArrayList<int>;
		porovArray->add(7);
		porovArray->add(1);
		porovArray->add(1);
		porovArray->add(1);
		porovArray->add(77);
		porovArray->add(1);
		porovArray->add(1);
		porovArray->add(1);
		porovArray->add(1);
		porovArray->add(1);
		porovArray->add(1);
		porovArray->add(10);
		porovArray->add(20);
		porovArray->add(30);
		porovArray->add(40);
		porovArray->add(100);
		porovArray->add(200);
		porovArray->add(300);
		porovArray->add(777);
		porovArray->add(400);
		porovArray->add(7777);
		SimpleTest::assertTrue(porovArray->equals(*testArray), "metoda equals v inserte");

		SimpleTest::assertTrue(testArray->at(0) == 7, "ma byt 7 je " + std::to_string(testArray->at(0)));
		SimpleTest::assertTrue(testArray->at(1) == 1, "ma byt 1 je " + std::to_string(testArray->at(1)));
		SimpleTest::assertTrue(testArray->at(2) == 1, "ma byt 1 je " + std::to_string(testArray->at(2)));
		SimpleTest::assertTrue(testArray->at(3) == 1, "ma byt 1 je " + std::to_string(testArray->at(3)));
		SimpleTest::assertTrue(testArray->at(4) == 77, "ma byt 77 je " + std::to_string(testArray->at(4)));
		SimpleTest::assertTrue(testArray->at(5) == 1, "ma byt 1 je " + std::to_string(testArray->at(5)));
		SimpleTest::assertTrue(testArray->at(6) == 1, "ma byt 1 je " + std::to_string(testArray->at(6)));
		SimpleTest::assertTrue(testArray->at(7) == 1, "ma byt 1 je " + std::to_string(testArray->at(7)));
		SimpleTest::assertTrue(testArray->at(8) == 1, "ma byt 1 je " + std::to_string(testArray->at(8)));
		SimpleTest::assertTrue(testArray->at(9) == 1, "ma byt 1 je " + std::to_string(testArray->at(9)));
		SimpleTest::assertTrue(testArray->at(10) == 1, "ma byt 1 je " + std::to_string(testArray->at(10)));
		SimpleTest::assertTrue(testArray->at(11) == 10, "ma byt 10 je " + std::to_string(testArray->at(11)));
		SimpleTest::assertTrue(testArray->at(12) == 20, "ma byt 20 je " + std::to_string(testArray->at(12)));
		SimpleTest::assertTrue(testArray->at(13) == 30, "ma byt 30 je " + std::to_string(testArray->at(13)));
		SimpleTest::assertTrue(testArray->at(14) == 40, "ma byt 40 je " + std::to_string(testArray->at(14)));
		SimpleTest::assertTrue(testArray->at(15) == 100, "ma byt 100 je " + std::to_string(testArray->at(15)));
		SimpleTest::assertTrue(testArray->at(16) == 200, "ma byt 200 je " + std::to_string(testArray->at(16)));
		SimpleTest::assertTrue(testArray->at(17) == 300, "ma byt 300 je " + std::to_string(testArray->at(17)));
		SimpleTest::assertTrue(testArray->at(18) == 777, "ma byt 777 je " + std::to_string(testArray->at(18)));
		SimpleTest::assertTrue(testArray->at(19) == 400, "ma byt 400 je " + std::to_string(testArray->at(19)));
		SimpleTest::assertTrue(testArray->at(20) == 7777, "ma byt 7777 je " + std::to_string(testArray->at(20)));
		delete testArray;
		delete porovArray;
	}

	ArrayListTestRemove::ArrayListTestRemove()
		:SimpleTest("ArrayListTestRemove")
	{
	}

	void ArrayListTestRemove::test()
	{
		structures::ArrayList<int>* testArray = new structures::ArrayList<int>;
		for (int i = 0; i < 100; i++)
		{
			testArray->add(i);
		}

		testArray->removeAt(99);
		SimpleTest::assertTrue(testArray->size() == 99, "Velkost Array 99 v ArrayListTestRemove");
		SimpleTest::assertTrue(testArray->getIndexOf(99) == -1, "Bol vymazany prvok s cislom 99");
		testArray->removeAt(50);
		SimpleTest::assertTrue(testArray->size() == 98, "Velkost Array 98 v ArrayListTestRemove");
		SimpleTest::assertTrue(testArray->getIndexOf(50) == -1, "Bol vymazany prvok s cislom 50");
		testArray->removeAt(0);
		SimpleTest::assertTrue(testArray->size() == 97, "Velkost Array 97 v ArrayListTestRemove");
		SimpleTest::assertTrue(testArray->getIndexOf(0) == -1, "Bol vymazany prvok s cislom 0");

		for (int i = 5; i < 100; i+=5)
		{
			if (!testArray->tryRemove(i)) {
				SimpleTest::assertTrue(testArray->getIndexOf(50) == -1, "Nenasiel sa prvok s cislom 50");
			}
		}
		SimpleTest::assertTrue(testArray->size() == 79, "Velkost Array 79 v ArrayListTestRemove");

		for (int i = 0; i < 100; i+=5)
		{
			SimpleTest::assertTrue(testArray->getIndexOf(i) == -1, "Bol vymazany prvok s cislom: " + std::to_string(i));
		}

		testArray->clear();
		SimpleTest::assertTrue(testArray->isEmpty() == true, "ArrayList je prázdny");
		delete testArray;
	}

	DoubleLinkedListTestInsert::DoubleLinkedListTestInsert()
		:SimpleTest("DoubleLinkedListTestInsert")
	{
	}

	void DoubleLinkedListTestInsert::test()
	{
		structures::DoubleLinkedList<int>* testList = new structures::DoubleLinkedList<int>;
		testList->add(10);
		testList->add(20);
		testList->add(30);
		testList->add(40);
		SimpleTest::assertTrue(testList->size() == 4, "Size 4");
		testList->add(100);
		testList->add(200);
		testList->add(300);
		testList->add(400);
		SimpleTest::assertTrue(testList->size() == 8, "Size 8");

		for (size_t i = 0; i < 9; i++)
		{
			testList->insert(1, 0);
		}
		SimpleTest::assertTrue(testList->size() == 17, "Size 17");

		testList->insert(7, 0);
		testList->insert(77, 4);
		testList->insert(777, 18);
		testList->insert(7777, 20);
		SimpleTest::assertTrue(testList->size() == 21, "Size 21");

		structures::DoubleLinkedList<int>* porovList = new structures::DoubleLinkedList<int>;
		porovList->add(7);
		porovList->add(1);
		porovList->add(1);
		porovList->add(1);
		porovList->add(77);
		porovList->add(1);
		porovList->add(1);
		porovList->add(1);
		porovList->add(1);
		porovList->add(1);
		porovList->add(1);
		porovList->add(10);
		porovList->add(20);
		porovList->add(30);
		porovList->add(40);
		porovList->add(100);
		porovList->add(200);
		porovList->add(300);
		porovList->add(777);
		porovList->add(400);
		porovList->add(7777);
		SimpleTest::assertTrue(porovList->equals(*testList), "metoda equals v inserte");

		SimpleTest::assertTrue(testList->at(0) == 7, "ma byt 7 je " + std::to_string(testList->at(0)));
		SimpleTest::assertTrue(testList->at(1) == 1, "ma byt 1 je " + std::to_string(testList->at(1)));
		SimpleTest::assertTrue(testList->at(2) == 1, "ma byt 1 je " + std::to_string(testList->at(2)));
		SimpleTest::assertTrue(testList->at(3) == 1, "ma byt 1 je " + std::to_string(testList->at(3)));
		SimpleTest::assertTrue(testList->at(4) == 77, "ma byt 77 je " + std::to_string(testList->at(4)));
		SimpleTest::assertTrue(testList->at(5) == 1, "ma byt 1 je " + std::to_string(testList->at(5)));
		SimpleTest::assertTrue(testList->at(6) == 1, "ma byt 1 je " + std::to_string(testList->at(6)));
		SimpleTest::assertTrue(testList->at(7) == 1, "ma byt 1 je " + std::to_string(testList->at(7)));
		SimpleTest::assertTrue(testList->at(8) == 1, "ma byt 1 je " + std::to_string(testList->at(8)));
		SimpleTest::assertTrue(testList->at(9) == 1, "ma byt 1 je " + std::to_string(testList->at(9)));
		SimpleTest::assertTrue(testList->at(10) == 1, "ma byt 1 je " + std::to_string(testList->at(10)));
		SimpleTest::assertTrue(testList->at(11) == 10, "ma byt 10 je " + std::to_string(testList->at(11)));
		SimpleTest::assertTrue(testList->at(12) == 20, "ma byt 20 je " + std::to_string(testList->at(12)));
		SimpleTest::assertTrue(testList->at(13) == 30, "ma byt 30 je " + std::to_string(testList->at(13)));
		SimpleTest::assertTrue(testList->at(14) == 40, "ma byt 40 je " + std::to_string(testList->at(14)));
		SimpleTest::assertTrue(testList->at(15) == 100, "ma byt 100 je " + std::to_string(testList->at(15)));
		SimpleTest::assertTrue(testList->at(16) == 200, "ma byt 200 je " + std::to_string(testList->at(16)));
		SimpleTest::assertTrue(testList->at(17) == 300, "ma byt 300 je " + std::to_string(testList->at(17)));
		SimpleTest::assertTrue(testList->at(18) == 777, "ma byt 777 je " + std::to_string(testList->at(18)));
		SimpleTest::assertTrue(testList->at(19) == 400, "ma byt 400 je " + std::to_string(testList->at(19)));
		SimpleTest::assertTrue(testList->at(20) == 7777, "ma byt 7777 je " + std::to_string(testList->at(20)));
		delete testList;
		delete porovList;
	}


	DoubleLinkedListTestRemove::DoubleLinkedListTestRemove()
		:SimpleTest("DoubleLinkedListTestRemove")
	{
	}

	void DoubleLinkedListTestRemove::test()
	{
		structures::DoubleLinkedList<int>* testList = new structures::DoubleLinkedList<int>;
		for (int i = 0; i < 100; i++)
		{
			testList->add(i);
		}

		testList->removeAt(99);
		SimpleTest::assertTrue(testList->size() == 99, "Velkost DoubleLinkedList 99 v DoubleLinkedListTestRemove");
		SimpleTest::assertTrue(testList->getIndexOf(99) == -1, "Bol vymazany prvok s cislom 99");
		testList->removeAt(50);
		SimpleTest::assertTrue(testList->size() == 98, "Velkost DoubleLinkedList 98 v DoubleLinkedListTestRemove");
		SimpleTest::assertTrue(testList->getIndexOf(50) == -1, "Bol vymazany prvok s cislom 50");
		testList->removeAt(0);
		SimpleTest::assertTrue(testList->size() == 97, "Velkost DoubleLinkedList 97 v DoubleLinkedListTestRemove");
		SimpleTest::assertTrue(testList->getIndexOf(0) == -1, "Bol vymazany prvok s cislom 0");

		for (int i = 5; i < 100; i += 5)
		{
			if (!testList->tryRemove(i)) {
				SimpleTest::assertTrue(testList->getIndexOf(50) == -1, "Nenasiel sa prvok s cislom 50");
			}
		}
		SimpleTest::assertTrue(testList->size() == 79, "Velkost DoubleLinkedList 79 v DoubleLinkedListTestRemove");

		for (int i = 0; i < 100; i += 5)
		{
			SimpleTest::assertTrue(testList->getIndexOf(i) == -1, "Bol vymazany prvok s cislom: " + std::to_string(i));
		}

		testList->clear();
		SimpleTest::assertTrue(testList->isEmpty() == true, "DoubleLinkedList je prázdny");
		delete testList;
	}

	//-------------------------------------------------------
	//-------------------------------------------------------

	ListTestScenare::ListTestScenare()
		:ComplexTest("TestyScenarov")
	{
		addTest(new TestScenarAal());
		addTest(new TestScenarBal());
		addTest(new TestScenarCal());
		addTest(new TestScenarAdll());
		addTest(new TestScenarBdll());
		addTest(new TestScenarCdll());
	}

	ListTestScenar::ListTestScenar(const char* testNazov)
		:SimpleTest(testNazov)
	{
	}

	void ListTestScenar::testScenar(structures::List<int>* list, float insert, float removeAt, float at, float getIndexOf)
	{
		srand((int)time(NULL));
		/*structures::List<int>* list = nullptr;
		if (listType.compare("ArrayList")) {
			list = new structures::ArrayList<int>();
		}
		else {
			list = new structures::DoubleLinkedList<int>();
		}

		for (int i = 0; i < 100; i++)
		{
			list->add(i);
		}*/

		int opCounter = 0;
		int insertCounter = 0;
		int removeCounter = 0;
		int atCounter = 0;
		int indexCounter = 0;
		int k = 0;
		auto timeCounter = SimpleTest::getElapsedTime();
		while (opCounter < 100000) {
			k = rand() % 100;
			if (k < 100 * insert) {
				if (insertCounter < 100000 * insert) {
					int x = rand() % 100000;
					int y = rand() % list->size();
					SimpleTest::startStopwatch();
					list->insert(x, y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					insertCounter++;
				}
			}
			if (k >= 100 * insert && k < 100 * (insert + removeAt)) {
				if (removeCounter < 100000 * removeAt) {
					int y = rand() % list->size();
					SimpleTest::startStopwatch();
					list->removeAt(y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					removeCounter++;
				}
			}
			if (k >= 100 * (insert + removeAt) && k < 100 * (insert + removeAt + at)) {
				if (atCounter < 100000 * at) {
					int y = rand() % list->size();
					SimpleTest::startStopwatch();
					list->at(y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					atCounter++;
				}
			}
			if (k >= 100 * (insert + removeAt + at) && k < 100) {
				if (indexCounter < 100000 * getIndexOf) {
					int x = rand() % 100000;
					SimpleTest::startStopwatch();
					list->getIndexOf(x);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					indexCounter++;
				}
			}
			opCounter = insertCounter + removeCounter + atCounter + indexCounter;
		}
		structures::Logger::getInstance().logDuration(list->size(), timeCounter,
			SimpleTest::getName());
	}

	TestScenarAal::TestScenarAal()
		:ListTestScenar("TestScenarAal")
	{
	}

	void TestScenarAal::test()
	{
		auto testList = new structures::ArrayList<int>();
		for (int i = 0; i < 50000; i++)
		{
			testList->add(i);
		}
		testScenar(testList, 0.20, 0.20, 0.50, 0.10);
		delete testList;
	}


	TestScenarBal::TestScenarBal()
		:ListTestScenar("TestScenarBal")
	{
	}

	void TestScenarBal::test()
	{
		auto testList = new structures::ArrayList<int>();
		for (int i = 0; i < 50000; i++)
		{
			testList->add(i);
		}
		testScenar(testList, 0.35, 0.35, 0.20, 0.10);
		delete testList;
	}


	TestScenarCal::TestScenarCal()
		:ListTestScenar("TestScenarCal")
	{
	}

	void TestScenarCal::test()
	{
		auto testList = new structures::ArrayList<int>();
		for (int i = 0; i < 50000; i++)
		{
			testList->add(i);
		}
		testScenar(testList, 0.45, 0.45, 0.05, 0.05);
		delete testList;
	}


	TestScenarAdll::TestScenarAdll()
		:ListTestScenar("TestScenarAdll")
	{
	}

	void TestScenarAdll::test()
	{	
		auto testList = new structures::DoubleLinkedList<int>();
		for (int i = 0; i < 50000; i++)
		{
			testList->add(i);
		}
		testScenar(testList, 0.20, 0.20, 0.50, 0.10);
		delete testList;
	}


	TestScenarBdll::TestScenarBdll()
		:ListTestScenar("TestScenarBdll")
	{
	}

	void TestScenarBdll::test()
	{
		auto testList = new structures::DoubleLinkedList<int>();
		for (int i = 0; i < 50000; i++)
		{
			testList->add(i);
		}
		testScenar(testList, 0.35, 0.35, 0.20, 0.10);
		delete testList;
	}


	TestScenarCdll::TestScenarCdll()
		:ListTestScenar("TestScenarCdll")
	{
	}

	void TestScenarCdll::test()
	{
		auto testList = new structures::DoubleLinkedList<int>();
		for (int i = 0; i < 50000; i++)
		{
			testList->add(i);
		}
		testScenar(testList, 0.45, 0.45, 0.05, 0.05);
		delete testList;
	}

	//-------------------------------------------------------

	ListTestTime::ListTestTime()
		:ComplexTest("ListTestTime")
	{
		addTest(new TestTimeInsertal());
		addTest(new TestTimeAtal());
		addTest(new TestTimeRemoveAtal());
		addTest(new TestTimeInsertdll());
		addTest(new TestTimeAtdll());
		addTest(new TestTimeRemoveAtdll());
	}


	TestTimeInsertal::TestTimeInsertal()
		:SimpleTest("TestTimeInsertal")
	{
	}

	void TestTimeInsertal::test()
	{
		srand((int)time(NULL));
		structures::Logger::getInstance().logInfo("Casova zlozitost ArrayList::insert()");
		int number = 0;

		structures::ArrayList<int>* testArray = new structures::ArrayList<int>();
		for (int i = 0; i < 100; i++)
		{
			testArray->add(i);
		}

		for (int i = 0; i < 1000; i++)
		{
			number = rand() % 100;
			SimpleTest::startStopwatch();
			testArray->insert(number, testArray->size() / 2);
			SimpleTest::stopStopwatch();
			structures::Logger::getInstance().logDuration(testArray->size(), SimpleTest::getElapsedTime(), "");
			for (int i = 0; i < 100; i++)
			{
				testArray->add(i);
			}
		}
		delete testArray;
	}


	TestTimeAtal::TestTimeAtal()
		:SimpleTest("TestTimeAtal")
	{
	}

	void TestTimeAtal::test()
	{
		srand((int)time(NULL));
		structures::Logger::getInstance().logInfo("Casova zlozitost ArrayList::at()");

		structures::ArrayList<int>* testArray = new structures::ArrayList<int>();
		for (int i = 0; i < 100; i++)
		{
			testArray->add(i);
		}

		for (int i = 0; i < 1000; i++)
		{
			SimpleTest::startStopwatch();
			testArray->at(testArray->size() / 2);
			SimpleTest::stopStopwatch();
			structures::Logger::getInstance().logDuration(testArray->size(), SimpleTest::getElapsedTime(), "");
			for (int i = 0; i < 100; i++)
			{
				testArray->add(i);
			}
		}
		delete testArray;
	}


	TestTimeRemoveAtal::TestTimeRemoveAtal()
		:SimpleTest("TestTimeRemoveAtal")
	{
	}

	void TestTimeRemoveAtal::test()
	{
		srand((int)time(NULL));
		structures::Logger::getInstance().logInfo("Casova zlozitost ArrayList::removeAt()");

		structures::ArrayList<int>* testArray = new structures::ArrayList<int>();
		for (int i = 0; i < 100; i++)
		{
			testArray->add(i);
		}

		for (int i = 0; i < 1000; i++)
		{
			SimpleTest::startStopwatch();
			testArray->removeAt(testArray->size() / 2);
			SimpleTest::stopStopwatch();
			structures::Logger::getInstance().logDuration(testArray->size(), SimpleTest::getElapsedTime(), "");
			for (int i = 0; i < 100; i++)
			{
				testArray->add(i);
			}
		}
		delete testArray;
	}


	TestTimeInsertdll::TestTimeInsertdll()
		:SimpleTest("TestTimeInsertdll")
	{
	}

	void TestTimeInsertdll::test()
	{
		srand((int)time(NULL));
		structures::Logger::getInstance().logInfo("Casova zlozitost DoubleLinkedList::insert()");
		int number = 0;

		structures::DoubleLinkedList<int>* testList = new structures::DoubleLinkedList<int>();
		for (int i = 0; i < 100; i++)
		{
			testList->add(i);
		}

		for (int i = 0; i < 1000; i++)
		{
			number = rand() % 100;
			SimpleTest::startStopwatch();
			testList->insert(number, testList->size() / 2);
			SimpleTest::stopStopwatch();
			structures::Logger::getInstance().logDuration(testList->size(), SimpleTest::getElapsedTime(), "");
			for (int i = 0; i < 100; i++)
			{
				testList->add(i);
			}
		}
		delete testList;
	}


	TestTimeAtdll::TestTimeAtdll()
		:SimpleTest("TestTimeAtdll")
	{
	}

	void TestTimeAtdll::test()
	{
		srand((int)time(NULL));
		structures::Logger::getInstance().logInfo("Casova zlozitost DoubleLinkedList::at()");

		structures::DoubleLinkedList<int>* testList = new structures::DoubleLinkedList<int>();
		for (int i = 0; i < 100; i++)
		{
			testList->add(i);
		}

		for (int i = 0; i < 1000; i++)
		{
			SimpleTest::startStopwatch();
			testList->at(testList->size() / 2);
			SimpleTest::stopStopwatch();
			structures::Logger::getInstance().logDuration(testList->size(), SimpleTest::getElapsedTime(), "");
			for (int i = 0; i < 100; i++)
			{
				testList->add(i);
			}
		}
		delete testList;
	}


	TestTimeRemoveAtdll::TestTimeRemoveAtdll()
		:SimpleTest("TestTimeRemoveAtdll")
	{
	}

	void TestTimeRemoveAtdll::test()
	{
		srand((int)time(NULL));
		structures::Logger::getInstance().logInfo("Casova zlozitost DoubleLinkedList::removeAt()");

		structures::DoubleLinkedList<int>* testList = new structures::DoubleLinkedList<int>();
		for (int i = 0; i < 100; i++)
		{
			testList->add(i);
		}

		for (int i = 0; i < 1000; i++)
		{
			SimpleTest::startStopwatch();
			testList->removeAt(testList->size() / 2);
			SimpleTest::stopStopwatch();
			structures::Logger::getInstance().logDuration(testList->size(), SimpleTest::getElapsedTime(), "");
			for (int i = 0; i < 100; i++)
			{
				testList->add(i);
			}
		}
		delete testList;
	}
}