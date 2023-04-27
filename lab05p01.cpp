#include <iostream>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

class CzasPracy
{
private:
    void zapiszCzas()
    {
        fstream plik;
        plik.open("log.txt", ios::app);
        int czas = time(NULL);
        plik << czas;
        plik << endl;
        plik.close();
    }

public:
    CzasPracy()
    {
        zapiszCzas();
    }
    ~CzasPracy()
    {
        zapiszCzas();
    }

    int zliczCzasPracy()
    {
        fstream plik;
        int czas_pracy = 0;
        plik.open("log.txt", ios::in);
        if (!plik.good())
            return 0;
        string wpis_1, wpis_2;
        int czas;
        while (!plik.eof())
        {
            getline(plik, wpis_1);
            getline(plik, wpis_2);
            if (wpis_2.length() > 0 && wpis_1.length() > 0)
            {
                czas = atoi(wpis_2.c_str()) - atoi(wpis_1.c_str());
                czas_pracy += czas;
                // cout << wpis_1 << "  " << wpis_2 << "  " << czas << endl;
            }
        }
        plik.close();
        return czas_pracy;
    }
    string podsumowanie()
    {
        
    }

};

int main()
{
    CzasPracy start;
    cout << "czas pracy: " << start.zliczCzasPracy() << endl;
    cout << "nacisnij dowolny klawisz";
    getch();
    return 0;
}