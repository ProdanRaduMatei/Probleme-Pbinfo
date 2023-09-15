#include <iostream>
#include <cstring>

using namespace std;

char c[12], s[12], voc[12];
int n, m;

void afis() {
    for (int i = 0; i <= n; ++i)
        cout << s[i];
    cout << "\0"<< endl;
}

bool valid(char s[], int k) {
    for (int i = 0; i < k; ++i)
        if (s[i] == s[k])
            return 0;
    return 1;
}

void bt(int k) {
    if (strchr("aeiou", c[k]) == 0) {
        s[k] = c[k];
        if (k == n)
            afis();
        else
            bt(k + 1);
    }
    else {
        for (int i = 0; i <= m; ++i) {
            s[k] = voc[i];
            if (valid(s, k)) {
                if (k == n)
                    afis();
                else
                    bt(k + 1);
            }
        }
    }
}

void sorteaza() {
    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j <= m; ++j)
            if (voc[i] > voc[j])
                swap(voc[i], voc[j]);
}

int main()
{
    cin >> c;
    n = strlen(c);
    --n;
    for (int i = 0; i <= n; ++i)
        if (strchr("aeiou", c[i]))
            voc[m++] = c[i];
    if (m > 0)
        --m;
    sorteaza();
    bt(0);
    return 0;
}
