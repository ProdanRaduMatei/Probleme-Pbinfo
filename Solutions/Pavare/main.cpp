#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b;
    d = __gcd(a, b);
    c = a / d * b / d;
    cout << c << " " << d;
    return 0;
}
