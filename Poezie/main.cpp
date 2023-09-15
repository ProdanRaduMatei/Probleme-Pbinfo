#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[256], t[256];
    int n, i, j, nr;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin.getline(s, 256);
        for (j = strlen(s) - 2; j >= 0; --j) {
            if (!isalpha(s[j]) && s[j] != 32) {
                strcpy(t, s + j + 1);
                strcpy(s + j, t);
            }
            ++nr;
        }
        if (nr)
            cout << s << endl;
    }
    return 0;
}
