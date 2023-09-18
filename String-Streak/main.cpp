#include <iostream>
#include <cstring>

using namespace std;

const int LGMAX = 1e5;
char s[LGMAX + 5];
int N;
long long C, p2[35];
int distToNextC[LGMAX + 5];

int Solve(char ch) {
    distToNextC[N + 1] = 32;
    for (int i = N; i >= 1; i--)
        if (s[i] != ch)
            distToNextC[i] = 1 + distToNextC[i + 1];
        else
            distToNextC[i] = 0;

    int ret = 0, l = 1, currDif = 0;
    long long currCost = 0LL;
    for (int r = 1; r <= N; r++) {
        if (s[r] == ch) {
            currDif = 0;
            ret = max(ret, r - l + 1);
            continue;
        }
        currDif++;
        if (r - l > currDif) {
            currCost -= p2[currDif - 1];
            currCost += p2[currDif];
        }
        else {
            currCost -= p2[r - l];
            currCost += p2[r - l + 1];
        }
        while (currCost > C) {
            int mnDist = min(distToNextC[l], r - l + 1);
            l++;
            if (mnDist == 0)
                continue;
            if (mnDist > 30)
                continue;
            else {
                currCost -= p2[mnDist];
                mnDist--;
                currCost += p2[mnDist];
            }
        }
        ret = max(ret, r - l + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    p2[1] = 2;
    for (int i = 2; i <= 32; i++)
        p2[i] = 2LL * p2[i - 1];
    cin >> (s + 1);
    N = strlen(s + 1);
    cin.get();
    cin >> C;
    int sol = 1;
    for (int i = 1; i <= 32; i++)
        if (p2[i] <= C)
            sol = i;
    for (char ch = 'a'; ch <= 'z'; ch++)
        sol = max(sol, Solve(ch));
    cout << sol << '\n';
    return 0;
}