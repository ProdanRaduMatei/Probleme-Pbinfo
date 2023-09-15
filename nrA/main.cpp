#include <bits/stdc++.h>

using namespace std;

int n, i, nr;
char s[75], *p;

int main()
{
    cin.getline(s, sizeof(s));
    p = strtok(s, " ");
    while (p) {
        if (strchr(p, 'a'))
            ++nr;
        p = strtok(NULL, " ");
    }
    cout << nr;
    return 0;
}
