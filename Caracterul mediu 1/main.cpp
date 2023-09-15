#include <iostream>
#include <cstring>

using namespace std;

char s[201], v[] = "AEIOUaeiou", ch;
int S, c, n;

bool bun(char x) {
    if (!strchr(v, x) && x != ' ' && !(x >= 'A' && x <= 'Z'))
        return 1;
    else
        return 0;
}

int main()
{
    cin.getline(s, 201);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (bun(s[i]) == 1) {
            ++c;
            S = S + (int)s[i];
        }
    }
    ch = (char)(S / c);
    cout << ch;
    return 0;
}
