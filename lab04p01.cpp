#include <iostream>
#include <ctime>

using namespace std;

class Random
{
public:
    Random() { srand(time(NULL)); }
    int nextInt() { return rand(); }                           // <0 ; maxInt)
    int nextInt(int b) { return rand() % b; }                  // <0 ; b)
    int nextInt(int a, int b) { return rand() % (b - a) + a; } // <a ; b)
    double nextDouble() { return rand() % 10000 / 10000.0; }
    bool nextBool()
    {
        if (rand() % 2 == 1)
            return true;
        else
            return false;

        // if (rand() % 2)
        //     return true;
        // else
        //     return false;
    }
};

int main()
{
    Random random1;

    for (int i = 0; i < 20; i++)
        // cout << random1.nextInt(-50, 50) << " ";
        cout << random1.nextDouble() << " ";

    return 0;
}