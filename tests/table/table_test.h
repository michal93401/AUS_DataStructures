#pragma once

#include "../test.h"
#include "../../structures/table/table.h"

namespace tests
{
	int bigRandom(int size);

	/// <summary>
	/// Zavola vsetky metody z rozhrania tabulky avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class TableTestInterface
		: public SimpleTest
	{
	public:
		TableTestInterface();
		void test() override;

	protected:
		virtual structures::Table<int, int>* makeTable() = 0;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class BinarySearchTreeTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class HashTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class LinkedTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class SortedSequenceTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class TreapTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class UnsortedSequenceTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class BinarySearchTreeTestOverall
		: public ComplexTest
	{
	public:
		BinarySearchTreeTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class HashTableTestOverall
		: public ComplexTest
	{
	public:
		HashTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class LinkedTableTestOverall
		: public ComplexTest
	{
	public:
		LinkedTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class SortedSequenceTableTestOverall
		: public ComplexTest
	{
	public:
		SortedSequenceTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class TreapTestOverall
		: public ComplexTest
	{
	public:
		TreapTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class UnsortedSequenceTableTestOverall
		: public ComplexTest
	{
	public:
		UnsortedSequenceTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju tabulku.
	/// </summary>
	class TableTestOverall
		: public ComplexTest
	{
	public:
		TableTestOverall();
	};

	//-------------------------------------------------------
	//-------------------------------------------------------

	class SSTMethodsTest :
		public SimpleTest
	{
	public:
		SSTMethodsTest();
		void test() override;
	};

	class BSTMethodsTest :
		public SimpleTest
	{
	public:
		BSTMethodsTest();
		void test() override;
	};

	//-------------------------------------------------------

	class TableTestScenare :
		public ComplexTest
	{
	public:
		TableTestScenare();
	};

	class TableTestScenar
		: public SimpleTest
	{
	public:
		TableTestScenar(const char* testNazov);
		void testScenar(structures::Table<int, int>* table, float push, float pop, float peek);
	};

	class TestScenarASST
		: public TableTestScenar
	{
	public:
		TestScenarASST();
		void test() override;
	};

	class TestScenarBSST
		: public TableTestScenar
	{
	public:
		TestScenarBSST();
		void test() override;
	};

	class TestScenarABST
		: public TableTestScenar
	{
	public:
		TestScenarABST();
		void test() override;
	};

	class TestScenarBBST
		: public TableTestScenar
	{
	public:
		TestScenarBBST();
		void test() override;
	};

	//-------------------------------------------------------

	class TableTimeTest :
		public ComplexTest
	{
	public:
		TableTimeTest();
	};

	class TimeTestSSTinsert :
		public SimpleTest
	{
	public:
		TimeTestSSTinsert();
		void test() override;
	};

	class TimeTestSSTremove :
		public SimpleTest
	{
	public:
		TimeTestSSTremove();
		void test() override;
	};

	class TimeTestSSTtryfind :
		public SimpleTest
	{
	public:
		TimeTestSSTtryfind();
		void test() override;
	};

	class TimeTestBSTinsert :
		public SimpleTest
	{
	public:
		TimeTestBSTinsert();
		void test() override;
	};

	class TimeTestBSTremove :
		public SimpleTest
	{
	public:
		TimeTestBSTremove();
		void test() override;
	};

	class TimeTestBSTtryfind :
		public SimpleTest
	{
	public:
		TimeTestBSTtryfind();
		void test() override;
	};
}