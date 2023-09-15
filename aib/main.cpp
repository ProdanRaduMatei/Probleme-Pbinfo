#include <iostream>

using namespace std;

int n, v[100001], fr[100001] = {0};

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        fr[v[i]] = 1;
        int c = 0;
        for (int j = 1; j < v[i]; ++j)
            if (fr[j] == 1)
                ++c;
        cout << c << " ";
    }
    return 0;
}
