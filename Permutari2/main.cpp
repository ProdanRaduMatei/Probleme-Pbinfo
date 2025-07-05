#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("permutari2.in");
ofstream fout("permutari2.out");

int val_min = 1, val_max;
int n, elem[255];
vector<int>sol;

int solutie() {
    return sol.size() == n;
}

void prelucrare_sol() {
    for (const auto& it : sol)
        fout << elem[it] << " ";
    fout << "\n";
}

bool valid() {
    for (auto i = sol.begin(); i != sol.end() - 1; ++i)
        if (*i == sol.back())
            return 0;
    return 1;
}

void back() {
    for (int i = val_min; i <= val_max; ++i) {
        sol.push_back(i);
        if (valid())
            if (solutie())
                prelucrare_sol();
            else
                back();
        sol.pop_back();
    }
}

int main()
{
    fin >> n;
    ///elem.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        fin >> elem[i];
    }
    sort(elem + 1, elem + n + 1);
    val_max = n;
    back();
    return 0;
}
