#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int st[20], n, i, j;
char s[20], aux, v[10] = "aeiou";

void afisare (int k) {
    for (int i = 1; i <= k; ++i)
        cout << s[st[i]];
    cout << endl;
}

int valid (int k) {
    int ev = 1;
    for (int i = 1; i <= k - 1; ++i)
        if (st[k] == st[i])
            ev = 0;
    if (k == 1 || k == n)
        if (strchr(v, s[st[k]]) == 0)
            ev = 0;
    return ev;
}

void back (int k) {
    for (int i = 0; i <= n - 1; ++i)
    {
        st[k] = i;
        if (valid(k))
            if (k == n)
                afisare(k);
            else
                back(k + 1);
    }
}

int main()
{
    cin >> s;
    n = strlen(s);
    for (int i = 0; i <= n - 2; ++i)
        for (int j = i + 1; j <= n - 1; ++j)
            if (s[i] > s[j])
                swap(s[i], s[j]);
    back(1);
    return 0;
}
