#include <bits/stdc++.h>

using namespace std;

bool compara(pair<int,int>& P1, pair<int,int>& P2) {
    return P1.second < P2.second;
}

void proces(vector<string>& D, string& S) {
    vector<pair<int,int>> V;
    for (auto i : D) {
        auto poz = S.find(i);
        while (poz != -1) {
            V.push_back({poz, poz + i.size() - 1});
            poz++;
            poz = S.find(i, poz);
        }
    }
    sort(V.begin(), V.end(), compara);
    int sfarsit = -1;
    int contor = 0;
    for (auto i : V)
        if (i.first > sfarsit) {
            sfarsit = i.second;
            contor++;
        }
    cout << contor << endl;
}

int main() {
    vector<string> D;
    string S;
    while (cin >> S && S != "#")
        D.push_back(S);
    string mare;
    string T;
    while (cin >> T && T != "#") {
        mare += T;
        if (mare.back() == '|') {
            proces(D, mare);
            mare = "";
        }
    }
    return 0;
}
