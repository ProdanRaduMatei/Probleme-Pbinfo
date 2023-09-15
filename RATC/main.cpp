#include <iostream>

using namespace std;

int main()
{
    int n, x, y, p, xi[1001], yi[1001], urcat = 0, coborat = 0;
    cin >> n >> x >> y >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> xi[i] >> yi[i];
        urcat = urcat + xi[i];
        coborat = coborat + yi[i];
    }
    if (p == 1)
        cout << urcat << " " << coborat << " " << urcat - coborat;
    urcat = 0;
    if (p == 2) {
        for (int i = 1; i <= x; ++i)
            urcat = urcat + xi[i];
        if (urcat > y)
            cout << "DA";
        else
            cout << "NU";
    }
    return 0;
}
