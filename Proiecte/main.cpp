#include <fstream>

using namespace std;

ifstream fin("proiecte.in");
ofstream fout("proiecte.out");

struct proiect {
    int v, in;
};

int main()
{
    int n;
    fin>>n;
    proiect x[n + 1];
    for(int i = 1; i <= n; ++i) {
        fin >> x[i].v;
        x[i].in = i;
    }
    proiect aux;
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(x[i].v > x[j].v) {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
    for(int i = 1; i <= n; ++i)
        fout << x[i].in << " ";
    return 0;
}
