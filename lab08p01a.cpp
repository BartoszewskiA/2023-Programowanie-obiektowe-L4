#include <iostream>
#include <cmath>

using namespace std;

class Kolo
{
private:
    double r;

public:
    Kolo() : r(0) {}
    Kolo(int R) : r(R) {}
    double getR() { return r; }
    double getObwod() { return 2 * 3.14 * r; }
    double getPole() { return 3.14 * r * r; }
    void setR(double r) { this->r = r; }
    void setObwod(double obw)
    {
        r = obw / (2 * 3.14);
    }
    void setPole(double pole)
    {
        r = sqrt(pole / 3.14);
    }
    friend int porownaj(const Kolo &k1, const Kolo &k2);
    friend Kolo dodajR(const Kolo &k1, const Kolo &k2);
    friend Kolo *dodajR_v2(Kolo *k1, Kolo *k2);
};

Kolo dodajPole(Kolo &k1, Kolo &k2)
{
    double sumaPol = k1.getPole() + k2.getPole();
    Kolo wynik; //obiekt o r=0
    wynik.setPole(sumaPol);
    return wynik;
}
Kolo *dodajPole_v2(Kolo *k1, Kolo *k2)
{
    double sumaPol = k1->getPole() + k2->getPole();
    Kolo *wynik = new Kolo; // obiekt o r=0
    wynik->setPole(sumaPol);
    return wynik;
}

Kolo dodajR(const Kolo &k1, const Kolo &k2)
{
    Kolo wynik(k1.r + k2.r); // statycznie
    return wynik;
}

Kolo *dodajR_v2(Kolo *k1, Kolo *k2)
{
    Kolo *wynik = new Kolo(k1->r + k2->r); // dynamicznie
    return wynik;
}

int porownaj(const Kolo &k1, const Kolo &k2)
{
    //-1 => k1>k2
    // 0 => k1=k2
    // 1 => k1<k2
    if (k1.r > k2.r)
        return -1;
    else if (k1.r == k2.r)
        return 0;
    else
        return 1;
}

int main()
{
    // Kolo k1(10), k2(30);
    // Kolo wynik = dodajR(k1, k2);
    // cout << wynik.getR();

    Kolo *k1 = new Kolo(21);
    Kolo *k2 = new Kolo(31);
    Kolo *wynik = dodajR_v2(k1, k2);
    cout << wynik->getR();
    delete k1;
    delete k2;
    delete wynik;
    return 0;
}