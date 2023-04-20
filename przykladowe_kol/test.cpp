#include "test.h"
#include <stdexcept>
#include <iostream>
using namespace std;

int element_tablicy(int* tab, int szukana, const int size, bool& jest) {
	int i;

	for (i = 0; i < size; i++) {
		if (tab[i] == szukana) {
			jest = true;
			return i;
		}
	}
		throw std::length_error("");
}

int element_tablicy(int* tab, int szukana, const int size) {
	int i;
	for (i = size - 1; i >= 0; i--) {
		if (tab[i] == szukana) {
			return i;
		}
	}
		throw std::length_error("");
}

void test_brak() {
	const int size = 6;
	int tab[size] = { 2,4,8,16,32,64 };
	int szukana = 0;
	bool jest = false;
	try
	{
		cerr << "Test 1:\t";
		element_tablicy(tab, szukana, size, jest);
		cerr << "False\n";
	}
	catch (std::length_error) {
		cerr << "OK\n";
	}
	catch (...) {
		cerr << "False\tJakis inny blad.\n";
	}
}

void test_raz() {
	const int size = 6;
	int tab[size] = { 2,4,8,16,32,64 };
	int szukana = 16;
	bool jest = false;
	try
	{
		cerr << "Test 2:\t";
		element_tablicy(tab, szukana, size, jest);
		cerr << "OK\n";
	}
	catch (std::length_error) {
		cerr << "False\tBrak szukanego elementu\n";
	}
	catch (...) {
		cerr << "False\tJakis inny blad.\n";
	}
}

void test_kilka() {
	const int size = 6;
	int tab[size] = { 2,4,8,16,2,64 };
	int szukana = 2;
	bool jest = false;
	try
	{
		cerr << "Test 3:\t";
		element_tablicy(tab, szukana, size, jest);
		cerr << "OK\n";
	}
	catch (std::length_error) {
		cerr << "False\tBrak szukanego elementu\n";
	}
	catch (...) {
		cerr << "False\tJakis inny blad.\n";
	}
}