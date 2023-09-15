#include <iostream>
using namespace std;
int main() // complexitate O[n*sqrt(valmax)]
{
    int n, i, j, ogl = 0, nr, k;
    long long int S = 0;
    cin >> nr;
    for (k = 1; k <= nr; k++)
    {
        cin >> n; //citire numere
        ogl = 0; // reinitializare nr oglindit
        while (n != 0)//oglindire
        {
            ogl = ogl * 10 + n % 10;
            n /= 10;
        }
        for (i = 1; i * i <= ogl; i++) //divizori
        {
            if (ogl % i == 0)
            {
                S += i;
                j = ogl / i;
                if (j != i)
                    S += j;
            }
        }
    }
    cout << S; //afisare suma
    return 0;
}
