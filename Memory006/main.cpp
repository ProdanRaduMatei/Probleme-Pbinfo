#include <fstream>
#include <queue>
#define ll unsigned long long
#define INF 1000000000

using namespace std;

ifstream fin("memory006.in");
ofstream fout("memory006.out");

int n, k, exponent, sum, secvente;
queue <int> q;
long long x;

int exponentiere(long long x) {
    int p = 0;
    while (x % 2 == 0) {
        p++;
        x /= 2;
    }
    if (x != 1)
        return INF;
    return p;
}

int main() {
    fin >> n >> k;
    for (int i = 1; i <= n; i++) {
        fin >> x;
        exponent = exponentiere(x);
        q.push(exponent);
        sum += exponent;
        while (!q.empty() && sum > k) {
            int front = q.front();
            sum -= front;
            q.pop();
        }
        if (sum == k)
            secvente++;
    }
    fout << secvente;
}