#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, v[1001], neg[1001], poz[1001], ne = 1, nul = 0, p = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] < 0)
            neg[ne++] = v[i];
        else if (v[i] == 0)
            ++nul;
        else if (v[i] > 0)
            poz[p++] = v[i];
    }
    sort(neg + 1, neg + ne);
    sort(poz + 1, poz + p);
    for (int i = ne - 1; i >= 1; --i)
        cout << neg[i] << " ";
    for (int i = 1; i <= nul; ++i)
        cout << 0 << " ";
    for (int i = p - 1; i >= 1; --i)
        cout << poz[i] << " ";
    return 0;
}
