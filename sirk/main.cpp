#include <iostream>

using namespace std;

int main()
{
    int k, g, s, x, poz;
    cin >> k;
    if (k < 3)
        cout << k;
    else {
        x = 1;
        while (x * (x + 1) < k)
            ++x;
        g = x - 1;
        s = g * (g + 1);
        poz = k - s;
        if (poz == 0)
            cout << 2;
        else {
            if (poz <= x + 1)
                cout << poz;
            else {
                poz = poz - (x + 1);
                cout << (x + 1) - poz;
            }
        }
    }
    return 0;
}
