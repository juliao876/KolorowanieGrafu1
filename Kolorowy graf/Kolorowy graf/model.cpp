#include "model.h"
#include <iostream>
#include <sstream>
#include <set>



bool weryfikujPoprawnoscParametrow(int argc, char** argv)
{
	if (argc != 5) {
		return false;
	}
	if (std::strcmp(argv[1], "-g") == 0 && std::strcmp(argv[3], "-k") == 0) {
		return true;
	}
	return std::strcmp(argv[1], "-k") == 0 && std::strcmp(argv[3], "-g") == 0;
}

void wczytajParametry(int argc, char** argv, std::string& plikWejsciowy, std::string& plikWynikowy)
{
	if (std::strcmp(argv[1], "-g") == 0) {
		plikWejsciowy = argv[2];
		plikWynikowy = argv[4];
	}
	else {
		plikWejsciowy = argv[4];
		plikWynikowy = argv[2];
	}
}

std::vector<std::vector<int>> wczytajDaneZPliku(std::string nazwa) {

	std::vector<std::vector<int>> graf;
	std::ifstream plik("input.txt");
	if (plik.is_open()) {
		int rozmiarTablicy = 100;
		graf.resize(rozmiarTablicy);

		char nawias, przecinek;
		int wierzchołekA, wierzchołekB;
		while (plik >> nawias >> wierzchołekA >> przecinek >> wierzchołekB >> nawias) {
			if (wierzchołekA >= rozmiarTablicy || wierzchołekB >= rozmiarTablicy) {
				if (wierzchołekA > wierzchołekB) {
					rozmiarTablicy += wierzchołekA + 1;
				}
				else {
					rozmiarTablicy += wierzchołekB + 1;
				}
				graf.resize(rozmiarTablicy);
			}
			graf[wierzchołekA].push_back(wierzchołekB);
			graf[wierzchołekB].push_back(wierzchołekA);
			plik >> przecinek;
		}
		plik.close();
	}
	return graf;

}

void pokolorujGraf(int wierzcholek, std::vector<std::vector<int>> graf, std::vector<int>& kolory) {
	for (int kolor = 1; kolor <= kolory.size(); kolor++) {
		if (czyMoznaPokolorowac(wierzcholek, graf, kolor, kolory)) {
			kolory[wierzcholek] = kolor;
		}
	}

	int wierzcholekStartowy = 0;
	int minimalnaLiczbaKolorow = graf.size();
	for (int i = 0; i < graf.size(); i++) {
		if (graf[i].empty()) {
			continue;
		}
		pokolorujSasiedztwo(graf, graf[i], kolory);
		int liczbaWykorzystanychKolorow = obliczWykorzystaneKolory(kolory);
		if (liczbaWykorzystanychKolorow < minimalnaLiczbaKolorow) {
			minimalnaLiczbaKolorow = liczbaWykorzystanychKolorow;
			wierzcholekStartowy = i;
		}
		wyczyscKolory(kolory);
	}
	pokolorujSasiedztwo(graf, graf[wierzcholekStartowy], kolory);
}

void pokolorujSasiedztwo(std::vector<std::vector<int>> graf, std::vector<int> sasiedztwo, std::vector<int>& kolory) {
	if (czySasiedztwoPokolorowane(sasiedztwo, kolory)) {
		return;
	}
	for (int sasiad : sasiedztwo) {
		if (kolory[sasiad] != 0) {
			continue;
		}
		for (int kolor = 1; kolor < kolory.size(); kolor++) {
			if (czyMoznaPokolorowac(sasiad, graf, kolor, kolory)) {
				kolory[sasiad] = kolor;
				break;
			}
		}
		pokolorujSasiedztwo(graf, graf[sasiad], kolory);
	}
}

bool czyMoznaPokolorowac(int wierzcholek, std::vector<std::vector<int>> graf, int kolor, std::vector<int>& kolory) {
	// Sprawdzanie, czy dany kolor jest już użyty przez jakiegoś sąsiada
	for (int i = 0; i < graf[wierzcholek].size(); i++) {
		if (kolory[graf[wierzcholek][i]] == kolor) {
			return false;
		}
	}
	return true;
}


bool czySasiedztwoPokolorowane(std::vector<int> sasiedztwo, std::vector<int> kolory) {
	int licznikPokolorowanych = 0;
	for (int sasiad : sasiedztwo) {
		if (kolory[sasiad] != 0) {
			licznikPokolorowanych++;
		}
	}
	return licznikPokolorowanych == sasiedztwo.size();
}

int obliczWykorzystaneKolory(std::vector<int> kolory) {
	std::set<int> unikalneKolory;
	for (int i = 0; i < kolory.size(); i++) {
		unikalneKolory.insert(kolory[i]);
	}
	return unikalneKolory.size();
}

void wyczyscKolory(std::vector<int> kolory) {
	for (int i = 0; i < kolory.size(); i++) {
		kolory[i] = 0;
	}
}


void zapiszWynikDoPliku(std::string nazwa, std::vector<std::vector<int>> graf, std::vector<int> kolory) {
	std::ofstream plik(nazwa);
	if (plik.is_open()) {
		for (int i = 0; i < graf.size(); i++) {
			if (graf[i].empty()) {
				continue;
			}
			plik << "wierzcholek " << i << " jest koloru " << kolory[i] << std::endl;
		}
		plik.close();
	}
}