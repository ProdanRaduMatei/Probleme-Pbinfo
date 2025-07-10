#include <iostream>

using namespace std;

int main()
{
    long long n;
    int c[10] = {0};
    cin >> n;
    while (n) {
        ++c[n % 10];
        n = n / 10;
    }
    for (int i = 0; i <= 9; ++i)
        if (c[i] != 0)
            cout << i << " ";
    return 0;
}
