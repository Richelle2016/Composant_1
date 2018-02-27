#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod0)
		{
			Assert::AreEqual(1, 1);
		}
		TEST_METHOD(TestMethod1)
		{

			String fichier = "empty_blockchain.txt";

			List Result = Fonction_Lecture_fichier(fichier);

			Assert::AreEqual(Result.size(), 0);
		}
		TEST_METHOD(TestMethod2)
		{

			String fichier = "blockchain.txt";

			Fonction_ajout_bloc(bloc1);

			Fonction_ajout_bloc(bloc2);

			List Result = Fonction_Lecture_fichier(fichier);

			Assert::AreEqual(Result.size(), 2);
		}
		TEST_METHOD(TestMethod3)
		{

			String fichier = "blockchain.txt";

			String Result1 = Fonction_recherche_bloc(hashFirstBloc);

			Assert::AreEqual(Result1,bloc1);

			String Result2 = Fonction_recherche_bloc(2);

			Assert::AreEqual(Result2,bloc2);
		}

		TEST_METHOD(TestMethod4)
		{

			String fichier1 = "correct_blockchain.txt";

			String fichier2 = "corrupted_blockchain.txt";

			Boolean Result1 = Fonction_validation_blockchain(fichier);

			Assert::AreEqual(Result1,True);

			Boolean Result2 = Fonction_validation_blockchain(fichier);

			Assert::AreEqual(Result2,False);
		}

		TEST_METHOD(TestMethod5)
		{

			String fichier = "blockchain.txt";

			String Result = Fonction_lecture_fichier(fichier);

			String blocs = bloc1 + bloc 2;

			Assert::AreEqual(Result,blocs);

		}
		TEST_METHOD(TestMethod6)
		{

			String fichier = "blockchain.txt";

			String Result = Fonction_lecture_bloc(fichier,bloc1);

			Assert::AreEqual((Result.toString()).type(),String);

		}

	};
}

