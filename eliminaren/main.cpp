#include <iostream>
#include <string.h>

using namespace std;

char c[21], sol[21];
int n, s;

void afis() {
    int j = 1;
    for (int i = 0; i < s; ++i)
        if (i != sol[j])
            cout << c[i];
        else
            ++j;
    cout << endl;
}

int valid(int k) {
    for (int i = 1; i < k; ++i)
        if (sol[i] >= sol[k])
            return 0;
    return 1;
}

void bt(int k) {
    for (int i = s - 1; i > 0; --i) {
        sol[k] = i;
        if (valid(k))
            if (k == n)
                afis();
            else
                bt(k + 1);
        sol[k] = 0;
    }
}

int main()
{
    cin >> c;
    cin >> n;
    s = strlen(c);
    bt(1);
    return 0;
}
