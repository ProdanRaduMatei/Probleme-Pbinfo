#include <fstream>
#define ll long long
using namespace std;

ifstream cin("binar.in");
ofstream cout("binar.out");

long long n, ans, x, lmax, maxi1, maxi2, l, z, temp;
short cerinta;
int poz;

long long bin(long long x) {
    long long t = 0;
    while (x) {
        if ((x & 1LL))
            t++;
        x = (x >> 1LL);
    }
    return t;
}

void read() {
    cin >> cerinta >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> x;
        long long r = bin(x);
        if (maxi1 < r) {
            maxi1 = r;
            if (ans < x || z < maxi1) {
                ans = x;
                z = maxi1;
            }
        }
        else if (maxi1 == r)
            if (ans < x || z < maxi1) {
                ans = x;
                z = maxi1;
            }
        if (!l) {
            l = 1;
            temp = r;
        }
        else if (temp == r) 
            l++;
        else {
            if (lmax < l) {
                lmax = l;
                poz = i - l;
            }
            l = 1;
        }
        temp = r;
    }
}

int main() {
    read();
    if (cerinta == 1)
        cout << ans;
    else {
        if (lmax < l) {
            lmax = l;
            poz = n - l + 1;
        }
        cout << lmax << " " << poz;
    }
}