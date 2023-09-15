#include <iostream>

using namespace std;

void nr_div_imp(int n, int &c) {
    c = 0;
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            if (d % 2 == 1)
                ++c;
            if ((n / d) % 2 != 0)
                ++c;
        }
        if (d * d == n)
            if (d % 2 == 1)
                ++c;
    }
}

int main()
{
    int n, c;
    cin >> n;
    nr_div_imp(n, c);
    cout << c;
    return 0;
}
