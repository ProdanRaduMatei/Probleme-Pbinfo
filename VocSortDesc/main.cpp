#include <bits/stdc++.h>

using namespace std;

int nrvoc(string s) {
    int S = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            ++S;
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            ++S;
    }
    return S;
}

int main()
{
    int n = 0;
    char *p, c[256];
    string s[256];
    cin.getline(c, 256);
    p = strtok(c, " ");
    while (p != NULL) {
        s[++n] = p;
        p = strtok(NULL, " ");
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            if (nrvoc(s[i]) < nrvoc(s[j]))
                swap(s[i], s[j]);
            else if (nrvoc(s[i]) == nrvoc(s[j])) {
                if (s[i].length() < s[j].length())
                    swap(s[i],s[j]);
                else if (s[i].length() == s[j].length()) {
                    for (int k = 0; k < s[i].length(); ++k)
                        if (s[i][k] > s[j][k]) {
                            swap(s[i], s[j]);
                            break;
                        }
                        else if (s[i][k] < s[j][k])
                            break;
                }
            }
        }
    for (int i = 1; i <= n; ++i)
        cout << s[i] << endl;
    return 0;
}
