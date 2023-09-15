#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[256], voc[] = "aeiou";
    int l = 0, st = 0, dr, m = 0, j = 0;
    cin.getline(s, 256);
    for (int i = 0; i < strlen(s); ++i) {
        if (!strchr(voc, s[i])) {
            ++j;
            if (j >= m) {
                m = j;
                st = i - j + 1;
                dr = i;
            }
        }
        else
            j = 0;
    }
    s[dr + 1] = 0;
        cout << s + st;
    return 0;
}
