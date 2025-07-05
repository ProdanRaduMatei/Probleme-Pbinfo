#include <cstring>
#include <cstdio>

using namespace std;

int a, i, j, nr, p, w[105];
char s[105];

int main()
{
    gets(s + 1);
    a = strlen(s + 1);
    for (i = 1; i <= a; ++i) {
            if (s[i] == '.') {
                for (j = i + 1; j <= a; ++j)
                    if (s[j] != '0' && s[j] != '1' && s[j] != '2' && s[j] != '3' && s[j] != '4' && s[j] != '5' && s[j] != '6' && s[j] != '7' && s[j] != '8' && s[j] != '9') {
                        p = j - 1;
                        break;
                    }
                    if (p == 0)
                        p = a;
                    for (j = i - nr; j <= p; ++j)
                        w[j] = true;
            }
            if (s[i] <= '9' && s[i] >= '0')
                ++nr;
            else
                nr = 0;
            p = 0;
    }
    for (i = 1; i <= a; ++i)
        if (!w[i])
            printf("%c", s[i]);
    return 0;
}
