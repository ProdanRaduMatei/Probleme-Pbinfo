#include <iostream>

using namespace std;

int main()
{
    int n, v[100001], mst[100001], mdr[100001], aux = 0, w = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] > aux)
            aux = v[i];
        mst[i] = aux;
    }
    aux = 0;
    for (int i = n; i >= 1; --i) {
        if (v[i] > aux)
            aux = v[i];
        mdr[i] = aux;
    }
    for (int i = 2; i < n; ++i)
        if (v[i] < min(mst[i], mdr[i])) {
            w = w + (min(mst[i], mdr[i]) - v[i]);
            v[i] = min(mst[i], mdr[i]);
        }
    cout << w;
    return 0;
}
