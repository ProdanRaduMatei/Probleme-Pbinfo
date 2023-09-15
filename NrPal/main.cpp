#include <iostream>

using namespace std;

bool pal(long long x) {
    long long c = x, y = 0;
    while (c) {
        y = y * 10 + c % 10;
        c = c / 10;
    }
    if (x == y)
        return 1;
    return 0;
}

int main()
{
    long long a, b;
    int c = 0;
    cin >> a >> b;
    if (a > b)
        swap (a, b);
    for (long long i = a; i <= b; ++i)
        if (pal(i) == 1)
            ++c;
    cout << c;
    return 0;
}
