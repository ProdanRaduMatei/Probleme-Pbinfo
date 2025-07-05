#include <iostream>

using namespace std;

int FindPosFirst(int n, int v[], int x) {
    for (int i = 0; i < n; ++i)
        if (v[i] == x)
            return i;
    return -1;
}

int FindPosLast(int n, int v[], int x) {
    for (int i = n - 1; i >= 0; --i)
        if (v[i] == x)
            return i;
    return -1;
}

int FindKPos(int n, int v[], int x, int k) {
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (v[i] == x) {
            ++c;
            if (c == k)
                return i;
        }
    return -1;
}

int main() {
    int n, x, k, q = 0, p, c = 0, r;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cin >> x >> k;
    cout << FindPosFirst(n, v, x) + 1 << endl << FindPosLast(n, v, x) + 1 << endl << FindKPos(n, v, x, k) + 1;
    return 0;
}