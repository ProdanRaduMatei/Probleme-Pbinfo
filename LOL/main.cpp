#include <iostream>

using namespace std;

int main()
{
    int n, A = 0, B = 0, C = 0, D = 0, E = 0, a = 0, b = 0, c = 0, d = 0, e = 0, i, v[10], X, Y, P, p;
    char x, y;
    cin >> n;
    for (i = 1; i <= n; ++i)
        v[i] = 300;
    for (i = 1; i <= n; ++i) {
        cin >> x >> y;
        switch (x) {
            case 'A': X = A; P = 1; break;
            case 'B': X = B; P = 2; break;
            case 'C': X = C; P = 3;break;
            case 'D': X = D; P = 4;break;
            case 'E': X = E; P = 5;break;
            case 'a': X = a; P = 6;break;
            case 'b': X = b; P = 7;break;
            case 'c': X = c; P = 8;break;
            case 'd': X = d; P = 9;break;
            case 'e': X = e; P = 10;break;
        }
        switch (y) {
            case 'A': Y = A; p = 1;break;
            case 'B': Y = B; p = 2;break;
            case 'C': Y = C; p = 3;break;
            case 'D': Y = D; p = 4;break;
            case 'E': Y = E; p = 5;break;
            case 'a': Y = a; p = 6;break;
            case 'b': Y = b; p = 7;break;
            case 'c': Y = c; p = 8;break;
            case 'd': Y = d; p = 9;break;
            case 'e': Y = e; p = 10;break;
        }
        X = X + v[p];
        v[p] = v[p] - 50;
        v[P] = v[P] + 50;
        if (v[p])
    }
    return 0;
}
