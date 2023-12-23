#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream cin("cosuri.in");
ofstream cout("cosuri.out");

short task;
int n, x;
pair <int, int> mini = { 1000001, 1000001 }, maxi;
int fr[1000001];
vector <int> v, t;

void solve1() {
    for (int i = 1; i <= 2 * n; i++) {
        cin >> x;
        if (mini.first == 1000001)
            mini.first = x;
        else if (mini.second == 1000001)
            mini.second = x;
        else {
            if (mini.first < mini.second && x < mini.second)
                mini.second = x;
            else if (mini.first > mini.second && x < mini.first)
                mini.first = x;
        }
        if (!maxi.first)
            maxi.first = x;
        else if (!maxi.second)
            maxi.second = x;
        else {
            if (maxi.first < maxi.second && x > maxi.first)
                maxi.first = x;
            else if (maxi.first > maxi.second && x > maxi.second)
                maxi.second = x;
        }
    }
    cout << mini.first + mini.second << " " << maxi.first + maxi.second;
}

void solve2() {
    v.push_back(0);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> x;
        v.push_back(x);
        fr[x]++;
    }
    sort(v.begin(), v.end());
    int back = 2 * n;
    int s = v[1] + v[back];
    int excedent = abs(v[1] - v[back]);
    bool ok = 1;
    back--;
    for (int i = 2; i <= n && ok; i++) {
        if (v[i] + v[back] != s)
            ok = 0;
        else if (v[i] + v[back] == s && fr[v[i]] != fr[v[back]])
            ok = 0;
        else if (v[i] + v[back] == s && fr[v[i]] == fr[v[back]])
            excedent = min(excedent, abs(v[i] - v[back]));
        back--;
    }
    if (ok)
        cout << "DA\n" << excedent;
    else
        cout << "NU";
}

int main() {
    cin >> task >> n;
    if (task == 1)
        solve1();
    else solve2();
}