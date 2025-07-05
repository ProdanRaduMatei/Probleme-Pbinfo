#include <iostream>

using namespace std;

int cautare(int n, double X[], double v) {
    for (int i = 0; i < n; ++i)
        if (X[i] == v)
            return i;
    return -1;
}

int main()
{
    int n;
    double X[100], v;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> X[i];
    cin >> v;
    cout << cautare(n, X, v);
    return 0;
}
