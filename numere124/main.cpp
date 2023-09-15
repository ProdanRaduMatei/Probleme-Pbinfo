#include <iostream>
#include <algorithm>

using namespace std;

long long n;
int c, cn, v[10], s[10];

void afis() {
    for (int i = 1; i <= c; ++i)
        cout << s[i];
    cout << endl;
}

int valid(int k) {
    for (int i = 1; i < k; ++i)
        if (s[k] == s[i])
            return 0;
    return 1;
}

void bt(int k) {
    for (int i = 1; i <= cn; ++i) {
        s[k] = v[i];
        if (valid(k))
            if (k == c)
                afis();
            else
                bt(k + 1);
    }
}

int main()
{
    cin >> n >> c;
    while (n) {
        v[++cn] = n % 10;
        n = n / 10;
    }
    sort(v + 1, v + 1 + cn);
    bt(1);
    return 0;
}
