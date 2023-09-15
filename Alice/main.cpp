#include <bits/stdc++.h>
 
using namespace std;

int Contains(int n, int dgt) {
    while (n) {
        if (n % 10 == dgt)
            return 1;
        n = n / 10;
    }
    return 0;
}

int FirstDigit(int n) {
    while (n > 9)
        n = n / 10;
    return n;
}

int MaxDigit(int n) {
    int max = 0;
    while (n) {
        if (n % 10 > max)
            max = n % 10;
        n /= 10;
    }
    return max;
}

int main()
{
    int n, k, i, x, y, p, maxEven = 0, cntDoors = 0, maxDgt;
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        cin >> x;
        if (x % 2 == 0 && x > maxEven)
            maxEven = x;
        while (x > 9) {
            y = 0;
            p = 1;
            if (Contains(x, 0) && MaxDigit(x) != FirstDigit(x))
                x = -1;
            else {
                maxDgt = MaxDigit(x);
                while (x) {
                    y = y + (maxDgt - x % 10) * p;
                    x = x / 10;
                    p = p * 10;
                }
                x = y;
            }
        }
        if (x == k)
            cntDoors++;
    }
    cout << maxEven << endl << cntDoors;
    return 0;
}