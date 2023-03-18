#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// zmienne globalne
string tab[100];
int n = 0;

// nagłówki
void wypisz();
void wczytaj();
void wczytaj_v2();
void zapisz();

int main()
{
    wczytaj_v2();
    wypisz();
    zapisz();
    return 0;
}

void wypisz()
{
    for (int i = 0; i < n; i++)
        cout << "[" << tab[i] << "] ";
}

void wczytaj()
{
    string temp;
    do
    {
        cout << "?: ";
        getline(cin, temp);
        tab[n] = temp;
        n++;
    } while (temp.length() != 0);
}

void wczytaj_v2()
{
    string temp;
    while (true)
    {
        cout << "?: ";
        getline(cin, temp);
        if (temp.length() == 0)
            break;
        tab[n] = temp;
        n++;
    }
}

void zapisz()
{
    fstream plik;
    plik.open("wynik.txt", ios::out);
    for (int i = 0; i < n; i++)
        plik << tab[i] << endl;
    plik.close();
}