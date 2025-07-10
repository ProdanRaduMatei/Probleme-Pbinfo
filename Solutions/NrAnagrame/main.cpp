#include <cstdio>
#include <cstring>

using namespace std;

int n, i, w[260][27], l, nr, j;
char s[260], *p, t[260][260];

int main()
{
    gets(s);
    p = strtok(s, " ");
    strcpy(t[1], p);
    while (j < strlen(t[1])) {
        ++w[1][t[1][j] - 'a'];
        ++j;
    }
    l = 1;
    while (p != NULL) {
        p = strtok(NULL, " ");
        if (p == NULL)
            break;
        ++l;
        j = 0;
        strcpy(t[l], p);
        while (j < strlen(t[l])) {
            ++w[l][t[l][j] - 'a'];
            ++j;
        }
    }
    for (i = 1; i < l; ++i)
        if (!memcmp(w[i], w[l], sizeof(w[l])) && strcmp(t[i], t[l]))
            ++nr;
    printf("%d", nr);
    return 0;
}
