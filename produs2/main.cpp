#include <fstream>
#include <queue>    
#define ull unsigned long long

using namespace std;

ifstream fin("produs2.in");
ofstream fout("produs2.out");

long long n, p, x, ans;
queue <pair <long long, int>> q;

int main() {
    fin >> n >> p;
    long long t = 1, st = 1;
    for (long long i = 1; i <= n; i++) {
        fin >> x;
        q.push({x, i});
        t *= x;
        if (t >= p) {
            while (!q.empty() && t >= p) {
                t /= q.front().first;
                st++;
                q.pop();
            }
        }
        ans += i - st + 1;
    }
    fout << ans;
}