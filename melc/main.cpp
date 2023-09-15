#include <iostream>

using namespace std;

int main()
{
    float v, T;
    int t, d;
    cin >> v >> d;
    v = v * 1000 / 60;
    T = 1.0 * d / v;
    t = (int)T;
    if (T > t)
        ++t;
    cout << t;
    return 0;
}
