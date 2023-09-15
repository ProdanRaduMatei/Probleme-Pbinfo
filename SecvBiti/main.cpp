#include <iostream>

using namespace std;

long long SecvBiti(char s[]) {
    int v[1000001], n = 1, f[1000001] = {0};
    v[0] = 1;
    int b1 = 1, b0 = 0;
    for (char *p = s; *p; ++p) {
        if (*p == 0)
            ++b0;
        else
            ++b1;
        v[n++] = b1 - b0;
    }
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        total = total + f[v[i]];
        ++f[v[i]];
    }
    return total;
}

int main()
{

    return 0;
}
