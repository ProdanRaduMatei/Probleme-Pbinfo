#include <fstream>

using namespace std;

ifstream fin("covoare1.in");
ofstream fout("covoare1.out");

struct covor{
    int l, c;
}sc[200001];

int n, m, p;
int lm, cm;

int main()
{
    fin >> n >> m >> p;
    lm = cm = 1;
    for (int i = 1; i <= p; ++i) {
        fin >> sc[i].l >> sc[i].c;
        fout << lm << " " << cm << endl;

    }
    return 0;
}
