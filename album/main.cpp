#include <fstream>

using namespace std;

ifstream cin("album.in");
ofstream cout("album.out");

int a[800002], n;
short task;
void citeste() {
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

bool verificare(int n, int max1, int max2) {
    int frecv[11] = {0};
    while (n) {
        frecv[n % 10]++;
        n /= 10;
    } 
    if ((max1 != max2 && frecv[max1] > 0 && frecv[max2] > 0) || (max1 == max2 && frecv[max1] >= 2))
        return 1;
    return 0;
}

int main() {
    cin >> task >> n;
    if (task == 1) {
        int max1, max2;
        for (int i = 1; i <= n; ++i) {
            max1 = -1, max2 = -1;
            int x;
            cin >> x;
            while (x) {
                int c = x % 10;
                if (c >= max1) {
                    max2 = max1;
                    max1 = c;
                }
                else if (c >= max2)
                    max2 = c;
                x /= 10;
            }
        }
        cout << max2 << " " << max1; 
    }
    else {
        int cnt1 = 0;
        int cnt2 = 0;
        citeste();
        bool impartire = false;
        for (int i = 1; i <= n; ++i) {
            if (a[i]) {
                int x = a[i];
                int max1 = -1, max2 = -1;
                int copieX = x;
                while (copieX) {
                    int cifra = copieX % 10;
                    if (cifra >= max1) {
                        max2 = max1;
                        max1 = cifra;
                    }
                    else if (cifra >= max2)
                        max2 = cifra;
                    copieX /= 10;
                }
                if (!impartire)
                    cnt1 ++;
                else
                    cnt2 ++;
                a[i] = 0;
                for (int j = i + 1; j <= n; ++j) {
                    if (a[j])
                        if (verificare(a[j], max1, max2)) {
                            if (!impartire)
                                cnt1 ++;
                            else
                                cnt2 ++;
                            a[j] = 0;
                        }
                }
                if (!impartire)
                    impartire = true;
                else
                    impartire = false;
            }
        }
        if (cnt1 == cnt2) 
            cout << "V R" << "\n" << cnt1;
        else {
            if (cnt1 > cnt2)
                cout << "V" << '\n' << cnt1;
            else
                cout << "R" << '\n' << cnt2;
        }
    }
    return 0;
}