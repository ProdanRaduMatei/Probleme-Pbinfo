#include <iostream>

using namespace std;

int n, c, v[200];
double s;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        s = s + v[i];
    }
    s = (double) s / n;
    for (int i = 1; i <= n; ++i)
        if (v[i] > s)
            ++c;
    cout << c;
    return 0;
}
