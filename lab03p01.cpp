#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const int DL_TAB = 100;

class punkt
{
private:
    int x;
    int y;

public:
    void setX(int px) { x = px; }
    void setY(int py) { y = py; }
    int getX() { return x; }
    int getY() { return y; }
    double getR() { return sqrt(x * x + y * y); }
    void wypisz(); // nagłowek metody
    void wylosuj(int a, int b);
};

void punkt::wypisz()
{
    cout << "(" << x << ";" << y << ") ";
}

void punkt::wylosuj(int a, int b)
{
    if (a > b)
    {
        x = 0;
        y = 0;
    }
    else
    {
        x = rand() % (b - a + 1) + a;
        y = rand() % (b - a + 1) + a;
    }
}

int main()
{
    srand(time(NULL));
    punkt tab[DL_TAB];
    int a, b;
    cout << "podaj a:";
    cin >> a;
    cout << "podaj b:";
    cin >> b;
    // for (int i = 0; i < DL_TAB; i++)
    // {
    //     tab[i].setX(rand() % (b - a + 1) + a);
    //     tab[i].setY(rand() % (b - a + 1) + a);
    // }
    for (int i = 0; i < DL_TAB; i++)
        tab[i].wylosuj(a, b);
    for (int i = 0; i < DL_TAB; i++)
        tab[i].wypisz();
    cout << "\n-----------------------------------\n";
    for (int i = 0; i < DL_TAB; i++)
        cout << tab[i].getR() << " ";
    double minimum = tab[0].getR(), maksimum = tab[0].getR();
    for (int i = 0; i < DL_TAB; i++)
    {
        if (tab[i].getR() < minimum)
            minimum = tab[i].getR();
        if (tab[i].getR() > maksimum)
            maksimum = tab[i].getR();
    }
    cout << "\n-----------------------------------\n";
    cout << "Minimum=" << minimum << endl
         << "Maksimum=" << maksimum;

    return 0;
}