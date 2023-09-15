
#include <iostream>

using namespace std;

struct obiect{
    double w, v;
}Ob[101];

void ordonare(int n, obiect Ob[])
{
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (Ob[i].w / Ob[i].v > Ob[j].w / Ob[j].v)
                swap(Ob[i], Ob[j]);
}

int main() {
    int n, g;
    cin >> n >> g;
    for (int i = 1; i <= n; ++i)
        cin >> Ob[i].w >> Ob[i].v;
    ordonare(n, Ob);
    for (int i = 1; i <= n; ++i)
        if (Ob[i].w <= g)
        {
            cout << Ob[i].w << " " << Ob[i].v << endl;
            g -= Ob[i].w;
        }
    return 0;
}
