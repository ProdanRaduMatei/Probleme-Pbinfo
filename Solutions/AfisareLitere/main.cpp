#include <bits/stdc++.h>

using namespace std;

int i, n, v[150];
char s[256];

int main()
{
    cin.getline(s, sizeof(s));
    n = strlen(s);
    for (i = 0; i < n; ++i)
        if (s[i] >= 'a' && s[i] <= 'z')
            v[s[i]] = 1;
    for (i = 0; i < n; ++i)
        if (v[s[i]] == 1) {
            cout << s[i] << " ";
            v[s[i]] = 0;
        }
    return 0;
}
