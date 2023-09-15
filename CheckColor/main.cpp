#include <iostream>

using namespace std;

int main()
{
    int m, M, a;
    cin >> m >> a >> M;
    if (a < m)
        swap(a, m);
    if (M < m)
        swap(m, M);
    if (a > M)
        swap(a, M);
    if (m < 0) {
        cout << "NU E CULOARE";
        return 0;
    }
    if (M > 255) {
        cout << "NU E CULOARE";
        return 0;
    }
    if (M - m <= 10) {
        cout << "GRI";
        return 0;
    }
    cout << "CULOARE";
    return 0;
}
