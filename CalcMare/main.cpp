#include <fstream>
#include <vector>

using namespace std;

ifstream cin("calcmare.in");
ofstream cout("calcmare.out");

vector<int> v1, v2, finall, sum, dif;
char op;
string x, y;

void adunare()
{

    bool used = 0;
    int r = 0;
    if (v1.size() <= v2.size())
    {

        for (int i = 0; i < v2.size(); i++)
        {
            int s = v2[i];
            if (!used)
            {
                s += r;
                used = 1;
            }

            if (i < v1.size())
                s += v1[i];

            if (s < 10)
                sum.push_back(s);
            else
            {
                sum.push_back(s % 10);
                r = s / 10;
                used = 0;
            }
        }
    }
    else
    {

        for (int i = 0; i < v1.size(); i++)
        {
            int s = v1[i];
            if (!used)
            {
                s += r;
                used = 1;
            }

            if (i < v2.size())
                s += v2[i];

            if (s < 10)
                sum.push_back(s);
            else
            {
                sum.push_back(s % 10);
                r = s / 10;
                used = 0;
            }
        }
    }

    while (r && !used)
    {
        sum.push_back(r % 10);
        r /= 10;
    }

    for (int i = sum.size() - 1; i >= 0; i--)
        finall.push_back(sum[i]);

    for (auto e : finall)
        cout << e;
}

void scadere()
{

    for (int i = 0; i < v1.size(); i++)
    {

        int s = v1[i];

        if (i < v2.size())
            s -= v2[i];

        if (s < 0)
        {
            int p = i + 1;
            s += 10;
            while (p < v1.size() - 1 && v1[p] - 1 < 0)
            {
                v1[p] = 9;
                p++;
            }

            v1[p]--;
        }
        dif.push_back(s);
    }

    for (int i = dif.size() - 1; i >= 0; i--)
        finall.push_back(dif[i]);

    bool nonzero = 0;

    for (auto e : finall)
    {
        if (e || nonzero)
            cout << e;
        if (e)
            nonzero = 1;
    }

    if (!nonzero)
        cout << 0;
}

int main()
{

    cin >> x >> y >> op;
    for (int i = x.size() - 1; i >= 0; i--)
        v1.push_back(int(x[i]) - 48);

    for (int i = y.size() - 1; i >= 0; i--)
        v2.push_back(int(y[i]) - 48);

    if (op == '+')
        adunare();
    else
        scadere();
}