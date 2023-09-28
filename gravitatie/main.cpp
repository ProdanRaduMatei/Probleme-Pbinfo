#include <bits/stdc++.h>

using namespace std;

ifstream fin("gravitatie.in");
ofstream fout("gravitatie.out");

int N;
unsigned int x;
set<unsigned int>S;

int main() {
    fin >> N;
    for (int i = 1; i <= N; ++i) {
        fin >> x;
        S.insert(x);
    }
    fout << S.size();
    return 0;
}