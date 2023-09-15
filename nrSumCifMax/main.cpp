#include <iostream>

using namespace std;

int main()
{
    int a, b, c, sm = 0;
    cin >> a >> b >> c;
    if (a % 10 + (a / 10) % 10 > sm)
        sm = a % 10 + (a / 10);
    if (b % 10 + (b / 10) % 10 > sm)
        sm = b % 10 + (b / 10) % 10;
    if (c % 10 + (c / 10) % 10 > sm)
        sm = c % 10 + (c / 10) % 10;
    if (sm == a % 10 + (a / 10) % 10)
        cout << a << " ";
    if (sm == b % 10 + (b / 10) % 10)
        cout << b << " ";
    if (sm == c % 10 + (c / 10) % 10)
        cout << c << " ";
    return 0;
}
