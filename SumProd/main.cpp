#include <iostream>

using namespace std;

int main()
{
    int a, b, c, M = 0, s;
    cin >> a >> b >> c;
    s = a + b * c;
    if (s > M)
        M = s;
    s = a * b + c;
    if (s > M)
        M = s;
    s = b + a * c;
    if (s > M)
        M = s;
    cout << M;
    return 0;
}
