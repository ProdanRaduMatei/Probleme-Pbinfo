#include <iostream>

using namespace std;

int multiplu(int n)
{
    int d = 2, m = n, s = 0;
    while (n != 1)
    {
        s = 0;
        while (n % d == 0)
        {
            n = n / d;
            ++s;
        }
        if (s % 2 == 1)
            m = m * d;
        if (d == 2)
            ++d;
        else
            d = d + 2;
    }
    return m;
}

int main() {
    int n;
    cin >> n;
    cout << multiplu(n);
    return 0;
}
