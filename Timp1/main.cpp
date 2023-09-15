#include <iostream>

using namespace std;

int main()
{
    int h1, h2, m1, m2, x, y;
    cin >> h1 >> m1;
    cin >> x >> y;
    h2 = (h1 + x + (m1 + y) / 60) % 24;
    m2 = (m1 + y) % 60;
    cout << h2 << " " << m2;
    return 0;
}
