#include <iostream>

using namespace std;

void nr_cif_zero(int n, int &nr) {
    nr = 0;
    if (n == 0)
        nr = 1;
    while (n) {
        if (n % 10 == 0)
            ++nr;
        n = n / 10;
    }
}

int main()
{
    int n, nr;
    cin >> n;
    nr_cif_zero(n, nr);
    cout << nr;
    return 0;
}
