#include <fstream>

using namespace std;

ifstream cin("paint.in");
ofstream cout("paint.out");

int n, days, k, ans;
int mars[250005];

int main() {
    int x = 0, y = 0;
    cin >> n >> k >> days;
    for (int i = 1; i <= days; i++) {
        cin >> x >> y;
        mars[x]++;
        mars[x + y]--;
    }
    if (mars[0] < k)
    	ans++;
    for (int i = 1; i < n; i++) {
        mars[i] += mars[i - 1];
        if (mars[i] < k)
            ans++;
    }
    cout << ans;
}