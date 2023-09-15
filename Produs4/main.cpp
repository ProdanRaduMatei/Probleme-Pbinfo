#include <iostream>

using namespace std;

void produs(int a, int &k) {
    int p = 1, i = 1;
    do {
        p = p * i;
        ++i;
    } while (p <= a);
    k = i;
}

int main()
{
    int a, k;
    cin >> a;
    produs(a, k);
    cout << k;
    return 0;
}
