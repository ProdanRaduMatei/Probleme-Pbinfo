#include <bits/stdc++.h>

using namespace std;
int inf = 1<<30;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int N, M;

bool InRaza(int urmx, int urmy) {
    return urmx >= 0 && urmy >= 0 && urmx < N && urmy < M;
}

struct stadiu {
    int X;
    int Y;
    int valoare;
};

bool operator<(const stadiu& S1, const stadiu& S2) {
    if (S1.valoare == S2.valoare) {
        if (S1.X == S2.X)
            return S1.Y < S2.Y;
        return S1.X < S2.X;
    }
    return S1.valoare > S2.valoare;
}

int main() {
    cin >> N >> M;
    vector<vector<int>> valoare;
    vector<vector<int>> bun;
    vector<vector<int>> viz;
    valoare.resize(N, vector<int>(M));
    bun.resize(N, vector<int>(M, inf));
    viz.resize(N, vector<int>(M, false));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> valoare[i][j];
    bun[0][0] = 0;
    priority_queue<state> C;
    C.push({0, 0, 0});
    while (!C.empty()) {
        int curentx = C.top().X;
        int curenty = C.top().Y;
        C.pop();
        if (viz[curx][cury])
            continue;
        viz[curx][cury] = true;
        for (int i = 0; i < 4; i++) {
            int urmx = curentx + dx[i];
            int urmy = curenty + dy[i];
            if (!InRaza(urmx, urmy))
                continue;
            int urmvaloare = max(0, valoare[urmx][urmy] - valoare[curentx][curenty]);
            urmvaloare = max(urmvaloare, bun[curentx][curenty]);
            if (bun[urmx][urmy] > urmvaloare) {
                bun[urmx][urmy] = urmvaloare;
                C.push({urmx, urmy, urmvaloare});
            }
        }
    }
    cout << bun[N - 1][M - 1] << endl;
    return 0;
}
