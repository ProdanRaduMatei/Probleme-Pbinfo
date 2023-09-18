#include<fstream>
#include<cmath>

using namespace std;

ifstream fin("unificare.in");
ofstream fout("unificare.out");

int f[10], v[100001], best[10];

void schimba(int n, int p) {
    int local[10] = {0};
    while(n) {
            local[n % 10] += p;
            n /= 10;
        }
    if (p == 1)
        for (int i = 0 ; i <= 9 ; i++)
            f[i] += min(1, local[i]);
    else 
        for (int i = 0 ; i <= 9 ; i++)
            f[i] += max(-1, local[i]);
}

void copie() {
    for (int i = 0 ; i <= 9 ; i++)
        best[i] = f[i];
}

int cati(int v[]) {
    int s = 0 ;
    for (int i = 0 ; i <= 9 ; i++)
        s += v[i];
    return s;
}

void update() {
    int a = cati(f), b = cati(best);
    if (a > b)
        copie();
    else if (a == b) {
            for (int i = 9 ; i >= 0 ; i--) {	
                	if (best[i] > f[i])
                        break;
                    if (f[i] > best[i]) {
                            copie();
                            return;
                    }
            }
    }
}

int main() {
    int c, n, k;
    fin >> c >> n >> k;
    for (int i = 1; i <= n ; i++)
        fin >> v[i];
    if (c == 1) {
        int ans = 0;
        for (int i = 1; i <= n ; i++)
            if (floor(log10(v[i])) == k - 1)
                ans = max(ans, v[i]);
        fout << ans;
        return 0;
    }
    if (c == 2)
        k = 2;
    for (int i = 1; i <= k ; i++)
        schimba(v[i], 1);
    update();
    for (int u = k + 1; u <= n ; u++) {
            schimba(v[u], 1);
            schimba(v[u - k], -1);
            update();
    }
    for (int i = 9; i >= 0; i--)
        while(best[i]--)
            fout << i;
    return 0;
}