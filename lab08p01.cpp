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
    // double getR() { return r; }
    // double getObwod() { return 2 * 3.14 * r; }
    // double getPole() { return 3.14 * r * r; }
    void setR(double r) { this->r = r; }
    void setObwod(double obw)
    {
        r = obw / (2 * 3.14);
    }
    void setPole(double pole)
    {
        r = sqrt(pole / 3.14);
    }
};

int main()
{

    return 0;
}