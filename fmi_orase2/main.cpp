#include <fstream>

using namespace std;

ifstream cin("fmi_orase2.in");
ofstream cout("fmi_orase2.out");

short v[1001];
short m, x;

int main() {
    cin >> m;
    for (short i = 1; i <= m; i++) {
        cin >> x;
        v[x]++;
    }
    for (short i = 1; i <= m; i++) 
        v[i] += v[i - 1];
    for (short i = 1000; i >= 1; i--)
        if (m - v[i - 1] >= i){ 
            cout << i;
            break;
        }
    return 0;
}