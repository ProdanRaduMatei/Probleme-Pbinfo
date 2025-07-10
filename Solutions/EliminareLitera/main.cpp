#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[101], *p, a[51][50], aux[101];
    int i, k = 0, l, ok;
    cin.getline(s, 101);
    ok = 0;
    p = strtok(s, " ");
    while (p) {
        l = strlen(p);
        strcpy(a[k], p);
        if (l % 2 == 1) {
            if (l > 1) {
                ok = 1;
                strcpy(aux, p + l / 2 + 1);
                strcpy(a[k] + l / 2, aux);
            }
        }
        ++k;
        p = strtok(NULL, " ");
    }
    if (ok) {
        for (i = 0; i < k; ++i)
            cout << a[i] << " ";
    }
    else
        cout << "nu exista";
    return 0;
}
