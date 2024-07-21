#include <fstream>
#include <queue>

using namespace std;

ifstream fin("teatru.in");
ofstream fout("teatru.out");

int z, c, n;
int fr[201];
queue<char> q, costume;
char caracter, v[55001];

void read()
{
    fin >> z >> c;
    for (int i = 1; i <= z; i++)
    {
        fin >> caracter;
        v[i] = caracter;
    }
}

void solve()
{
    int st = 1, dr = 0;
    pair<int, int> p;
    for (int i = 1; i <= z; i++)
    {
        if (!fr[v[i]])
            q.push(v[i]);
        fr[v[i]]++;
        costume.push(v[i]);
        if (q.size() > c)
        {
            dr = i - 1;
            if (n < dr - st + 1)
            {
                n = dr - st + 1;
                p.first = st;
                p.second = dr;
            }
            while (!costume.empty() && !q.empty() && q.size() > c)
            {
                fr[costume.front()]--;
                if (!fr[costume.front()])
                    q.pop();
                costume.pop();
                st++;
            }
        }
    }
    fout << n << "\n";
    for (int i = p.first; i <= p.second; i++)
        fout << v[i];
}

int main()
{
    read();
    solve();
    return 0;
}