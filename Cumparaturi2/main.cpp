#include <iostream>

using namespace std;

int main()
{
    int s, d, r, m, M = 0;
    cin >> s >> d >> r >> m;
    if (d <= s && d > M)
        M = d;
    else if (r <= s && r > M)
        M = r;
    else if (m <= s && m > M)
        M = m;
    if (d == M)
        cout << "drona";
    else if (r == M)
        cout << "robot";
    else if (m == M)
        cout << "masina";
    else if (M == 0)
        cout << "nimic";
    return 0;
}
