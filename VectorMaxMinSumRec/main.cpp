#include <iostream>

using namespace std;

void P(int x[], int n, int &mini, int &maxi, int &sum) {
    mini = 99999999;
    maxi = 0;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] < mini)
            mini = x[i];
        if (x[i] > maxi)
            maxi = x[i];
        sum = sum + x[i];
    }
}

int main()
{
    int n, x[100], mini, maxi, sum;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    P(x, n, mini, maxi, sum);
    cout << mini << " " << maxi << " " << sum;
    return 0;
}
