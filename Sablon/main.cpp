#include <bits/stdc++.h>

using namespace std;

int i;
char s1[201], s2[201], voc[] = "aeiou";

int main()
{
    cin >> s1 >> s2;
    for (i = 0; i < strlen(s1); ++i)
        if (strchr(voc, s1[i]) && strchr(voc, s2[i]))
            cout << '*';
        else if (!strchr(voc, s1[i]) && !strchr(voc, s2[i]))
            cout << '#';
        else
            cout << '?';
    return 0;
}
