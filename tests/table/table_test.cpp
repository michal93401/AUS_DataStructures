#include "table_test.h"
#include "../../structures/table/binary_search_tree.h"
#include "../../structures/table/hash_table.h"
#include "../../structures/table/linked_table.h"
#include "../../structures/table/sorted_sequence_table.h"
#include "../../structures/table/table.h"
#include "../../structures/table/treap.h"
#include "../../structures/table/unsorted_sequence_table.h"

namespace tests
{
	TableTestInterface::TableTestInterface() :
		SimpleTest("Interface")
	{
	}

	void TableTestInterface::test()
	{
		int x = 0;
		structures::Table<int, int>* table = this->makeTable();
		table->equals(*table);
		table->assign(*table);
		table->insert(0, 0);
		table->find(0);
		table->remove(0);
		table->tryFind(0, x);
		table->containsKey(0);
		delete table;
		this->logPass("Compiled.");
	}

	structures::Table<int, int>* BinarySearchTreeTestInterface::makeTable()
	{
		return new structures::BinarySearchTree<int, int>();
	}

	structures::Table<int, int>* HashTableTestInterface::makeTable()
	{
		return new structures::HashTable<int, int>();
	}

	structures::Table<int, int>* LinkedTableTestInterface::makeTable()
	{
		return new structures::LinkedTable<int, int>();
	}

	structures::Table<int, int>* SortedSequenceTableTestInterface::makeTable()
	{
		return new structures::SortedSequenceTable<int, int>();
	}

	structures::Table<int, int>* TreapTestInterface::makeTable()
	{
		return new structures::Treap<int, int>();
	}

	structures::Table<int, int>* UnsortedSequenceTableTestInterface::makeTable()
	{
		return new structures::UnsortedSequenceTable<int, int>();
	}

	BinarySearchTreeTestOverall::BinarySearchTreeTestOverall() :
		ComplexTest("BinarySearchTree")
	{
		addTest(new BinarySearchTreeTestInterface());
		addTest(new BSTMethodsTest());
	}

	HashTableTestOverall::HashTableTestOverall() :
		ComplexTest("HashTable")
	{
		addTest(new HashTableTestInterface());
	}

	LinkedTableTestOverall::LinkedTableTestOverall() :
		ComplexTest("LinkedTable")
	{
		addTest(new LinkedTableTestInterface());
	}

	SortedSequenceTableTestOverall::SortedSequenceTableTestOverall() :
		ComplexTest("SortedSequenceTable")
	{
		addTest(new SortedSequenceTableTestInterface());
		addTest(new SSTMethodsTest());
	}

	TreapTestOverall::TreapTestOverall() :
		ComplexTest("Treap")
	{
		addTest(new TreapTestInterface());
	}

	UnsortedSequenceTableTestOverall::UnsortedSequenceTableTestOverall() :
		ComplexTest("UnsortedSequenceTable")
	{
		addTest(new UnsortedSequenceTableTestInterface());
	}

	TableTestOverall::TableTestOverall() :
		ComplexTest("Table")
	{
		addTest(new BinarySearchTreeTestOverall());
		//addTest(new HashTableTestOverall());
		addTest(new LinkedTableTestOverall());
		addTest(new SortedSequenceTableTestOverall());
		//addTest(new TreapTestOverall());
		addTest(new UnsortedSequenceTableTestOverall());
		addTest(new TableTestScenare());
		addTest(new TableTimeTest());
	}

	//-------------------------------------------------------
	//-------------------------------------------------------

	SSTMethodsTest::SSTMethodsTest() :
		SimpleTest("SSTMethodsTest")
	{
	}

	void SSTMethodsTest::test()
	{
		structures::SortedSequenceTable<int, int>* testTable = new structures::SortedSequenceTable<int, int>();
		srand((int)time(NULL));
		SimpleTest::logInfo("SortedSequenceTableMethodsTest");
		for (int i = 1; i < 11; i++)
		{
			testTable->insert(i, i);
		}
		SimpleTest::assertTrue(testTable->size() == 10, "Size 10");

		testTable->insert(0, 999);
		SimpleTest::assertTrue(testTable->containsKey(0) == true, "ContainsKey = 0");
		SimpleTest::assertTrue(testTable->size() == 11, "Size 11");
		int data = 0;
		SimpleTest::assertTrue(testTable->tryFind(10, data) == true, "tryFind found key 10");
		SimpleTest::assertTrue(data == 10, "Data found with value of 10");
		for (int i = 0; i < 11; i++)
		{
			testTable->remove(i);
		}
		SimpleTest::assertTrue(testTable->isEmpty() == true, "Size 0 = isEmpty");

		for (int i = 0; i < 10; i++)
		{
			testTable->insert(i, i);
		}
		structures::SortedSequenceTable<int, int>* testTable2 = new structures::SortedSequenceTable<int, int>(*testTable);
		int data2 = 0;
		SimpleTest::assertTrue(testTable2->size() == 10, "Copied table size 10");
		SimpleTest::assertTrue(testTable2->tryFind(5, data) == testTable->tryFind(5, data2), "tryFind(5, data1)_table1 = tryFind(5, data2)_table2");
		SimpleTest::assertTrue(data == data2, "data1 = data2");
		for (int i = 0; i < 10; i++)
		{
			testTable->remove(i);
		}
		SimpleTest::assertTrue(testTable->size() == 0, "Size 0");
		SimpleTest::assertTrue(testTable2->size() == 10, "Size 10");
		delete testTable;
		delete testTable2;
	}

	BSTMethodsTest::BSTMethodsTest() :
		SimpleTest("BSTMethodsTest")
	{
	}

	void BSTMethodsTest::test()
	{
		structures::BinarySearchTree<int, int>* testTree = new structures::BinarySearchTree<int, int>();
		srand((int)time(NULL));
		SimpleTest::logInfo("BinarySearchTreeMethodsTest");
		for (int i = 1; i < 11; i++)
		{
			testTree->insert(i, i);
		}
		SimpleTest::assertTrue(testTree->size() == 10, "Size 10");

		testTree->insert(0, 999);
		SimpleTest::assertTrue(testTree->containsKey(0) == true, "ContainsKey = 0");
		SimpleTest::assertTrue(testTree->size() == 11, "Size 11");
		int data = 0;
		SimpleTest::assertTrue(testTree->tryFind(10, data) == true, "tryFind found key 10");
		SimpleTest::assertTrue(data == 10, "Data found with value of 10");
		for (int i = 0; i < 11; i++)
		{
			testTree->remove(i);
		}
		SimpleTest::assertTrue(testTree->isEmpty() == true, "Size 0 = isEmpty");

		for (int i = 0; i < 10; i++)
		{
			testTree->insert(i, i);
		}
		structures::BinarySearchTree<int, int>* testTree2 = new structures::BinarySearchTree<int, int>(*testTree);
		int data2 = 0;
		SimpleTest::assertTrue(testTree2->size() == 10, "Copied table size 10");
		SimpleTest::assertTrue(testTree2->tryFind(5, data) == testTree->tryFind(5, data2), "tryFind(5, data1)_tree1 = tryFind(5, data2)_tree2");
		SimpleTest::assertTrue(data == data2, "data1 = data2");
		for (int i = 0; i < 10; i++)
		{
			testTree->remove(i);
		}
		SimpleTest::assertTrue(testTree->size() == 0, "Size 0");
		SimpleTest::assertTrue(testTree2->size() == 10, "Size 10");
		delete testTree;
		delete testTree2;
	}

	//-------------------------------------------------------

	TableTestScenare::TableTestScenare() :
		ComplexTest("TableTestScenare")
	{
		addTest(new TestScenarABST());
		addTest(new TestScenarBBST());
		addTest(new TestScenarASST());
		addTest(new TestScenarBSST());
	}


	TableTestScenar::TableTestScenar(const char* testNazov) :
		SimpleTest(testNazov)
	{
	}

	void TableTestScenar::testScenar(structures::Table<int, int>* table, float insert, float remove, float tryfind)
	{
		srand((int)time(NULL));
		int opCounter = 0;
		int insertCounter = 0;
		int removeCounter = 0;
		int tryfindCounter = 0;
		int size = 100000;
		int k = 0;
		int x = 0;
		auto timeCounter = SimpleTest::getElapsedTime();

		structures::Array<int>* HELP = new structures::Array<int>(200);
		for (int i = 0; i < 100; i++)
		{
			x = bigRandom(200);
			if (HELP->at(x) != 1) {
				HELP->at(x) = 1;
				table->insert(x, i);
			}
			else {
				i--;
			}
		}

		while (opCounter < 100000) {
			k = rand() % 100;
			if (k < 100 * insert) {
				if (insertCounter < 100000 * insert) {
					while (HELP->at(x) == 1)
					{
						x = bigRandom(size);
					}
					SimpleTest::startStopwatch();
					table->insert(x, insertCounter);
					SimpleTest::stopStopwatch();
					HELP->at(x) = 1;
					timeCounter += SimpleTest::getElapsedTime();
					insertCounter++;
				}
			}
			if (k >= 100 * insert && k < 100 * (insert + remove)) {
				if (removeCounter < 100000 * remove) {
					while (HELP->at(x) == 0)
					{
						x = bigRandom(size);
					}
					SimpleTest::startStopwatch();
					table->remove(x);
					SimpleTest::stopStopwatch();
					HELP->at(x) = 0;
					timeCounter += SimpleTest::getElapsedTime();
					removeCounter++;
				}
			}
			if (k >= 100 * (insert + remove) && k < 100) {
				if (tryfindCounter < 100000 * tryfind) {
					int y = 0;
					x = bigRandom(size);
					SimpleTest::startStopwatch();
					table->tryFind(x, y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					tryfindCounter++;
				}
			}
			opCounter = insertCounter + removeCounter + tryfindCounter;
		}
		structures::Logger::getInstance().logDuration(table->size(), timeCounter,
			SimpleTest::getName());
		delete HELP;
	}


	TestScenarASST::TestScenarASST() :
		TableTestScenar("TestScenarASST")
	{
	}

	void TestScenarASST::test()
	{
		auto testTable = new structures::SortedSequenceTable<int, int>();
		testScenar(testTable, 0.20, 0.20, 0.60);
		delete testTable;
	}


	TestScenarBSST::TestScenarBSST() :
		TableTestScenar("TestScenarBSST")
	{
	}

	void TestScenarBSST::test()
	{
		auto testTable = new structures::SortedSequenceTable<int, int>();
		testScenar(testTable, 0.40, 0.40, 0.20);
		delete testTable;
	}


	TestScenarABST::TestScenarABST() :
		TableTestScenar("TestScenarABST")
	{
	}

	void TestScenarABST::test()
	{
		auto testTree = new structures::BinarySearchTree<int, int>();
		testScenar(testTree, 0.20, 0.20, 0.60);
		delete testTree;
	}


	TestScenarBBST::TestScenarBBST() :
		TableTestScenar("TestScenarBBST")
	{
	}

	void TestScenarBBST::test()
	{
		auto testTree = new structures::BinarySearchTree<int, int>();
		testScenar(testTree, 0.40, 0.40, 0.20);
		delete testTree;
	}

	//-------------------------------------------------------

	TableTimeTest::TableTimeTest() :
		ComplexTest("TableTimeTest")
	{
		addTest(new TimeTestSSTinsert());
		addTest(new TimeTestSSTremove());
		addTest(new TimeTestSSTtryfind());
		addTest(new TimeTestBSTinsert());
		addTest(new TimeTestBSTremove());
		addTest(new TimeTestBSTtryfind());
	}


	TimeTestSSTinsert::TimeTestSSTinsert() :
		SimpleTest("TimeTestSSTinsert")
	{
	}

	void TimeTestSSTinsert::test()
	{
		structures::SortedSequenceTable<int, int>* testTable = new structures::SortedSequenceTable<int, int>();
		structures::Logger::getInstance().logInfo("Casova zlozitost SortedSequenceTable::insert");

		for (int i = 0; i < 1000; i++)
		{
			for (int j = (i * 100) + 1; j < (i * 100) + 101; j++)
			{
				testTable->insert(j, i);
			}
			SimpleTest::startStopwatch();
			testTable->insert(0, i);
			SimpleTest::stopStopwatch();
			testTable->remove(0);
			structures::Logger::getInstance().logDuration(testTable->size(), SimpleTest::getElapsedTime(), "");
		}

		delete testTable;
	}


	TimeTestSSTremove::TimeTestSSTremove() :
		SimpleTest("TimeTestSSTremove")
	{
	}

	void TimeTestSSTremove::test()
	{
		structures::SortedSequenceTable<int, int>* testTable = new structures::SortedSequenceTable<int, int>();
		structures::Logger::getInstance().logInfo("Casova zlozitost SortedSequenceTable::remove");

		for (int i = 0; i < 1000; i++)
		{
			for (int j = (i * 100) + 1; j < (i * 100) + 101; j++)
			{
				testTable->insert(j, i);
			}
			testTable->insert(0, i);
			SimpleTest::startStopwatch();
			testTable->remove(0);
			SimpleTest::stopStopwatch();
			structures::Logger::getInstance().logDuration(testTable->size(), SimpleTest::getElapsedTime(), "");
		}
		delete testTable;
	}


	TimeTestSSTtryfind::TimeTestSSTtryfind() :
		SimpleTest("TimeTestSSTtryfind")
	{
	}

	void TimeTestSSTtryfind::test()
	{
		structures::SortedSequenceTable<int, int>* testTable = new structures::SortedSequenceTable<int, int>();
		structures::Logger::getInstance().logInfo("Casova zlozitost SortedSequenceTable::tryFind");
		int x = 0;
		for (int i = 0; i < 1000; i++)
		{
			for (int j = (i * 100) + 1; j < (i * 100) + 101; j++)
			{
				testTable->insert(j, i);
			}
			SimpleTest::startStopwatch();
			testTable->tryFind(0, x);
			SimpleTest::stopStopwatch();
			structures::Logger::getInstance().logDuration(testTable->size(), SimpleTest::getElapsedTime(), "");
		}
		delete testTable;
	}


	TimeTestBSTinsert::TimeTestBSTinsert() :
		SimpleTest("TimeTestBSTinsert")
	{
	}

	void TimeTestBSTinsert::test()
	{
		structures::BinarySearchTree<int, int>* testTree = new structures::BinarySearchTree<int, int>();
		structures::Logger::getInstance().logInfo("Casova zlozitost BinarySearchTree::insert");
		structures::Array<int>* HELP = new structures::Array<int>(100001);
		int x = 0;
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				x = bigRandom(100000) + 1;
				if (HELP->at(x) != 1) {
					HELP->at(x) = 1;
					testTree->insert(x, j);
				}
				else {
					j--;
				}
			}
			SimpleTest::startStopwatch();
			testTree->insert(0, i);
			SimpleTest::stopStopwatch();
			testTree->remove(0);
			structures::Logger::getInstance().logDuration(testTree->size(), SimpleTest::getElapsedTime(), "");
		}
		delete HELP;
		delete testTree;
	}


	TimeTestBSTremove::TimeTestBSTremove() :
		SimpleTest("TimeTestBSTremove")
	{
	}

	void TimeTestBSTremove::test()
	{
		structures::BinarySearchTree<int, int>* testTree = new structures::BinarySearchTree<int, int>();
		structures::Logger::getInstance().logInfo("Casova zlozitost BinarySearchTree::remove");
		structures::Array<int>* HELP = new structures::Array<int>(100001);
		int x = 0;
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				x = bigRandom(100000) + 1;
				if (HELP->at(x) != 1) {
					HELP->at(x) = 1;
					testTree->insert(x, j);
				}
				else {
					j--;
				}
			}
			testTree->insert(0, i);
			SimpleTest::startStopwatch();
			testTree->remove(0);
			SimpleTest::stopStopwatch();
			structures::Logger::getInstance().logDuration(testTree->size(), SimpleTest::getElapsedTime(), "");
		}
		delete HELP;
		delete testTree;
	}


	TimeTestBSTtryfind::TimeTestBSTtryfind() :
		SimpleTest("TimeTestBSTtryfind")
	{
	}

	void TimeTestBSTtryfind::test()
	{
		structures::BinarySearchTree<int, int>* testTree = new structures::BinarySearchTree<int, int>();
		structures::Logger::getInstance().logInfo("Casova zlozitost BinarySearchTree::tryFind");
		structures::Array<int>* HELP = new structures::Array<int>(100001);
		int x = 0;
		int y = 0;
		//testTree->insert(50000, 50000);
		//HELP->at(50000) = 1;
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				x = bigRandom(100000) + 1;
				if (HELP->at(x) != 1) {
					HELP->at(x) = 1;
					testTree->insert(x, j);
				}
				else {
					j--;
				}
			}
			SimpleTest::startStopwatch();
			testTree->tryFind(100002, y);
			SimpleTest::stopStopwatch();
			structures::Logger::getInstance().logDuration(testTree->size(), SimpleTest::getElapsedTime(), "");
		}
		delete HELP;
		delete testTree;
	}


	int bigRandom(int size)
	{
		return (rand() * rand()) % size;
		//return (rand() + rand() + rand() + rand()) % size;
	}

}