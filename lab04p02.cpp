#include <iostream>
#include <ctime>

using namespace std;

class KotShcrodingera
{
private:
    int stan; // {-1,0,1}
public:
    KotShcrodingera() { stan = 0; }
    string otworzPudelko()
    {
        if (stan == 0)
        {
            if (rand() % 2 == 0)
                stan = -1;
            else
                stan = 1;
        }

        if (stan == 1)
            return "zywy";
        else
            return "martwy";
    }
};

int main()
{
    srand(time(NULL));
    KotShcrodingera tab[10];
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 10; i++)
            cout << "kot " << i << ":" << tab[i].otworzPudelko() << " ";
        cout << endl;
    }
    return 0;
}