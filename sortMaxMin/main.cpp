    #include <iostream>
    #include <algorithm>

    using namespace std;

    int n, M = 0, m = 1000000, p, P, v[1001];
    int main()
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
            if (v[i] > M) {
                P = i;
                M = v[i];
            }
            if (v[i] < m) {
                p = i;
                m = v[i];
            }
        }
        if (p > P)
            swap (p, P);
        sort(v + p, v + 1 + P);
        for (int i = 1; i <= n; ++i)
            cout << v[i] << " ";
        return 0;
    }
