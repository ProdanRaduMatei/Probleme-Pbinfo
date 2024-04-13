#include <iostream>

using namespace std;

int main()
{
    int n, s, m = 0, p, v[1001] = {0};
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            p = s / v[i];
            m = max(m, s + p * (v[j] - v[i]));
        }
    cout << m;
}