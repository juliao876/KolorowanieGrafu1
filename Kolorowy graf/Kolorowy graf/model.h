#pragma once
#include <string>
#include <vector>
#include <fstream>
/// <summary>
/// Weryfikacja poprawności parametrów wejściowych aplikacji
/// </summary>
/// <param name="argc">licznik parametrów</param>
/// <param name="argv">tablica wartości parametrów</param>
/// <returns>wynik weryfikacji poprawności parametrów</returns>
bool weryfikujPoprawnoscParametrow(int argc, char** argv);
/// <summary>
/// 
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <param name="plikWejsciowy"></param>
/// <param name="plikWynikowy"></param>
void wczytajParametry(int argc, char** argv, std::string& plikWejsciowy, std::string& plikWynikowy);
/// <summary>
/// 
/// </summary>
/// <param name="plik"></param>
/// <returns></returns>
std::vector<std::vector<int>> wczytajDaneZPliku(std::string plik);
/// <summary>
/// 
/// </summary>
/// <param name="nazwa"></param>
/// <param name="graf"></param>
/// <param name="kolory"></param>
void zapiszWynikDoPliku(std::string nazwa, std::vector<std::vector<int>> graf, std::vector<int> kolory);
/// <summary>
/// 
/// </summary>
/// <param name="wierzcholek"></param>
/// <param name="graf"></param>
/// <param name="kolory"></param>
void pokolorujGraf(int wierzcholek, std::vector<std::vector<int>> graf, std::vector<int>& kolory);
/// <summary>
/// 
/// </summary>
/// <param name="graf"></param>
/// <param name="sasiedztwo"></param>
/// <param name="kolory"></param>
void pokolorujSasiedztwo(std::vector<std::vector<int>> graf, std::vector<int> sasiedztwo, std::vector<int>& kolory);
/// <summary>
/// 
/// </summary>
/// <param name="wierzcholek"></param>
/// <param name="graf"></param>
/// <param name="kolor"></param>
/// <param name="kolory"></param>
/// <returns></returns>
bool czyMoznaPokolorowac(int wierzcholek, std::vector<std::vector<int>> graf, int kolor, std::vector<int>& kolory);
/// <summary>
/// 
/// </summary>
/// <param name="sasiedztwo"></param>
/// <param name="kolory"></param>
/// <returns></returns>
bool czySasiedztwoPokolorowane(std::vector<int> sasiedztwo, std::vector<int> kolory);
/// <summary>
/// 
/// </summary>
/// <param name="kolory"></param>
/// <returns></returns>
int obliczWykorzystaneKolory(std::vector<int> kolory);
/// <summary>
/// 
/// </summary>
/// <param name="kolory"></param>
void wyczyscKolory(std::vector<int> kolory);
