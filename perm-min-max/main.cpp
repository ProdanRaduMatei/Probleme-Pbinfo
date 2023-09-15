#include <iostream>
#include <algorithm>

using namespace std;

int n, v[11], m = 100000000, pm, s[11], M, pM;

void afis() {
    for (int i = 1; i <= n + 2; ++i)
        cout << s[i] << " ";
    cout << endl;
}

bool valid(int k) {
    for (int i = 1; i < k; ++i)
        if (s[i] == s[k])
            return 0;
    return 1;
}

void bt(int k) {
    if (k == pm || k == pM) {
        if (k == pM) {
            s[k] = M;
            if (k == n + 2)
                afis();
            else
                bt(k + 1);
        }
        else {
            s[k] = m;
            if (k == n + 2)
                afis();
            else
                bt(k + 1);
        }
    }
    else {
        for (int i = 1; i <= n; ++i) {
            s[k] = v[i];
            if (valid(k))
                if (k == n + 2)
                    afis();
                else
                    bt(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] < m) {
            pm = i;
            m = v[i];
        }
        if (v[i] > M) {
            pM = i;
            M = v[i];
        }
    }
    if (pm < pM) {
        for (int i = pm; i < n; ++i)
            v[i] = v[i + 1];
        --n;
        for (int i = pM - 1; i < n; ++i)
            v[i] = v[i + 1];
        --n;
    }
    else {
        for (int i = pm; i < n; ++i)
            v[i] = v[i + 1];
        --n;
        for (int i = pM - 1; i < n; ++i)
            v[i] = v[i + 1];
        --n;
    }
    sort(v + 1, v + n + 1);
    bt(1);
    return 0;
}
