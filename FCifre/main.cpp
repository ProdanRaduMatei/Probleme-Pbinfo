#include <iostream>

using namespace std;

int nr_cif(int n, int k) {
    int cnt = 0, u;
    while (n) {
        u = n % 10;
        if (k % u == 0 && u != 0)
            ++cnt;
        n = n / 10;
    }
    return cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << nr_cif(n, k);
    return 0;
}
