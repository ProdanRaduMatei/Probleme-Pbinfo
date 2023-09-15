#include <bits/stdc++.h>

using namespace std;

int x[20], n;
bool gasit;

bool cont(int k) {
    for (int i = 1; i < k; ++i) {
        if (x[i] == x[k])
            return false;
        if (k - i == abs(x[k] - x[i]))
            return false;
    }
    return true;
}

void afisare(int n) {
    gasit = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            if (x[j] == i)
                cout << "* ";
            else
                cout << "- ";
        cout << endl;
    }
}

void back(int k) {
    for (int i = 1; !gasit && i <= n; ++i) {
        x[k] = i;
        if (cont(k))
            if (k == n)
                afisare(n);
            else
                back(k + 1);
    }
}

int main()
{
    cin >> n;
    back(1);
    return 0;
}
