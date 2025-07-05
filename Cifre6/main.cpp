#include <iostream>

using namespace std;

void numar(int n, int k, int &x) {
    int v[10] = {0};
    x = 0;
    while (n) {
        ++v[n % 10];
        n = n / 10;
    }
    int i = 9;
    while (k && i >= 0) {
        while (k && v[i]) {
            x = x * 10 + i;
            --v[i];
            --k;
        }
        --i;
    }
}

int main()
{
    int n, k, x;
    cin >> n >> k;
    numar(n, k, x);
    cout << x;
    return 0;
}
