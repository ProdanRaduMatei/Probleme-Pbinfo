#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[51], c, cf;
    int i, ap, mp = 0;
    cin.getline(s, 51);
    for (c = '0'; c <= '9'; ++c) {
        ap = 0;
        for (i = 0; i < strlen(s); ++i)
            if (s[i] == c)
                ++ap;
        if (mp < ap) {
            cf = c;
            mp = ap;
        }
    }
    if (mp)
        cout << cf;
    else
        cout << "NU";
    return 0;
}
