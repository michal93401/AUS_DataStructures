#include "matrix_test.h"
#include "../../structures/matrix/coherent_matrix.h"
#include "../../structures/matrix/incoherent_matrix.h"

namespace tests
{
	tests::MatrixTestInterface::MatrixTestInterface() :
		SimpleTest("Interface")
	{
	}

	void tests::MatrixTestInterface::test()
	{
		structures::Matrix<int>* matrix = this->makeMatrix(20, 20);
		matrix->assign(*matrix);
		matrix->equals(*matrix);
		matrix->size();
		matrix->isEmpty();
		matrix->getRowCount();
		matrix->getColumnCount();
		matrix->at(10, 10);
		delete matrix;
	}

	structures::Matrix<int>* CoherentMatrixTestInterface::makeMatrix(size_t rows, size_t cols) const
	{
		return new structures::CoherentMatrix<int>(rows, cols);
	}

	structures::Matrix<int>* IncoherentMatrixTestInterface::makeMatrix(size_t rows, size_t cols) const
	{
		return new structures::IncoherentMatrix<int>(rows, cols);
	}

	CoherentMatrixTestOverall::CoherentMatrixTestOverall() :
		ComplexTest("CoherentMatrix")
	{
		//addTest(new CoherentMatrixTestInterface());
		addTest(new CoherentMatrixTestAt());
		addTest(new CoherentMatrixTestEquals());
		addTest(new CoherentMatrixTestAssign());
	}

	IncoherentMatrixTestOverall::IncoherentMatrixTestOverall() :
		ComplexTest("IncoherentMatrix")
	{
		//addTest(new IncoherentMatrixTestInterface());
		addTest(new IncoherentMatrixTestAt());
		addTest(new IncoherentMatrixTestEquals());
		addTest(new IncoherentMatrixTestAssign());
	}

	MatrixTestOverall::MatrixTestOverall() :
		ComplexTest("Matrix")
	{
		addTest(new CoherentMatrixTestOverall());
		addTest(new IncoherentMatrixTestOverall());
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	CoherentMatrixTestAt::CoherentMatrixTestAt() :
		SimpleTest("CoherentMatrixTestAt")
	{
	}
	void CoherentMatrixTestAt::test()
	{
		structures::Logger::getInstance().logInfo("CoherentTestAt start");
		structures::CoherentMatrix<int>* testMatrix = new structures::CoherentMatrix<int>(8,8);
		auto timeCounter = SimpleTest::getElapsedTime();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				testMatrix->at(i, j) = i * j;
			}
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				SimpleTest::startStopwatch();
				SimpleTest::assertTrue(testMatrix->at(i, j) == i * j, "CoherentTestAt:: at (" + std::to_string(i) + "," + std::to_string(j) + "), expected" + std::to_string(i * j) + "result = " + std::to_string(testMatrix->at(i, j)));
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(0, SimpleTest::getElapsedTime(), ": CoherentTestAt at(i,j)");
				timeCounter += SimpleTest::getElapsedTime();
			}
		}
		structures::Logger::getInstance().logDuration(0, timeCounter, ": CoherentTestAt end");
		delete testMatrix;
	}

	CoherentMatrixTestEquals::CoherentMatrixTestEquals() :
		SimpleTest("CoherentMatrixTestEquals")
	{
	}
	void CoherentMatrixTestEquals::test()
	{
		structures::Logger::getInstance().logInfo("CoherentTestEquals start");
		structures::CoherentMatrix<int>* testMatrix = new structures::CoherentMatrix<int>(8, 8);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				testMatrix->at(i, j) = i * j;
			}
		}
		structures::CoherentMatrix<int>* copiedMatrix = new structures::CoherentMatrix<int>(*testMatrix);
		SimpleTest::startStopwatch();
		SimpleTest::assertTrue(testMatrix->equals(*copiedMatrix), "CoherentMatrix:: equals");
		SimpleTest::stopStopwatch();
		structures::Logger::getInstance().logDuration(0, SimpleTest::getElapsedTime(), ": CoherentTestEquals end");
		delete testMatrix;
		delete copiedMatrix;
	}

	CoherentMatrixTestAssign::CoherentMatrixTestAssign() :
		SimpleTest("CoherentMatrixTestAssign")
	{
	}
	void CoherentMatrixTestAssign::test()
	{
		structures::Logger::getInstance().logInfo("CoherentTestAssign start");
		structures::CoherentMatrix<int>* testMatrix = new structures::CoherentMatrix<int>(8, 8);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				testMatrix->at(i, j) = i * j;
			}
		}
		structures::CoherentMatrix<int>* copiedMatrix = new structures::CoherentMatrix<int>(8, 8);
		SimpleTest::startStopwatch();
		copiedMatrix->assign(*testMatrix);
		SimpleTest::stopStopwatch();
		SimpleTest::assertTrue(testMatrix->equals(*copiedMatrix), "CoherentMatrix:: assign");
		structures::Logger::getInstance().logDuration(0, SimpleTest::getElapsedTime(), ": CoherentTestAssign end");
		delete testMatrix;
		delete copiedMatrix;
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	IncoherentMatrixTestAt::IncoherentMatrixTestAt() :
		SimpleTest("IncoherentMatrixTestAt")
	{
	}
	void IncoherentMatrixTestAt::test()
	{
		structures::Logger::getInstance().logInfo("IncoherentTestAt start");
		structures::IncoherentMatrix<int>* testMatrix = new structures::IncoherentMatrix<int>(8, 8);
		auto timeCounter = SimpleTest::getElapsedTime();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				testMatrix->at(i, j) = i * j;
			}
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				SimpleTest::startStopwatch();
				SimpleTest::assertTrue(testMatrix->at(i, j) == i * j, "IncoherentMatrixTestAt:: at (" + std::to_string(i) + "," + std::to_string(j) + "), expected" + std::to_string(i * j) + "result = " + std::to_string(testMatrix->at(i, j)));
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(0, SimpleTest::getElapsedTime(), ": IncoherentTestAt at(i,j)");
				timeCounter += SimpleTest::getElapsedTime();
			}
		}
		structures::Logger::getInstance().logDuration(0, timeCounter, ": IncoherentTestAt end");
		delete testMatrix;
	}

	IncoherentMatrixTestEquals::IncoherentMatrixTestEquals() :
		SimpleTest("IncoherentMatrixTestEquals")
	{
	}
	void IncoherentMatrixTestEquals::test()
	{
		structures::Logger::getInstance().logInfo("IncoherentTestEquals start");
		structures::IncoherentMatrix<int>* testMatrix = new structures::IncoherentMatrix<int>(8, 8);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				testMatrix->at(i, j) = i * j;
			}
		}
		structures::IncoherentMatrix<int>* copiedMatrix = new structures::IncoherentMatrix<int>(*testMatrix);
		SimpleTest::startStopwatch();
		SimpleTest::assertTrue(testMatrix->equals(*copiedMatrix), "IncoherentMatrixTestEquals:: equals");
		SimpleTest::stopStopwatch();
		structures::Logger::getInstance().logDuration(0, SimpleTest::getElapsedTime(), ": IncoherentTestEquals end");
		delete testMatrix;
		delete copiedMatrix;
	}

	IncoherentMatrixTestAssign::IncoherentMatrixTestAssign() :
		SimpleTest("IncoherentMatrixTestAssign")
	{
	}
	void IncoherentMatrixTestAssign::test()
	{
		structures::Logger::getInstance().logInfo("IncoherentTestAssign start");
		structures::IncoherentMatrix<int>* testMatrix = new structures::IncoherentMatrix<int>(8, 8);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				testMatrix->at(i, j) = i * j;
			}
		}
		structures::IncoherentMatrix<int>* copiedMatrix = new structures::IncoherentMatrix<int>(8, 8);
		SimpleTest::startStopwatch();
		copiedMatrix->assign(*testMatrix);
		SimpleTest::stopStopwatch();
		SimpleTest::assertTrue(testMatrix->equals(*copiedMatrix), "IncoherentMatrixTestAssign:: assign");
		structures::Logger::getInstance().logDuration(0, SimpleTest::getElapsedTime(), ": IncoherentTestAssign end");
		delete testMatrix;
		delete copiedMatrix;
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	/// <summary>
	/// Testy scenarov a casovych zlozitosti
	/// </summary>
	MatrixScenarTest::MatrixScenarTest() :
		ComplexTest("MatrixScenarTest")
	{
		addTest(new CoherentMatrixScenarTest());
		addTest(new IncoherentMatrixScenarTest());
	}
	CoherentMatrixScenarTest::CoherentMatrixScenarTest() :
		ComplexTest("CoherentMatrixScenarTest")
	{
		addTest(new CoherentMatrixScenarTimeAt());
		addTest(new CoherentMatrixScenarTimeAssign());
		addTest(new CoherentMatrixScenarTestA());
		addTest(new CoherentMatrixScenarTestB());
		addTest(new CoherentMatrixScenarTestC());
		addTest(new CoherentMatrixScenarTestD());
	}
	IncoherentMatrixScenarTest::IncoherentMatrixScenarTest() :
		ComplexTest("IncoherentMatrixScenarTest")
	{
		addTest(new IncoherentMatrixScenarTimeAt());
		addTest(new IncoherentMatrixScenarTimeAssign());
		addTest(new IncoherentMatrixScenarTestA());
		addTest(new IncoherentMatrixScenarTestB());
		addTest(new IncoherentMatrixScenarTestC());
		addTest(new IncoherentMatrixScenarTestD());
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	CoherentMatrixScenarTimeAt::CoherentMatrixScenarTimeAt() :
		SimpleTest("CoherentMatrixScenarTimeAt")
	{
	}
	void CoherentMatrixScenarTimeAt::test()
	{
		// Definicia konstant pre test
		size_t krok = 100;
		size_t pocetOpakovani = 100;
		srand((int)time(NULL));
		// --------------------

		structures::Logger::getInstance().logInfo("CoherentMatrixTimeAt testovanie casovej zavislosti pre konstantne m, a n s krokom 100.");

		for (size_t i = 1; i < 26; i++)
		{
			auto testMatrix = new structures::CoherentMatrix<int>(250, i * krok);
			for (size_t x = 0; x < 250; x++)
			{
				for (size_t y = 0; y < (i * krok); y++) {
					testMatrix->at(x, y) = x + y;
				}
			}

			auto timeCounter = SimpleTest::getElapsedTime();
			int x = 0;
			int y = 0;
			for (size_t j = 0; j < pocetOpakovani; j++) {
				x = rand() % 250;
				y = rand() % (i * krok);
				SimpleTest::startStopwatch();
				testMatrix->at(x, y);
				SimpleTest::stopStopwatch();
				timeCounter += SimpleTest::getElapsedTime();
			}
			timeCounter /= pocetOpakovani;
			structures::Logger::getInstance().logDuration(i * krok, timeCounter, ": priemerny cas");
			delete testMatrix;
		}
		// --------------------
		
		structures::Logger::getInstance().logInfo("CoherentMatrixTimeAt testovanie casovej zavislosti pre konstantne n, a m s krokom 100.");

		for (size_t i = 1; i < 26; i++)
		{
			auto testMatrix = new structures::CoherentMatrix<int>(i * krok, 250);
			for (size_t x = 0; x < (i * krok); x++)
			{
				for (size_t y = 0; y < 250; y++) {
					testMatrix->at(x, y) = x + y;
				}
			}

			auto timeCounter = SimpleTest::getElapsedTime();
			int x = 0;
			int y = 0;
			for (size_t j = 0; j < pocetOpakovani; j++) {
				x = rand() % (i * krok);
				y = rand() % 250;
				SimpleTest::startStopwatch();
				testMatrix->at(x, y);
				SimpleTest::stopStopwatch();
				timeCounter += SimpleTest::getElapsedTime();
			}
			timeCounter /= pocetOpakovani;
			structures::Logger::getInstance().logDuration(i * krok, timeCounter, ": priemerny cas");
			delete testMatrix;
		}
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	CoherentMatrixScenarTimeAssign::CoherentMatrixScenarTimeAssign() :
		SimpleTest("CoherentMatrixScenarTimeAssign")
	{
	}
	void CoherentMatrixScenarTimeAssign::test()
	{
		// Definicia konstant pre test
		size_t krok = 100;
		size_t pocetOpakovani = 100;
		srand((int)time(NULL));
		// --------------------

		structures::Logger::getInstance().logInfo("CoherentMatrixTimeAssign testovanie casovej zavislosti pre konstantne m, a n s krokom 100.");

		for (size_t i = 1; i < 11; i++)
		{
			auto testMatrix = new structures::CoherentMatrix<int>(250, i * krok);
			for (size_t x = 0; x < 250; x++)
			{
				for (size_t y = 0; y < (i * krok); y++) {
					testMatrix->at(x, y) = x + x;
				}
			}

			auto timeCounter = SimpleTest::getElapsedTime();
			for (size_t j = 0; j < pocetOpakovani; j++) {
				auto testMatrix2 = new structures::CoherentMatrix<int>(250, i * krok);
				for (size_t x = 0; x < 250; x++)
				{
					for (size_t y = 0; y < (i * krok); y++) {
						testMatrix2->at(x, y) = y + y;
					}
				}
				SimpleTest::startStopwatch();
				testMatrix->assign(*testMatrix2);
				SimpleTest::stopStopwatch();
				timeCounter += SimpleTest::getElapsedTime();
				delete testMatrix2;
			}
			timeCounter /= pocetOpakovani;
			structures::Logger::getInstance().logDuration(i * krok, timeCounter, ": priemerny cas");
			delete testMatrix;
		}
		// ------------------

		structures::Logger::getInstance().logInfo("CoherentMatrixTimeAssign testovanie casovej zavislosti pre konstantne n, a m s krokom 100.");

		for (size_t i = 1; i < 11; i++)
		{
			auto testMatrix = new structures::CoherentMatrix<int>(i * krok, 250);
			for (size_t x = 0; x < (i * krok); x++)
			{
				for (size_t y = 0; y < 250; y++) {
					testMatrix->at(x, y) = x + x;
				}
			}

			auto timeCounter = SimpleTest::getElapsedTime();
			for (size_t j = 0; j < pocetOpakovani; j++) {
				auto testMatrix2 = new structures::CoherentMatrix<int>(i * krok,250);
				for (size_t x = 0; x < (i * krok); x++)
				{
					for (size_t y = 0; y < 250; y++) {
						testMatrix2->at(x, y) = y + y;
					}
				}
				SimpleTest::startStopwatch();
				testMatrix->assign(*testMatrix2);
				SimpleTest::stopStopwatch();
				timeCounter += SimpleTest::getElapsedTime();
				delete testMatrix2;
			}
			timeCounter /= pocetOpakovani;
			structures::Logger::getInstance().logDuration(i * krok, timeCounter, ": priemerny cas");
			delete testMatrix;
		}
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	CoherentMatrixScenarTestA::CoherentMatrixScenarTestA() :
		SimpleTest("CoherentMatrixScenarTestA")
	{
	}
	void CoherentMatrixScenarTestA::test()
	{
		// Definicia konstant pre test
		int pocetRiadkov = 10;
		int pocetStlpcov = 50;
		float percentRiadkov = 0.05;
		float percentStlpcov = 0.05;
		float percentAt = 0.9;
		srand((int)time(NULL));
		// -----------------------

		structures::CoherentMatrix<int>* testMatrix = new structures::CoherentMatrix<int>(pocetRiadkov, pocetStlpcov);

		int opCounter = 0;
		int rowCounter = 0;
		int columnCounter = 0;
		int atCounter = 0;
		int k = 0;
		auto timeCounter = SimpleTest::getElapsedTime();
		while (opCounter < 1000000) {
			k = rand() % 100;
			if (k < 100 * percentRiadkov) {
				if (rowCounter < 1000000 * percentRiadkov) {
					SimpleTest::startStopwatch();
					testMatrix->getRowCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					rowCounter++;
				}
			}
			if (k >= 100 * percentRiadkov && k < 100 * (percentRiadkov + percentStlpcov)) {
				if (columnCounter < 1000000 * percentStlpcov) {
					SimpleTest::startStopwatch();
					testMatrix->getColumnCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					columnCounter++;
				}
			}
			if (k >= 100 * (percentRiadkov + percentStlpcov) && k < 100) {
				if (atCounter < 1000000 * percentAt) {
					int x = rand() % pocetRiadkov;
					int y = rand() % pocetStlpcov;
					SimpleTest::startStopwatch();
					testMatrix->at(x, y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					atCounter++;
				}
			}
			opCounter = rowCounter + columnCounter + atCounter;
		}
		structures::Logger::getInstance().logDuration(pocetRiadkov * pocetStlpcov, timeCounter,
			": CoherentMatrixA time.");
		delete testMatrix;
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	CoherentMatrixScenarTestB::CoherentMatrixScenarTestB() :
		SimpleTest("CoherentMatrixScenarTestB")
	{
	}
	void CoherentMatrixScenarTestB::test()
	{
		// Definicia konstant pre test
		int pocetRiadkov = 2000;
		int pocetStlpcov = 500;
		float percentRiadkov = 0.05;
		float percentStlpcov = 0.05;
		float percentAt = 0.9;
		srand((int)time(NULL));
		// -----------------------

		structures::CoherentMatrix<int>* testMatrix = new structures::CoherentMatrix<int>(pocetRiadkov, pocetStlpcov);

		int opCounter = 0;
		int rowCounter = 0;
		int columnCounter = 0;
		int atCounter = 0;
		int k = 0;
		auto timeCounter = SimpleTest::getElapsedTime();
		while (opCounter < 1000000) {
			k = rand() % 100;
			if (k < 100 * percentRiadkov) {
				if (rowCounter < 1000000 * percentRiadkov) {
					SimpleTest::startStopwatch();
					testMatrix->getRowCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					rowCounter++;
				}
			}
			if (k >= 100 * percentRiadkov && k < 100 * (percentRiadkov + percentStlpcov)) {
				if (columnCounter < 1000000 * percentStlpcov) {
					SimpleTest::startStopwatch();
					testMatrix->getColumnCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					columnCounter++;
				}
			}
			if (k >= 100 * (percentRiadkov + percentStlpcov) && k < 100) {
				if (atCounter < 1000000 * percentAt) {
					int x = rand() % pocetRiadkov;
					int y = rand() % pocetStlpcov;
					SimpleTest::startStopwatch();
					testMatrix->at(x, y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					atCounter++;
				}
			}
			opCounter = rowCounter + columnCounter + atCounter;
		}
		structures::Logger::getInstance().logDuration(pocetRiadkov * pocetStlpcov, timeCounter,
			": CoherentMatrixB time.");
		delete testMatrix;
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	CoherentMatrixScenarTestC::CoherentMatrixScenarTestC() :
		SimpleTest("CoherentMatrixScenarTestC")
	{
	}
	void CoherentMatrixScenarTestC::test()
	{
		// Definicia konstant pre test
		int pocetRiadkov = 50;
		int pocetStlpcov = 10;
		float percentRiadkov = 0.1;
		float percentStlpcov = 0.3;
		float percentAt = 0.6;
		srand((int)time(NULL));
		// -----------------------

		structures::CoherentMatrix<int>* testMatrix = new structures::CoherentMatrix<int>(pocetRiadkov, pocetStlpcov);

		int opCounter = 0;
		int rowCounter = 0;
		int columnCounter = 0;
		int atCounter = 0;
		int k = 0;
		auto timeCounter = SimpleTest::getElapsedTime();
		while (opCounter < 1000000) {
			k = rand() % 100;
			if (k < 100 * percentRiadkov) {
				if (rowCounter < 1000000 * percentRiadkov) {
					SimpleTest::startStopwatch();
					testMatrix->getRowCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					rowCounter++;
				}
			}
			if (k >= 100 * percentRiadkov && k < 100 * (percentRiadkov + percentStlpcov)) {
				if (columnCounter < 1000000 * percentStlpcov) {
					SimpleTest::startStopwatch();
					testMatrix->getColumnCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					columnCounter++;
				}
			}
			if (k >= 100 * (percentRiadkov + percentStlpcov) && k < 100) {
				if (atCounter < 1000000 * percentAt) {
					int x = rand() % pocetRiadkov;
					int y = rand() % pocetStlpcov;
					SimpleTest::startStopwatch();
					testMatrix->at(x, y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					atCounter++;
				}
			}
			opCounter = rowCounter + columnCounter + atCounter;
		}
		structures::Logger::getInstance().logDuration(pocetRiadkov * pocetStlpcov, timeCounter,
			": CoherentMatrixC time.");
		delete testMatrix;
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	CoherentMatrixScenarTestD::CoherentMatrixScenarTestD() :
		SimpleTest("CoherentMatrixScenarTestD")
	{
	}
	void CoherentMatrixScenarTestD::test()
	{
		// Definicia konstant pre test
		int pocetRiadkov = 500;
		int pocetStlpcov = 2000;
		float percentRiadkov = 0.1;
		float percentStlpcov = 0.3;
		float percentAt = 0.6;
		srand((int)time(NULL));
		// -----------------------

		structures::CoherentMatrix<int>* testMatrix = new structures::CoherentMatrix<int>(pocetRiadkov, pocetStlpcov);

		int opCounter = 0;
		int rowCounter = 0;
		int columnCounter = 0;
		int atCounter = 0;
		int k = 0;
		auto timeCounter = SimpleTest::getElapsedTime();
		while (opCounter < 1000000) {
			k = rand() % 100;
			if (k < 100 * percentRiadkov) {
				if (rowCounter < 1000000 * percentRiadkov) {
					SimpleTest::startStopwatch();
					testMatrix->getRowCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					rowCounter++;
				}
			}
			if (k >= 100 * percentRiadkov && k < 100 * (percentRiadkov + percentStlpcov)) {
				if (columnCounter < 1000000 * percentStlpcov) {
					SimpleTest::startStopwatch();
					testMatrix->getColumnCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					columnCounter++;
				}
			}
			if (k >= 100 * (percentRiadkov + percentStlpcov) && k < 100) {
				if (atCounter < 1000000 * percentAt) {
					int x = rand() % pocetRiadkov;
					int y = rand() % pocetStlpcov;
					SimpleTest::startStopwatch();
					testMatrix->at(x, y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					atCounter++;
				}
			}
			opCounter = rowCounter + columnCounter + atCounter;
		}
		structures::Logger::getInstance().logDuration(pocetRiadkov * pocetStlpcov, timeCounter,
			": CoherentMatrixD time.");
		delete testMatrix;
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	IncoherentMatrixScenarTimeAt::IncoherentMatrixScenarTimeAt() :
		SimpleTest("IncoherentMatrixScenarTimeAt")
	{
	}
	void IncoherentMatrixScenarTimeAt::test()
	{
		// Definicia konstant pre test
		size_t krok = 100;
		size_t pocetOpakovani = 100;
		srand((int)time(NULL));
		// --------------------

		structures::Logger::getInstance().logInfo("IncoherentMatrixTimeAt testovanie casovej zavislosti pre konstantne m, a n s krokom 100.");

		for (size_t i = 1; i < 26; i++)
		{
			auto testMatrix = new structures::IncoherentMatrix<int>(250, i * krok);
			for (size_t x = 0; x < 250; x++)
			{
				for (size_t y = 0; y < i * krok; y++) {
					testMatrix->at(x, y) = x + y;
				}
			}

			auto timeCounter = SimpleTest::getElapsedTime();
			int x = 0;
			int y = 0;
			for (size_t j = 0; j < pocetOpakovani; j++) {
				x = rand() % 250;
				y = rand() % (i * krok);
				SimpleTest::startStopwatch();
				testMatrix->at(x, y);
				SimpleTest::stopStopwatch();
				timeCounter += SimpleTest::getElapsedTime();
			}
			timeCounter /= pocetOpakovani;
			structures::Logger::getInstance().logDuration(i * krok, timeCounter, ": priemerny cas");
			delete testMatrix;
		}
		// --------------------

		structures::Logger::getInstance().logInfo("IncoherentMatrixTimeAt testovanie casovej zavislosti pre konstantne n, a m s krokom 100.");
		
		for (size_t i = 1; i < 26; i++)
		{
			auto testMatrix = new structures::IncoherentMatrix<int>(i * krok, 250);
			for (size_t x = 0; x < i * krok; x++)
			{
				for (size_t y = 0; y < 250; y++) {
					testMatrix->at(x, y) = x + y;
				}
			}

			auto timeCounter = SimpleTest::getElapsedTime();
			int x = 0;
			int y = 0;
			for (size_t j = 0; j < pocetOpakovani; j++) {
				x = rand() % (i * krok);
				y = rand() % 250;
				SimpleTest::startStopwatch();
				testMatrix->at(x, y);
				SimpleTest::stopStopwatch();
				timeCounter += SimpleTest::getElapsedTime();
			}
			timeCounter /= pocetOpakovani;
			structures::Logger::getInstance().logDuration(i * krok, timeCounter, ": priemerny cas");
			delete testMatrix;
		}
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	IncoherentMatrixScenarTimeAssign::IncoherentMatrixScenarTimeAssign() :
		SimpleTest("IncoherentMatrixScenarTimeAssign")
	{
	}
	void IncoherentMatrixScenarTimeAssign::test()
	{
		// Definicia konstant pre test
		size_t krok = 100;
		size_t pocetOpakovani = 100;
		srand((int)time(NULL));
		// --------------------

		structures::Logger::getInstance().logInfo("IncoherentMatrixTimeAssign testovanie casovej zavislosti pre konstantne m, a n s krokom 100.");

		for (size_t i = 1; i < 11; i++)
		{
			auto testMatrix = new structures::IncoherentMatrix<int>(250, i * krok);
			for (size_t x = 0; x < 250; x++)
			{
				for (size_t y = 0; y < i * krok; y++) {
					testMatrix->at(x, y) = x + x;
				}
			}

			auto timeCounter = SimpleTest::getElapsedTime();
			for (size_t j = 0; j < pocetOpakovani; j++) {
				auto testMatrix2 = new structures::IncoherentMatrix<int>(250, i * krok);
				for (size_t x = 0; x < 250; x++)
				{
					for (size_t y = 0; y < i * krok; y++) {
						testMatrix2->at(x, y) = y + y;
					}
				}
				SimpleTest::startStopwatch();
				testMatrix->assign(*testMatrix2);
				SimpleTest::stopStopwatch();
				timeCounter += SimpleTest::getElapsedTime();
				delete testMatrix2;
			}
			timeCounter /= pocetOpakovani;
			structures::Logger::getInstance().logDuration(i * krok, timeCounter, ": priemerny cas");
			delete testMatrix;
		}
		// --------------------

		structures::Logger::getInstance().logInfo("IncoherentMatrixTimeAssign testovanie casovej zavislosti pre konstantne n, a m s krokom 100.");

		for (size_t i = 1; i < 11; i++)
		{
			auto testMatrix = new structures::IncoherentMatrix<int>(i * krok, 250);
			for (size_t x = 0; x < i * krok; x++)
			{
				for (size_t y = 0; y < 250; y++) {
					testMatrix->at(x, y) = x + x;
				}
			}

			auto timeCounter = SimpleTest::getElapsedTime();
			for (size_t j = 0; j < pocetOpakovani; j++) {
				auto testMatrix2 = new structures::IncoherentMatrix<int>(i * krok, 250);
				for (size_t x = 0; x < i * krok; x++)
				{
					for (size_t y = 0; y < 250; y++) {
						testMatrix2->at(x, y) = y + y;
					}
				}
				SimpleTest::startStopwatch();
				testMatrix->assign(*testMatrix2);
				SimpleTest::stopStopwatch();
				timeCounter += SimpleTest::getElapsedTime();
				delete testMatrix2;
			}
			timeCounter /= pocetOpakovani;
			structures::Logger::getInstance().logDuration(i * krok, timeCounter, ": priemerny cas");
			delete testMatrix;
		}
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	IncoherentMatrixScenarTestA::IncoherentMatrixScenarTestA() :
		SimpleTest("IncoherentMatrixScenarTestA")
	{
	}
	void IncoherentMatrixScenarTestA::test()
	{
		// Definicia konstant pre test
		int pocetRiadkov = 10;
		int pocetStlpcov = 50;
		float percentRiadkov = 0.05;
		float percentStlpcov = 0.05;
		float percentAt = 0.9;
		srand((int)time(NULL));
		// -----------------------

		structures::IncoherentMatrix<int>* testMatrix = new structures::IncoherentMatrix<int>(pocetRiadkov, pocetStlpcov);

		int opCounter = 0;
		int rowCounter = 0;
		int columnCounter = 0;
		int atCounter = 0;
		int k = 0;
		auto timeCounter = SimpleTest::getElapsedTime();
		while (opCounter < 1000000) {
			k = rand() % 100;
			if (k < 100 * percentRiadkov) {
				if (rowCounter < 1000000 * percentRiadkov) {
					SimpleTest::startStopwatch();
					testMatrix->getRowCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					rowCounter++;
				}
			}
			if (k >= 100 * percentRiadkov && k < 100 * (percentRiadkov + percentStlpcov)) {
				if (columnCounter < 1000000 * percentStlpcov) {
					SimpleTest::startStopwatch();
					testMatrix->getColumnCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					columnCounter++;
				}
			}
			if (k >= 100 * (percentRiadkov + percentStlpcov) && k < 100) {
				if (atCounter < 1000000 * percentAt) {
					int x = rand() % pocetRiadkov;
					int y = rand() % pocetStlpcov;
					SimpleTest::startStopwatch();
					testMatrix->at(x, y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					atCounter++;
				}
			}
			opCounter = rowCounter + columnCounter + atCounter;
		}
		structures::Logger::getInstance().logDuration(pocetRiadkov * pocetStlpcov, timeCounter,
			": IncoherentMatrixA time.");
		delete testMatrix;

	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	IncoherentMatrixScenarTestB::IncoherentMatrixScenarTestB() :
		SimpleTest("IncoherentMatrixScenarTestB")
	{
	}
	void IncoherentMatrixScenarTestB::test()
	{
		// Definicia konstant pre test
		int pocetRiadkov = 2000;
		int pocetStlpcov = 500;
		float percentRiadkov = 0.05;
		float percentStlpcov = 0.05;
		float percentAt = 0.9;
		srand((int)time(NULL));
		// -----------------------

		structures::IncoherentMatrix<int>* testMatrix = new structures::IncoherentMatrix<int>(pocetRiadkov, pocetStlpcov);

		int opCounter = 0;
		int rowCounter = 0;
		int columnCounter = 0;
		int atCounter = 0;
		int k = 0;
		auto timeCounter = SimpleTest::getElapsedTime();
		while (opCounter < 1000000) {
			k = rand() % 100;
			if (k < 100 * percentRiadkov) {
				if (rowCounter < 1000000 * percentRiadkov) {
					SimpleTest::startStopwatch();
					testMatrix->getRowCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					rowCounter++;
				}
			}
			if (k >= 100 * percentRiadkov && k < 100 * (percentRiadkov + percentStlpcov)) {
				if (columnCounter < 1000000 * percentStlpcov) {
					SimpleTest::startStopwatch();
					testMatrix->getColumnCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					columnCounter++;
				}
			}
			if (k >= 100 * (percentRiadkov + percentStlpcov) && k < 100) {
				if (atCounter < 1000000 * percentAt) {
					int x = rand() % pocetRiadkov;
					int y = rand() % pocetStlpcov;
					SimpleTest::startStopwatch();
					testMatrix->at(x, y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					atCounter++;
				}
			}
			opCounter = rowCounter + columnCounter + atCounter;
		}
		structures::Logger::getInstance().logDuration(pocetRiadkov * pocetStlpcov, timeCounter,
			": IncoherentMatrixB time.");
		delete testMatrix;
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	IncoherentMatrixScenarTestC::IncoherentMatrixScenarTestC() :
		SimpleTest("IncoherentMatrixScenarTestC")
	{
	}
	void IncoherentMatrixScenarTestC::test()
	{
		// Definicia konstant pre test
		int pocetRiadkov = 50;
		int pocetStlpcov = 10;
		float percentRiadkov = 0.1;
		float percentStlpcov = 0.3;
		float percentAt = 0.6;
		srand((int)time(NULL));
		// -----------------------

		structures::IncoherentMatrix<int>* testMatrix = new structures::IncoherentMatrix<int>(pocetRiadkov, pocetStlpcov);

		int opCounter = 0;
		int rowCounter = 0;
		int columnCounter = 0;
		int atCounter = 0;
		int k = 0;
		auto timeCounter = SimpleTest::getElapsedTime();
		while (opCounter < 1000000) {
			k = rand() % 100;
			if (k < 100 * percentRiadkov) {
				if (rowCounter < 1000000 * percentRiadkov) {
					SimpleTest::startStopwatch();
					testMatrix->getRowCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					rowCounter++;
				}
			}
			if (k >= 100 * percentRiadkov && k < 100 * (percentRiadkov + percentStlpcov)) {
				if (columnCounter < 1000000 * percentStlpcov) {
					SimpleTest::startStopwatch();
					testMatrix->getColumnCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					columnCounter++;
				}
			}
			if (k >= 100 * (percentRiadkov + percentStlpcov) && k < 100) {
				if (atCounter < 1000000 * percentAt) {
					int x = rand() % pocetRiadkov;
					int y = rand() % pocetStlpcov;
					SimpleTest::startStopwatch();
					testMatrix->at(x, y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					atCounter++;
				}
			}
			opCounter = rowCounter + columnCounter + atCounter;
		}
		structures::Logger::getInstance().logDuration(pocetRiadkov * pocetStlpcov, timeCounter,
			": IncoherentMatrixC time.");
		delete testMatrix;
	}

	//------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	IncoherentMatrixScenarTestD::IncoherentMatrixScenarTestD() :
		SimpleTest("IncoherentMatrixScenarTestD")
	{
	}
	void IncoherentMatrixScenarTestD::test()
	{
		// Definicia konstant pre test
		int pocetRiadkov = 500;
		int pocetStlpcov = 2000;
		float percentRiadkov = 0.1;
		float percentStlpcov = 0.3;
		float percentAt = 0.6;
		srand((int)time(NULL));
		// -----------------------

		structures::IncoherentMatrix<int>* testMatrix = new structures::IncoherentMatrix<int>(pocetRiadkov, pocetStlpcov);

		int opCounter = 0;
		int rowCounter = 0;
		int columnCounter = 0;
		int atCounter = 0;
		int k = 0;
		auto timeCounter = SimpleTest::getElapsedTime();
		while (opCounter < 1000000) {
			k = rand() % 100;
			if (k < 100 * percentRiadkov) {
				if (rowCounter < 1000000 * percentRiadkov) {
					SimpleTest::startStopwatch();
					testMatrix->getRowCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					rowCounter++;
				}
			}
			if (k >= 100 * percentRiadkov && k < 100 * (percentRiadkov + percentStlpcov)) {
				if (columnCounter < 1000000 * percentStlpcov) {
					SimpleTest::startStopwatch();
					testMatrix->getColumnCount();
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					columnCounter++;
				}
			}
			if (k >= 100 * (percentRiadkov + percentStlpcov) && k < 100) {
				if (atCounter < 1000000 * percentAt) {
					int x = rand() % pocetRiadkov;
					int y = rand() % pocetStlpcov;
					SimpleTest::startStopwatch();
					testMatrix->at(x, y);
					SimpleTest::stopStopwatch();
					timeCounter += SimpleTest::getElapsedTime();
					atCounter++;
				}
			}
			opCounter = rowCounter + columnCounter + atCounter;
		}
		structures::Logger::getInstance().logDuration(pocetRiadkov * pocetStlpcov, timeCounter,
			": IncoherentMatrixD time.");
		delete testMatrix;
	}
}