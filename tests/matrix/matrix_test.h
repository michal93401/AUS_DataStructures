#pragma once

#include "../test.h"
#include "../../structures/matrix/matrix.h"
#include "../../structures/_logger/logger.h"
#include <time.h>
#include <cstdlib>

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania matice avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class MatrixTestInterface
		: public SimpleTest
	{
	public:
		MatrixTestInterface();
		void test() override;

	protected:
		virtual structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const = 0;
	};

	/// <summary>
	/// Zavola vsetky metody koherentnej matice.
	/// </summary>
	class CoherentMatrixTestInterface
		: public MatrixTestInterface
	{
	protected:
		structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const override;
	};

	/// <summary>
	/// Zavola vsetky metody nekoherentnej matice.
	/// </summary>
	class IncoherentMatrixTestInterface
		: public MatrixTestInterface
	{
	protected:
		structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju CoherentMatrix.
	/// </summary>
	class CoherentMatrixTestOverall
		: public ComplexTest
	{
	public:
		CoherentMatrixTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju IncoherentMatrix.
	/// </summary>
	class IncoherentMatrixTestOverall
		: public ComplexTest
	{
	public:
		IncoherentMatrixTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju CoherrentMatrix a IncoherrentMatrix.
	/// </summary>
	class MatrixTestOverall
		: public ComplexTest
	{
	public:
		MatrixTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju scenare pre Matrix.
	/// </summary>
	class MatrixScenarTest
		: public ComplexTest
	{
	public:
		MatrixScenarTest();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju scenare pre CoherentMatrix.
	/// </summary>
	class CoherentMatrixScenarTest
		: public ComplexTest
	{
	public:
		CoherentMatrixScenarTest();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju scenare pre IncoherentMatrix.
	/// </summary>
	class IncoherentMatrixScenarTest
		: public ComplexTest
	{
	public:
		IncoherentMatrixScenarTest();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju casovu zlozitost metody at pre CoherentMatrix.
	/// </summary>
	class CoherentMatrixScenarTimeAt
		: public SimpleTest
	{
	public:
		CoherentMatrixScenarTimeAt();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju casovu zlozitost metody assign pre CoherentMatrix.
	/// </summary>
	class CoherentMatrixScenarTimeAssign
		: public SimpleTest
	{
	public:
		CoherentMatrixScenarTimeAssign();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju scenar A pre CoherentMatrix.
	/// </summary>
	class CoherentMatrixScenarTestA
		: public SimpleTest
	{
	public:
		CoherentMatrixScenarTestA();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju scenar B pre CoherentMatrix.
	/// </summary>
	class CoherentMatrixScenarTestB
		: public SimpleTest
	{
	public:
		CoherentMatrixScenarTestB();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju scenar C pre CoherentMatrix.
	/// </summary>
	class CoherentMatrixScenarTestC
		: public SimpleTest
	{
	public:
		CoherentMatrixScenarTestC();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju scenar D pre CoherentMatrix.
	/// </summary>
	class CoherentMatrixScenarTestD
		: public SimpleTest
	{
	public:
		CoherentMatrixScenarTestD();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju casovu zlozitost metody at pre IncoherentMatrix.
	/// </summary>
	class IncoherentMatrixScenarTimeAt
		: public SimpleTest
	{
	public:
		IncoherentMatrixScenarTimeAt();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju casovu zlozitost metody assign pre IncoherentMatrix.
	/// </summary>
	class IncoherentMatrixScenarTimeAssign
		: public SimpleTest
	{
	public:
		IncoherentMatrixScenarTimeAssign();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju scenar A pre IncoherentMatrix.
	/// </summary>
	class IncoherentMatrixScenarTestA
		: public SimpleTest
	{
	public:
		IncoherentMatrixScenarTestA();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju scenar B pre IncoherentMatrix.
	/// </summary>
	class IncoherentMatrixScenarTestB
		: public SimpleTest
	{
	public:
		IncoherentMatrixScenarTestB();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju scenar C pre IncoherentMatrix.
	/// </summary>
	class IncoherentMatrixScenarTestC
		: public SimpleTest
	{
	public:
		IncoherentMatrixScenarTestC();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju scenar D pre IncoherentMatrix.
	/// </summary>
	class IncoherentMatrixScenarTestD
		: public SimpleTest
	{
	public:
		IncoherentMatrixScenarTestD();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe testy, ktore testuju CoherentMatrix::at().
	/// </summary>
	class CoherentMatrixTestAt
		: public SimpleTest
	{
	public:
		CoherentMatrixTestAt();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe testy, ktore testuju CoherentMatrix::equals().
	/// </summary>
	class CoherentMatrixTestEquals
		: public SimpleTest
	{
	public:
		CoherentMatrixTestEquals();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe testy, ktore testuju CoherentMatrix::assign().
	/// </summary>
	class CoherentMatrixTestAssign
		: public SimpleTest
	{
	public:
		CoherentMatrixTestAssign();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju IncoherentMatrix::at().
	/// </summary>
	class IncoherentMatrixTestAt
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestAt();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju IncoherentMatrix::equals().
	/// </summary>
	class IncoherentMatrixTestEquals
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestEquals();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe testy, ktore testuju IncoherentMatrix::assign().
	/// </summary>
	class IncoherentMatrixTestAssign
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestAssign();
		void test() override;
	};
}