#include <iostream>
#include <cstring>

using namespace std;

char s[257];
int va, ve, vu, vi, vo, m;

int main()
{
    cin.getline(s, 257);
    for (int i = 0; i < strlen(s); ++i) {
        if (strchr("Aa", s[i] != NULL))
            ++va;
        else if (strchr("Ee", s[i] != NULL))
            ++ve;
        else if (strchr("Ii", s[i] != NULL))
            ++vi;
        else if (strchr("Oo", s[i] != NULL))
            ++vo;
        else if (strchr("Uu", s[i] != NULL))
            ++vu;
    }
    m = va;
    if (ve > m)
        m = ve;
    if (vi > m)
        m = vi;
    if (vo > m)
        m = vo;
    if (vu > m)
        m = vu;
    if (va == m)
        cout << "A";
    if (ve == m)
        cout << "E";
    if (vi == m)
        cout << "I";
    if (vo == m)
        cout << "O";
    if (vu == m)
        cout << "U";
    return 0;
}
