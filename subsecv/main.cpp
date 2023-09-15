#include <fstream>

using namespace std;

ifstream cin("subsecv.in");
ofstream cout("subsecv.out");

int n, a[10001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin.close();
    int s;
    for (int i = 1; i <= n; i++) {
        s = a[i];
        if (s % n == 0) {
            cout << i << ' ' << i;
            cout.close();
            return 0;
        }
        for (int j = i + 1; j < n; j++) {
            s += a[j] % n;
            if (s % n == 0) {
                cout << i << ' ' << j;
                cout.close();
                return 0;
            }
        }
    }
    return 0;
}
