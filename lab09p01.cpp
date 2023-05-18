#include <iostream>

using namespace std;

class Lz
{
private:
    double a;
    double b;

public:
    Lz() : a(0), b(0) {}
    Lz(double A, double B) : a(A), b(B) {}
    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    double getA() { return a; }
    double getB() { return b; }
};

Lz operator+(Lz l1, Lz l2)
{
    double a = l1.getA() + l2.getA();
    double b = l1.getB() + l2.getB();
    Lz wynik(a, b);
    return wynik;
}
Lz operator-(Lz l1, Lz l2)
{
    double a = l1.getA() - l2.getA();
    double b = l1.getB() - l2.getB();
    Lz wynik(a, b);
    return wynik;
}

Lz operator*(double sk, Lz l2)
{
    double a = sk * l2.getA();
    double b = sk * l2.getB();
    Lz wynik(a, b);
    return wynik;
}

Lz operator*(Lz l2, double sk)
{
    double a = sk * l2.getA();
    double b = sk * l2.getB();
    Lz wynik(a, b);
    return wynik;
}

ostream &operator<<(ostream &str, Lz ob)
{
    double a = ob.getA();
    double b = ob.getB();
    if (a == 0 && b == 0)
        str << 0;
    else
    {
        if (a != 0)
        {
            str << a;
            if (b > 0)
                str << "+";
        }
        if (b != 0)
            str << b << "i";
    }
    return str;
}

istream &operator>>(istream &str, Lz &ob)
{
    string s;
    double a = 0, b = 0;
    str >> s;
    int poz_i = s.find('i');
    if (poz_i < 0) // a  lub  -a
    {
        // nie ma czesci urojonej
        a = atof(s.c_str());
    }
    else
    {
        // jest czesc urojona
        s = s.substr(0, s.length() - 1); // usuwamy literę "i"
        int poz_plus = s.find('+');
        int poz_minus = s.find('-');
        int poz_2_minus = s.find('-', 1); 
        if (poz_plus <= 0 && poz_minus <= 0 && poz_2_minus < 0) // tylko czesc urojona
            b = atof(s.c_str());
        else // wystepuja obie czesci
        {

        }
    }

    ob.setA(a);
    ob.setB(b);
    return str;
}

Lz test[]{Lz(2, 3), Lz(-2, 3), Lz(2, -3), Lz(-2, -3),
          Lz(0, 3), Lz(0, -3),
          Lz(2, 0), Lz(-2, 0),
          Lz(0, 0)};

int main()
{
    // for (int i = 0; i < 9; i++)
    //     cout << test[i] << endl;

    Lz wartosc;
    cin >> wartosc;
    cout << wartosc;
    return 0;
}