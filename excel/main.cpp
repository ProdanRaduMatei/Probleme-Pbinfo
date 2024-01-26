#include <bits/stdc++.h>

using namespace std;

typedef pair<short int,short int> Pair;
unordered_map<int,vector<Pair>> mp;

int main()
{
    short int n;
    int s;
    ifstream fin("excel.in");
    fin >> n >> s;
    int v[n + 1];
    for (short int i = 0; i < n; ++i)
        fin >> v[i];
    int cnt = 0;
    for (short int i = 0; i < n - 1; ++i)
        for (short int j = i + 1; j < n; ++j)
        {
            int val = s - (v[i] + v[j]);
            if (mp.find(val) != mp.end())
            {
                for (auto pair: mp.find(val) -> second)
                {
                    short int x = pair.first, y = pair.second;
                    if ((x != i && x != j) && (y != i && y != j) && (x != y && i != j))
                        ++cnt;
                }
            }
            mp[v[i] + v[j]].push_back({i, j});
        }
    ofstream fout("excel.out");
    fout << cnt / 3;
    return 0;
}