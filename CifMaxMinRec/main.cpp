#include <iostream>

using namespace std;

void cifmaxmin(int n, int &max, int &min) {
    int cmin = 9, cmax = 0, u = n % 10;
    if (n < 10) {
        max = n;
        min = n;
    }
    else {
        n = n / 10;
        while (n) {
            if (n % 10 > max)
                max = n % 10;
            if (n % 10 < min)
                min = n % 10;
            n = n / 10;
        }
        if (u > cmax)
            max = u;
        else
            max = cmax;
        if (u < cmin)
            min = u;
        else
            min = cmin;
    }
}

int main()
{
    int n, max, min;
    cin >> n;
    cifmaxmin(n, max, min);
    cout << max << min;
    return 0;
}
