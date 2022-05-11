#pragma once

#include "../test.h"
#include "../../structures/list/array_list.h"
#include "../../structures/list/linked_list.h"
#include "../../structures/list/double_linked_list.h"

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania listu avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class ListTestInterface
		: public SimpleTest
	{
	public:
		ListTestInterface(std::string name);
		void test() override;

	protected:
		virtual structures::List<int>* makeList() const = 0;
	};

	/// <summary>
	/// Zavola vsetky metody ArrayListu.
	/// </summary>
	class ArrayListTestInterface
		: public ListTestInterface
	{
	public:
		ArrayListTestInterface();

	protected:
		structures::List<int>* makeList() const override;
	};

	/// <summary>
	/// Zavola vsetky metody LinkedListu.
	/// </summary>
	class LinkedListTestInterface
		: public ListTestInterface
	{
	public:
		LinkedListTestInterface();

	protected:
		structures::List<int>* makeList() const override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju ArrayList.
	/// </summary>
	class ArrayListTestOverall
		: public ComplexTest
	{
	public:
		ArrayListTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju LinkedList.
	/// </summary>
	class LinkedListTestOverall
		: public ComplexTest
	{
	public:
		LinkedListTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju ArrayList a LinkedList.
	/// </summary>
	class ListTestOverall :
		public ComplexTest
	{
	public:
		ListTestOverall();
	};

	//-------------------------------------------------------
	//-------------------------------------------------------

	class ListTestScenare :
		public ComplexTest
	{
	public:
		ListTestScenare();
	};

	class ListTestScenar
		: public SimpleTest
	{
	public:
		ListTestScenar(const char* testNazov);
		void testScenar(structures::List<int>* list, float insert, float removeAt, float at, float getIndexOf);
	};

	class TestScenarAal
		: public ListTestScenar
	{
	public:
		TestScenarAal();
		void test() override;
	};

	class TestScenarBal
		: public ListTestScenar
	{
	public:
		TestScenarBal();
		void test() override;
	};

	class TestScenarCal
		: public ListTestScenar
	{
	public:
		TestScenarCal();
		void test() override;
	};

	class TestScenarAdll
		: public ListTestScenar
	{
	public:
		TestScenarAdll();
		void test() override;
	};

	class TestScenarBdll
		: public ListTestScenar
	{
	public:
		TestScenarBdll();
		void test() override;
	};

	class TestScenarCdll
		: public ListTestScenar
	{
	public:
		TestScenarCdll();
		void test() override;
	};

	//-------------------------------------------------------

	class ListTestTime :
		public ComplexTest
	{
	public:
		ListTestTime();
	};

	class TestTimeInsertal
		: public SimpleTest
	{
	public:
		TestTimeInsertal();
		void test() override;
	};

	class TestTimeAtal
		: public SimpleTest
	{
	public:
		TestTimeAtal();
		void test() override;
	};

	class TestTimeRemoveAtal
		: public SimpleTest
	{
	public:
		TestTimeRemoveAtal();
		void test() override;
	};

	class TestTimeInsertdll
		: public SimpleTest
	{
	public:
		TestTimeInsertdll();
		void test() override;
	};

	class TestTimeAtdll
		: public SimpleTest
	{
	public:
		TestTimeAtdll();
		void test() override;
	};

	class TestTimeRemoveAtdll
		: public SimpleTest
	{
	public:
		TestTimeRemoveAtdll();
		void test() override;
	};

	//-------------------------------------------------------
	//-------------------------------------------------------

	class ArrayListTestInsert :
		public SimpleTest
	{
	public:
		ArrayListTestInsert();
		void test() override;
	};

	class ArrayListTestRemove :
		public SimpleTest
	{
	public:
		ArrayListTestRemove();
		void test() override;
	};

	class DoubleLinkedListTestInsert :
		public SimpleTest
	{
	public:
		DoubleLinkedListTestInsert();
		void test() override;
	};

	class DoubleLinkedListTestRemove :
		public SimpleTest
	{
	public:
		DoubleLinkedListTestRemove();
		void test() override;
	};
}