#include <iostream>
#include "model.h"

int main(int argc, char** argv)
{
	if (!weryfikujPoprawnoscParametrow(argc, argv)) {
		std::cout << "Brak parametrow wywolania programu";
		return 0;
	}
	std::string  plikWejsciowy, plikWynikowy;
	wczytajParametry(argc, argv, plikWejsciowy, plikWynikowy);
	std::vector<std::vector<int>> graf = wczytajDaneZPliku(plikWejsciowy);
	std::vector<int> kolory(graf.size() + 1);

	pokolorujGraf(0, graf, kolory);

	zapiszWynikDoPliku(plikWynikowy, graf, kolory);

	return 0;
}