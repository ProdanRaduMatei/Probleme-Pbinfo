#include <iostream>

using namespace std;

int main() {
    int k, x, c = 0, v[200001], n = 0, minim = 1000000, maxim = 0, pm = 0, pM = 0;
    cin >> k >> x;
    while (x != 0) {
        v[++n] = x;
        if (x % 10 == k && x > maxim)
        {
            maxim = x;
            pM = n;
        }
        if (x % 10 == k && x < minim)
        {
            minim = x;
            pm = n;
        }
        cin >> x;
    }
    if (pm == 0 || pM == 0)
        cout << "NU EXISTA";
    else if (max(pm, pM) - min(pm, pM) + 1 == 0)
        cout << "NU EXISTA";
    else
        cout << max(pm, pM) - min(pm, pM) + 1;
    return 0;
}
