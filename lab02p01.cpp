#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct osoba
{
    int id;
    string imie;
    string nazwisko;
};

osoba *baza[1000];
int n = 0;

void dodaj(string im, string nazw);
void wypisz();
void zapisz_do_pliku();
void usun();

int main()
{
    string im, nazw;
    for (int i = 0; i < 4; i++)
    {
        cout << "Podaj imie: ";
        getline(cin, im);
        cout << "Podaj nazwisko: ";
        getline(cin, nazw);
        dodaj(im, nazw);
    }
    wypisz();
    zapisz_do_pliku();
    usun();
    return 0;
}

void dodaj(string im, string nazw)
{
    baza[n] = new osoba;
    baza[n]->imie = im;
    baza[n]->nazwisko = nazw;
    baza[n]->id = n + 1;
    n++;
}

void wypisz()
{
    for (int i = 0; i < n; i++)
        cout << "ID: " << baza[i]->id << endl
             << "Imie: " << baza[i]->imie << endl
             << "Nazwisko: " << baza[i]->nazwisko << endl;
    cout << "-----------------------------------------" << endl;
}


void zapisz_do_pliku()
{
    fstream plik;
    plik.open("wydruk.txt",ios::out);

    for (int i = 0; i < n; i++)
        plik << "ID: " << baza[i]->id << endl
             << "Imie: " << baza[i]->imie << endl
             << "Nazwisko: " << baza[i]->nazwisko << endl;

    plik.close();

}

void usun()
{
    for (int i = 0; i < n; i++)
        delete baza[i];
}