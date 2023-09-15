#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int nrord, h;
    char c;
}elev;

elev elevi[101];

bool cmp(elev a, elev b) {
    if (a.c == b.c) {
        if (a.h == b.h)
            return a.nrord < b.nrord;
        else
            return a.h > b.h;
    }
    else
        return a.c == 'B';
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> elevi[i].c >> elevi[i].h;
        elevi[i].nrord = i;
    }
    sort(&elevi[1], &elevi[n + 1], cmp);
    for (int i = 1; i <= n; ++i)
        cout << elevi[i].nrord << " ";
    return 0;
}
