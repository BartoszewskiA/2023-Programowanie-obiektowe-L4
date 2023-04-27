#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class RGB
{
protected:
    int R;
    int G;
    int B;

public:
    RGB() : R(255), G(255), B(255) {}
    RGB(int r, int g, int b) : R(r), G(g), B(b) {}
    void setR(int R) { this->R = R; }
    void setG(int G) { this->G = G; }
    void setB(int B) { this->B = B; }
    int getR() { return R; }
    int getG() { return G; }
    int getB() { return B; }
    string toString()
    {
        stringstream s;
        s << "R=" << R << " G=" << G << " B=" << B;
        return s.str();
    }
};

//---------------------------------------------------------------

class aRGB : public RGB
{
protected:
    int A;

public:
    aRGB():RGB(), A(255) {}
    aRGB(int a, int r, int g, int b) : RGB(r, g, b), A(a) {}
    void setA(int A) { this->A = A; }
    int getA() { return A; }
    string toString()
    {
        stringstream s;
        // s << "A=" << A << " R=" << R << " G=" << G << " B=" << B;
        s << "A=" << A << " " << RGB::toString();
        return s.str();
    }
};

RGB kolory_podstawowe[] = { RGB(255,0,0), RGB(0,255,0), RGB(0,0,255)};

int main()
{
    // RGB kolor01;
    // RGB kolor02(20, 40, 70);

    // cout << kolor01.toString() << endl;
    // cout << kolor02.toString() << endl;

    aRGB kolor03;
    cout << kolor03.toString() << endl;
    return 0;
}