#include <iostream>
#include <cmath>

using namespace std;

int ascendent(int n, int x, int y)
{
    int cifraFinala = n % 10;
    int suma = 0;
    for (int i = x; i <= y; ++i)
    {
        int temp = i;
        bool valid = true;
        if (temp == 0)
            if (0 < cifraFinala)
                valid = false;
        while (temp > 0)
        {
            int cifra = temp % 10;
            if (cifra < cifraFinala)
            {
                valid = false;
                break;
            }
            temp /= 10;
        }
        if (valid)
            suma += i;
    }
    return suma;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << ascendent(n, x, y) << endl;
    return 0;
}