#include <fstream>

using namespace std;

int main()
{
    ifstream cin("cufere.in");
    ofstream cout("cufere.out");
    int cerinta, n, etichete[100]{}, numar;
    cin >> cerinta >> n;
    if (cerinta == 1)
    {
        for (int index = 0; index < 27 * n; ++index)
        {
            cin >> numar;
            if (numar != 0)
                etichete[numar % 100] += numar / 100;
        }
        for (int index = 10; index <= 99; ++index)
            if (etichete[index])
                cout << index << ' ' << etichete[index] << endl;
        return 0;
    }
    bool eratostene[100]{};
    for (int index1 = 2; index1 * index1 <= 99; ++index1)
        for (int index2 = index1 * index1; index2 <= 99; index2 += index1)
            eratostene[index2] = 1;
    for (int index = 0; index < 27 * n; ++index)
    {
        cin >> numar;
        if (numar != 0)
            etichete[numar % 100] += numar / 100;
    }
    int numareticheta = 10, afisare = 0, afisareLaNoua = 0;
    while (numareticheta <= 99)
    {
        if (etichete[numareticheta])
        {
            if (eratostene[numareticheta])
            {
                while (etichete[numareticheta] >= 64)
                {
                    cout << "64" << numareticheta << ' ';
                    etichete[numareticheta] -= 64;
                    ++afisare;
                    ++afisareLaNoua;
                    if (afisareLaNoua == 9)
                    {
                        cout << endl;
                        afisareLaNoua = 0;
                    }
                }
                if (etichete[numareticheta])
                {
                    cout << etichete[numareticheta] << numareticheta << ' ';
                    ++afisare;
                    ++afisareLaNoua;
                    if (afisareLaNoua == 9)
                    {
                        cout << endl;
                        afisareLaNoua = 0;
                    }
                }
            }
            else
            {
                while (etichete[numareticheta] >= 16)
                {
                    cout << "16" << numareticheta << ' ';
                    etichete[numareticheta] -= 16;
                    ++afisare;
                    ++afisareLaNoua;
                    if (afisareLaNoua == 9)
                    {
                        cout << endl;
                        afisareLaNoua = 0;
                    }
                }
                if (etichete[numareticheta])
                {
                    cout << etichete[numareticheta] << numareticheta << ' ';
                    ++afisare;
                    ++afisareLaNoua;
                    if (afisareLaNoua == 9)
                    {
                        cout << endl;
                        afisareLaNoua = 0;
                    }
                }
            }
        }
        ++numareticheta;
    }
    while (afisare < 27 * n)
    {
        if (afisareLaNoua == 9)
        {
            cout << endl;
            afisareLaNoua = 0;
        }
        cout << '0' << ' ';
        ++afisare;
        ++afisareLaNoua;
    }
    return 0;
}