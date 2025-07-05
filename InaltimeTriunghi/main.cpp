#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int c1, c2, i;
    cin >> c1 >> c2 >> i;
    float h, a;
    a = float(c1 * c2 / 2);
    h = float(a * 2 / i);
    cout << fixed << setprecision(2) << h;
    return 0;
}
