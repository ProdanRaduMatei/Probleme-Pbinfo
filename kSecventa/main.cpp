#include <iostream>

using namespace std;

int n, k;
int a[101];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int start1, start2;
    bool ebun;
    for (int i = 1; i < k; ++i) {
        start1 = (i - 1) * (n / k) + 1;
        for (int j = i + 1; j <= k; ++j) {
            start2 = (j - 1) * (n / k) + 1;
            ebun = 1;
            for (int p = 0; p < n / k; ++p) {
                if (a[start1 + p] != a[start2 + p]) {
                    ebun = 0;
                    break;
                }
            }
            if (ebun == 1) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "NU";
    return 0;
}
