#include <iostream>

using namespace std;

int main()
{
    int n, a, b, c, s;
    cin >> n;
    c = n % 10;
    b = (n / 10) % 10;
    a = (n / 100);
    s = 2 * 100 * a + 2 * 100 * b + 2 * 100 * c + 2 * 10 * a + 2 * 10 * b + 2 * 10 * c + 2 * a + 2 * b + 2 * c;
    cout << s;
    return 0;
}
