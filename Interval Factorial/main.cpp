#include <iostream>

using namespace std;

void interval(int n, int &a, int &b) {
    a = 1;
    for (int i = 1; i < n; ++i)
        a = a * i;
    ++a;
    b = 1;
    for (int i = 1; i <= n + 1; ++i)
        b = b * i;
    --b;
}

int main()
{
    int n, a, b;
    cin >> n;
    interval(n, a, b);
    cout << a << " " << b;
    return 0;
}
