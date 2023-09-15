#include <iostream>

using namespace std;

int main()
{
    int n, pag = 0, p = 9, i = 1;
    cin >> n;
    while (n >= p * i) {
        n = n - p * i;
        pag = pag + p;
        p = p * 10;
        ++i;
    }
    pag = pag + n / i;
    cout << pag;
    return 0;
}
