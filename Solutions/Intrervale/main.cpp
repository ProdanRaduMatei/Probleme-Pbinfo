#include <fstream>

using namespace std;

ifstream fin("intervale.in");
ofstream fout("intervale.out");

struct interval
{
    int start, final;
    bool intersectat;
};

void Intervale()
{
    int n;
    interval V[101] = {0};
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> V[i].start >> V[i].final;
        for (int j = i - 1; j >= 1; --j)
            if (V[i].final >= V[j].start && V[i].start <= V[j].final)
            {
                V[i].intersectat = true;
                V[j].intersectat = true;
            }
    }
    int contor = 0;
    for (int i = 1; i <= n; ++i)
        if (V[i].intersectat == false)
            contor++;
    fout << contor << '\n';
    for (int i = 1; i <= n; ++i)
        if (V[i].intersectat == false)
            fout << V[i].start << ' ' << V[i].final << '\n';
}

int main()
{
    Intervale();
    return 0;
}
