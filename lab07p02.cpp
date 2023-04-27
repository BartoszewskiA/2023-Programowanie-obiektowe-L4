#include <iostream>

using namespace std;

class Liczba
{
private:
    int x;
    static int ile;
    static int suma;

public:
    Liczba(int dana) : x(dana)
    {
        ile++;
        suma += x;
    }
    int getX() { return x; }
    void setX(int x)
    {
        suma -= this->x;
        this->x = x;
        suma += this->x;
    }
    static int getIle() { return ile; }
    static int getSuma() { return suma; }
    static double getSrednia() { return (double)suma / ile; }
    ~Liczba()
    {
        ile--;
        suma -= x;
    }
};

int Liczba::ile = 0;
int Liczba::suma = 0;

int main()
{
    // Liczba x1(10), x2(20), x3(31);

    Liczba *x1 = new Liczba(10);
    Liczba *x2 = new Liczba(20);
    Liczba *x3 = new Liczba(30);

    // cout << "Liczba: " << x1.getIle()
    //      << " Suma: " << x1.getSuma()
    //      << " Srednia: " << x3.getSrednia()
    //      << endl;

    cout << "Liczba: " << Liczba::getIle()
         << " Suma: " << Liczba::getSuma()
         << " Srednia: " << Liczba::getSrednia()
         << endl;

    delete x1;
    delete x2;
    cout << "Liczba: " << Liczba::getIle()
         << " Suma: " << Liczba::getSuma()
         << " Srednia: " << Liczba::getSrednia()
         << endl;

    delete x3;
    return 0;
}