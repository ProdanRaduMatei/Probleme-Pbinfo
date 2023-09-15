#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float b, B, l, x, d, h;
    cin >> b >> B >> l;
    x = (B - b) / 2;
    h = sqrt(l * l - x * x);
    d = sqrt((b + x) * (b + x) + h * h);
    cout << d << endl;
    return 0;
}
