#include <iostream>
#include <algorithm>

using namespace std;

int c1, c2, v[100], s[100];

void afis() {
    for (int i = 1; i <= c1 + c2; ++i)
        cout << s[i];
    cout << endl;
}

int valid(int k) {
    int cn1, cn2;
    for (int i = 1; i <= k; ++i)
        if (s[i] == c1)
            ++cn1;
        else
            ++cn2;
    if (cn1 > c1 || cn2 > c2)
        return 0;
    return 1;
}

void bt(int k) {
    for (int i = 1; i <= c1 + c2; ++i) {
        s[k] = v[i];
        if (valid(k))
            if (k == c1 + c2)
                afis();
            else
                bt(k + 1);
    }
}

int main()
{
    cin >> c1 >> c2;
    for (int i = 1; i <= c1; ++i)
        v[i] = c2;
    for (int i = c1 + 1; i <= c1 + c2; ++i)
        v[i] = c1;
    sort(v + 1, v + c1 + c2 + 1);
    bt(1);
    return 0;
}
