#include <bits/stdc++.h>

using namespace std;

bool merge(int inceput, int sfarsit, vector<vector<int>>& indecsi, vector<int>& interogari) {
    int total = 0;
    for (auto i : interogari) {
        auto jos = lower_bound(indecsi[i].begin(), indecsi[i].end(), inceput);
        auto sus = upper_bound(indecsi[i].begin(), indecsi[i].end(), sfarsit);
        total += distance(jos, sus);
    }
    int nevoi = (sfarsit - inceput) + 1;
    return total >= nevoi;
}

void rezolva(int inceput, vector<vector<int>>& indecsi, vector<int>& interogari, int n) {
    sort(interogari.begin(), interogari.end());
    interogari.erase(unique(interogari.begin(), interogari.end()), interogari.end());
    int jos = inceput;
    int sus = n;
    int minim;
    if (!merge(inceput, inceput, indecsi, interogari)) {
        cout << 0 << endl;
        return;
    }
    while (jos + 1 < sus) {
        minim = (jos + sus) / 2;
        if (merge(inceput, minim, indecsi, interogari))
            jos = minim;
        else
            sus = minim;
    }
    cout << jos - inceput + 1 << endl;
}

map<int,int> comprima(set<int>& S) {
    vector<int> V;
    for (auto i : S)
        V.push_back(i);
    map<int,int> conv;
    for (int i = 0; i < V.size(); i++)
        conv[V[i]] = i;
    return conv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> V(N);
    set<int> S;
    for (auto& i : V) {
        cin >> i;
        S.insert(i);
    }
    map<int,int> conv = comprima(S);
    vector<vector<int>> indecsi(N);
    for (int i = 0; i < V.size(); i++) {
        V[i] = conv[V[i]];
        indecsi[V[i]].push_back(i);
    }
    int C;
    cin >> C;
    for (int i = 0; i < C; ++i) {
        int inceput, sz;
        cin >> inceput >> sz;
        inceput--;
        set<int> interogari;
        for (int j = 0; j < sz; j++) {
            int T;
            cin >> T;
            if(S.count(T) == 0)
                continue;
            interogari.insert(conv[T]);
        }
        vector<int> actual;
        for (auto i : interogari)
            actual.push_back(i);
        rezolva(inceput, indecsi, actual, N);
    }
    return 0;
}
