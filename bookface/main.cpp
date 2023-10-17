#include <fstream>

using namespace std;

int main() {
    ifstream cin ("bookface.in");
    ofstream cout ("bookface.out");
    int n;
    int x, fact;   long long s, putere;
    cin >> n;
    while (n--) {
        cin >> x;
        s = 1;
        for (fact = 2; fact*fact <= x; ++fact) {
            putere = fact;
            while (x % fact == 0) {
                putere *= fact;
                x /= fact;
            }
            s *= (putere * putere / fact - 1) / (fact - 1);
        }
        if (x != 1)
            s *= (1ll * x * x * x - 1) / (x - 1);
        cout << s << '\n';
    }
    return 0;
}