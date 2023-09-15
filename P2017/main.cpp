#include <bits/stdc++.h>

using namespace std;

ifstream fin("2017.in");
ofstream fout("2017.out");

int Q, c;
long long K;

long long getFreq(long long n, int c) {
    long long sol = 0, p10 = 1, k = 0;
    while (n >= c) {
        if (n % 10 > c)
            sol += (n / 10 + 1) * p10;
        else if (n % 10 == c)
            sol += (n / 10) * p10 + k + 1;
        else sol += (n / 10) * p10;
        k += (n % 10) * p10;
        n /= 10;
        p10 *= 10;
    }
    return sol;
}

long long query(int c, long long K) {
    long long le = 1, ri = 1e13, mid, best;
    while (le <= ri) {
        mid = (le + ri) / 2;
        if (getFreq(mid, c) >= K) {
            best = mid;
            ri = mid - 1;
        }
        else
            le = mid + 1;
    }
    return best;
}

int main() {
    for (fin >> Q; Q; --Q) {
        fin >> c >> K;
        fout << query(c, K) << endl;
    }
}
