#include <iostream>

using namespace std;

int cifreImpare(int n) {
    int m = 0, p = 1;
    bool k = 0;
    while (n) {
        if ((n % 10) % 2 == 0) {
            m = m + p * (n % 10);
            p = p * 10;
        }
        else
            k = 1;
        n = n / 10;

    }
    if (k == 1 && m != 0)
        return m;
    else
        return -1;
}

int main()
{
    int n;
    cin >> n;
    cout << cifreImpare(n);
    return 0;
}
