#include <iostream>

using namespace std;

int resturi(int n, int x, int y, int r) {
    int nr = 0;
    if (x > y) {
        int temp = y;
        y = x;
        x = temp;
    }
    for (int i = r; i <= n; i = i + y)
        if (i % x == r)
            ++nr;
    return nr;
}

int main()
{
    int n, x, y, r;
    cin >> n >> x >> y >> r;
    cout << resturi(n, x, y, r);
    return 0;
}
