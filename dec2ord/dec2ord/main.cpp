#include <bits/stdc++.h>

using namespace std;

ifstream fin("dec2ord.in");
ofstream fout("dec2ord.out");

int main() {
    int n , z , per;
    fin >> n >> z >> per;
    if (z == -1 && per == -1)
        fout << n;
    else if (per == -1 && z != -1) {
        int p = 1, cz = z;
        while (cz) {
            p *= 10;
            cz /= 10;
        }
        int a = n * p + z;
        int b = p;
        while (b) {
            int r = a % b;
            a = b;
            b = r;
        }
        fout << (n * p + z) / a << '/' << p / a;
    }
    else if (z == -1 && per != -1) {
        int cper = per, p = 1;
        while (cper) {
            cper /= 10;
            p *= 10;
        }
        int a = n * p + per - n;
        int b = p - 1;
        while (b) {
            int r = a % b;
            a = b;
            b = r;
        }
        fout << (n * p + per - n) / a << '/' << (p - 1) / a;
    }
    else if (z != -1 && per != -1) {
        long long int p = 1, p1 = 1, cz = z, cper = per;
        while (cz) {
            p *= 10;
            cz /= 10;
        }
        while (cper) {
            p1 *= 10;
            cper /= 10;
        }
        long long int q = n * p + z;
        long long int a = q * p1 + per - q;
        long long int b = (p1 - 1) * p;
        while (b) {
            long long int r = a % b;
            a = b;
            b = r;
        }
        fout << 1LL * (q * p1 + per - q) / a << '/' << 1LL * ((p1 - 1) * p) / a;
    }
    return 0;
}

