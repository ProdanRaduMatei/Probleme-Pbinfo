#include <iostream>

using namespace std;

int n, v[11] = {0}, i;

void afisare(int n) {
    for (int j = n - 1; j >= 0; --j)
        cout << v[j];
    cout << endl;
}

int main()
{
    cin >> n;
    while (v[n] == 0) {
        afisare(n);
        if (v[0] == 0)
            v[0] = 1;
        else {
            i = 0;
            while (v[i] == 1) {
                v[i] = 0;
                ++i;
            }
            v[i] = 1;
        }
    }
    return 0;
}
