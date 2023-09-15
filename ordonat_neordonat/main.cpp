#include <iostream>

using namespace std;

int main()
{
    int n, i, v[1000], c = 1, d = 1, co = 1, sc = 1, sd = 1;
    cin >> n >> v[1];
    if (n > 1) {
        cin >> v[2];
        if (v[2] < v[1]) {
            c = 0;
            sc = 0;
            co = 0;
        }
        else if (v[2] > v[1]) {
            d = 0;
            sd = 0;
            co = 0;
        }
        else if (v[2] == v[1]) {
            sc = 0;
            sd = 0;
        }
    }
    for (i = 3; i <= n; ++i) {
        cin >> v[i];
        if (v[i] > v[i-1]) {
            d = 0;
            sd = 0;
            co = 0;
        }
        else if (v[i] < v[i - 1]) {
            c = 0;
            sc = 0;
            co = 0;
        }
        else if (v[i] == v[i - 1]) {
            sc = 0;
            sd = 0;
        }
    }
    if (sc == 1)
        cout << "sir strict cresator";
    else if (sd == 1)
        cout << "sir strict descrescator";
    else if (co == 1)
        cout << "sir constant";
    else if (sc == 0 && c == 1)
        cout << "sir crescator";
    else if (sd == 0 && d == 1)
        cout << "sir descrescator";
    else if (c == 0 && d == 0 && co == 0)
        cout << "sir neordonat";
    return 0;
}
