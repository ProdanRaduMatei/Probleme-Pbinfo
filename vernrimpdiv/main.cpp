#include <iostream>

using namespace std;

int nrdiv(int x) {
    if (x <= 1)
        return x;
    int c = 0;
    for (int d = 1; d * d <= x; ++d)
        if (x % d == 0)
            if (d * d == x)
                ++c;
            else
                c = c + 2;
    return c;
}

int main()
{
    int n;
    cin >> n;
    if (nrdiv(n) % 2 == 1)
        cout << "da";
    else
        cout << "nu";
    return 0;
}
