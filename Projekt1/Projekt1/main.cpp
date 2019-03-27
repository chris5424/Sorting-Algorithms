#include <iostream>
#include <cstdlib>
#include <chrono>

#include "bubble.hpp"
#include "insert.hpp"
#include "merge.hpp"
#include "quicksort.hpp"
#include "inv_quicksort.hpp"
#include "tester.hpp"


int main()
{
	//std::cout << "Podaj wielkosc tablicy do posortowania: ";

	int wielkosc=100;
	//std::cin >> wielkosc;



	int** tablica = new int *[100];
	for (int row = 0; row < 99; row++)  //utworzenie 100 tablic
	{
		tablica[row] = new int[wielkosc];
	}


	for (int row = 0; row < 99; row++)
	{
		for (int i = 0; i < wielkosc; i++)
		{
			tablica[row][i] = std::rand();  //wypełnienie tablic liczbami losowymi
		}
	}


	//for (int row = 0; row < 99; row++)
	//{
	//	for (int i = 0; i < wielkosc; i++)
	//	{
	//		std::cout << tablica[row][i] << " ";  //wyświetlenie tablic nieposortowanych
	//	}
	//	std::cout << "\n";
	//}
	//std::cout << "\n";

	for (int i = 0; i < 99; i++)
	{
		//quicksort(tablica[i], 0, wielkosc - 1, 0.25);  //wstępne sortowanie
		//inv_quicksort(tablica[i], 0, wielkosc - 1);    //sortowanie odwrotne
	}

	auto start = std::chrono::system_clock::now(); //start czasu
	for (int i = 0; i < 99; i++)
	{
		int *tab_pom = new int[wielkosc];
		//bubble(tablica[i], wielkosc);
		//insert(tablica[i], k);
		//quicksort(tablica[i], 0, wielkosc - 1, 1);  //czwarty parametr to stopień posortowania w % (0-1)
		merge_sort(tablica[i], tab_pom, 0, wielkosc-1);
	}
	auto end = std::chrono::system_clock::now(); //koniec czasu

	std::chrono::duration<double> elapsed_seconds = end - start;  //obliczenie zmiany czasu

	if (czy_posortowane(tablica, wielkosc)==1)
	{
		std::cout << "Posortowane\nCzas sortowania: " << elapsed_seconds.count() << "s\n";
		std::cout << "\n";
	}
	else
	{
		std::cout << "Blad sortowania\n";
	}


	//for (int row = 0; row < 99; row++)
	//{
	//	for (int i = 0; i < wielkosc; i++)
	//	{
	//		std::cout << tablica[row][i] << " ";  //wyświetlenie tablic posortowanych
	//	}
	//	std::cout << "\n";
	//}
	//std::cout << "\n";
	


	for (int i = 0; i < 99; i++)  
	{
		delete[] tablica[i];   //zwolnienie pamięci
	}
	delete[] tablica;


	system("pause");
	return 1;
}