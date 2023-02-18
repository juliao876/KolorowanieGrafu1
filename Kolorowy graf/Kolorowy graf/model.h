#pragma once
#include <string>
#include <vector>
#include <fstream>
/// <summary>
/// Weryfikacja poprawności parametrów wejściowych aplikacji
/// </summary>
/// <param name="argc">Licznik parametrów</param>
/// <param name="argv">Tablica wartości parametrów</param>
/// <returns>Wynik weryfikacji poprawności parametrów</returns>
bool weryfikujPoprawnoscParametrow(int argc, char** argv);
/// <summary>
/// Wczytanie parametrów wywołania do zmiennych programu
/// </summary>
/// <param name="argc">Licznik parametrów</param>
/// <param name="argv">Tablica wartości parametrów</param>
/// <param name="plikWejsciowy">Nazwa pliku wejściowego z parametrami grafu</param>
/// <param name="plikWynikowy">Nazwa pliku wynikowego, do którego zostaną zapisane rezultaty działania programu</param>
void wczytajParametry(int argc, char** argv, std::string& plikWejsciowy, std::string& plikWynikowy);
/// <summary>
/// Wczytywanie danych z podanego jako parametr pliku 
/// </summary>
/// <param name="plik">Nazwa pliku</param>
/// <returns>Tablica reprezentująca graf wraz z jego połączeniami</returns>
std::vector<std::vector<int>> wczytajDaneZPliku(std::string plik);
/// <summary>
/// Zapisywanie wynikido pliku wyjściowego podanego jako parametr
/// </summary>
/// <param name="nazwa">Nazwa pliku wyjściowego</param>
/// <param name="graf">Tablica reprezentująca graf wraz z jego połączeniami</param>
/// <param name="kolory">Tablica pokolorowanych wierzchołków</param>
void zapiszWynikDoPliku(std::string nazwa, std::vector<std::vector<int>> graf, std::vector<int> kolory);
/// <summary>
/// Główna funkcja odpowiedzialna za uruchomienie procesu kolorowania grafu
/// </summary>
/// <param name="wierzcholek">Numer wierzchołka</param>
/// <param name="graf">Tablica reprezentująca graf wraz z jego połączeniami</param>
/// <param name="kolory">Tablica pokolorowanych wierzchołków</param>
void pokolorujGraf(int wierzcholek, std::vector<std::vector<int>> graf, std::vector<int>& kolory);
/// <summary>
/// Funkcja rekurencyjna odpowiedzialna za kolorowanie grafu przechodząc po wszystkich sąsiadach wierzchołka.
/// Funkcja wykonuje się do momentu aż wszystkie wierzchołki zostaną pokolorowane.
/// </summary>
/// <param name="graf">Tablica reprezentująca graf wraz z jego połączeniami</param>
/// <param name="sasiedztwo">Sąsiedztwo wybranego wierzchołka</param>
/// <param name="kolory">Tablica pokolorowanych wierzchołków</param>
void pokolorujSasiedztwo(std::vector<std::vector<int>> graf, std::vector<int> sasiedztwo, std::vector<int>& kolory);
/// <summary>
/// Funkcja sprawdzająca czy można pokolorować wskazany jako parametr wierzchołek, podanym jako parametr kolorem
/// </summary>
/// <param name="wierzcholek">Numer wierzchołka</param>
/// <param name="graf">Tablica reprezentująca graf wraz z jego połączeniami</param>
/// <param name="kolor">Numer koloru</param>
/// <param name="kolory">Tablica pokolorowanych wierzchołków</param>
/// <returns>true - jeśli można pokolorować, false - jeśli nie można</returns>
bool czyMoznaPokolorowac(int wierzcholek, std::vector<std::vector<int>> graf, int kolor, std::vector<int>& kolory);
/// <summary>
/// Funkcja sprawdzająca czy całe sąsiedztwo danego wierzchołka ma już przydzielone swoje kolory.
/// </summary>
/// <param name="sasiedztwo">Sąsiedztwo wybranego wierzchołka</param>
/// <param name="kolory">Tablica pokolorowanych wierzchołków</param>
/// <returns>true - jeśli pokolorowane, false - jeśli niepokolorowane</returns>
bool czySasiedztwoPokolorowane(std::vector<int> sasiedztwo, std::vector<int> kolory);
/// <summary>
/// Liczenie ilości wykorzystanych kolorów w grafie
/// </summary>
/// <param name="kolory">Tablica pokolorowanych wierzchołków</param>
/// <returns>Liczba wykorzystanych kolorów w grafie</returns>
int obliczWykorzystaneKolory(std::vector<int> kolory);
/// <summary>
/// Czyszczenie tablicy kolory
/// </summary>
/// <param name="kolory">Tablica pokolorowanych wierzchołków</param>
void wyczyscKolory(std::vector<int> kolory);
