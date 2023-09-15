#include <iostream>

using namespace std;

int nrdiv(int num) {
    int nr = 0, j;
    for (j = 1; j * j < num; ++j)
        if (num % j == 0)
            nr = nr + 2;
    if (j * j == num)
        ++nr;
    return nr;
}

int main()
{
    int n, x = 1;
    cin >> n;
    for (int i = 2; i <= n; ++i)
        x = x + nrdiv(i);
    cout << x;
    return 0;
}
