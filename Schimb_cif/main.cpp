#include <iostream>

using namespace std;

int v[20];

int main()
{
    long long n, k, loc, i;
    cin >> n;
    while (n) {
        cin >> k;
        if (k < 100)
            cout << k << " ";
        else {
            loc = 0;
            while (k) {
                v[++loc] = k % 10;
                k = k / 10;
            }
            cout << v[loc];
            for (int i = 2; i < loc; ++i)
                cout << v[i];
            cout << v[1] << " ";
        }
        --n;
    }
    return 0;
}
