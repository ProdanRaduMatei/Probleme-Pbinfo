#include <iostream>
#include <fstream>
using namespace std;
ifstream in("puterik.in");
ofstream out("puterik.out");
void Ordonare(int vector[], int &limita)
{
    int i;
    bool found = true;
    while (found)
    {
        found = false;
        for (i = 1; i <= limita - 1; i++)
        {
            if (vector[i] > vector[i + 1])
            {
                int aux = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = aux;
                found = true;
            }
        }
    }
}

bool Putere(int x, int k)
{
    if (x > 1)
    {
        while (x % k == 0)
        {
            x /= k;
        }
    }
    return (x == 1);
}
int main()
{
    int n, k, m = 0;
    int v[105], put[105];
    int i;
    in >> n >> k;
    while (n)
    {
        in >> v[i];
        if (Putere(v[i], k))
            put[++m] = v[i];
            i++;
            n--;
    }
    Ordonare(put, m);
    for(i = 1; i <= m; i++)
        out << put[i] << " ";
    return 0;
}
