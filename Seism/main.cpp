#include <fstream>
#include <vector>

using namespace std;

ifstream cin("seism.in");
ofstream cout("seism.out");

int n, task, maxi, st, dr;
vector <bool> v;
vector <pair <int, int> > poz;
bool x;

bool inside(int i) {
    return(i > 2 && i < n - 1);
}

bool length(int x) {
    return(x >= 1 && x <= n - 4);
}

void read() {
    v.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        v.push_back(x);
    }
}

void solve1() {
    bool newseq = 0;
    st = dr = 0;
    int seisme = 0;
    for (int i = 1; i <= n; i++) {
        x = v[i];
        if (x && inside(i) && !newseq && !v[i - 1] && !v[i - 2]) {
            newseq = 1;
            st = i;
            dr = i;
        }
        else if (x && inside(i) && newseq)
            dr = i;
        else if (!x && newseq) {
            newseq = 0;
            if (v[i - 1] && inside(i - 1) && !v[i] && !v[i + 1] && maxi < dr - st + 1 && dr - st + 1 <= n - 4)
                maxi = dr - st + 1;
            if (v[i - 1] && inside(i - 1) && !v[i] && !v[i + 1] && dr - st + 1 <= n - 4)
                seisme++;
            st = dr = 0;
        }
    }
    if (task == 1)
        cout << maxi;
    else
        cout << seisme;
}

void solve3() {
    bool newseq = 0;
    st = dr = 0;
    for (int i = 3; i <= n - 2; i++) {
        x = v[i];
        if (!x && !newseq) {
            st = dr = i;
            newseq = 1;
        }
        else if (!x && newseq)
            dr = i;
        else if (x && newseq) {
            newseq = 0;
            poz.push_back({ st, dr });
            st = dr = 0;
        }
    }
    if (dr)
        poz.push_back({ st,dr });
    int maxi = -1;
    for (auto e : poz) {
        int st = e.first;
        int dr = e.second;
        int st_temp = st;
        int dr_temp = dr;
        while (v[st_temp - 1] && st_temp > 1)
            st_temp--;
        while (v[dr_temp + 1] && dr_temp < n)
            dr_temp++; 
        if (inside(st_temp) && !v[st_temp - 1] && !v[st_temp - 2] && inside(dr_temp) && !v[dr_temp + 1] && !v[dr_temp + 2])
            if (maxi < dr_temp - st_temp + 1 && length(dr_temp - st_temp + 1))
                maxi = dr_temp - st_temp + 1;
        int st_2 = st + 2;
        if (inside(st_2) && !v[st_2 - 1] && !v[st_2 - 2] && inside(dr_temp) && !v[dr_temp + 1] && !v[dr_temp + 2])
            if (maxi < dr_temp - st_2 + 1 && length(dr_temp - st_2 + 1))
                maxi = dr_temp - st_2 + 1;
        int st_3 = st + 2, dr_3 = dr - 2;
        if (inside(st_3) && !v[st_3 - 1] && !v[st_3 - 2] && inside(dr_3) && !v[dr_3 + 1] && !v[dr_3 + 2])
            if (maxi < dr_3 - st_3 + 1 && length(dr_3 - st_3 + 1))
                maxi = dr_3 - st_3 + 1;
        int dr_4 = dr - 2;
        if (inside(st_temp) && !v[st_temp - 1] && !v[st_temp - 2] && inside(dr_4) && !v[dr_4 + 1] && !v[dr_4 + 2])
            if (maxi < dr_4 - st_temp + 1 && length(dr_4 - st_temp + 1))
                maxi = dr_4 - st_temp + 1;
    }
    cout << maxi;
}

int main() {
    cin >> task >> n;
    read();
    if (task == 1 || task == 2)
        solve1();
    else
        solve3();
}