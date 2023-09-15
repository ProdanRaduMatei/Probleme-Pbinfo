#include <iostream>

using namespace std;

int n, sol[40], p[40];

void afis() {
    for (int i = 1; i <= n; ++i)
        if (i % 2 == 0)
            cout << i << " ";
        else
            cout << sol[i] << " ";
    cout << endl;
}

void back(int k) {
    for (int i = 1; i <= n; i = i + 2)
        if (p[i] == 0) {
            sol[k] = i;
            p[i] = 1;
            if (n % 2 == 0 && k == n - 1 || n % 2 == 1 && k == n)
                afis();
            else
                back(k + 2);
            p[i] = 0;
        }
}

int main()
{
    cin >> n;
    back(1);
    return 0;
}
