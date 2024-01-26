#include <bits/stdc++.h>

using namespace std;

ifstream fin("primprim.in");
ofstream fout("primprim.out");

const int MAX=1000005;
int n, C, Q, v[MAX], nr, aux, arr[MAX], la, fr[60];
long long suma;
bool prime[MAX];

void sieve()
{
    for (int i = 4; i < MAX; i+= 2)
        prime[i] = true;
    for (int i = 3; i * i < MAX; i += 2)
        if (prime[i] == false)
            for (int j = i * i; j < MAX; j += 2 * i)
                prime[j] = true;
    arr[la++] = 2;
    for (int i = 3; i < MAX; ++i)
        if (prime[i] == false)
            arr[la++] = i;
}

int CautBin(int arr[], int ln, int val)
{
    int st = 0, dr = ln - 1, p = 0, mid;
    while (st <= dr)
    {
        mid = st + (dr - st) / 2;
        if (val < arr[mid]) {
            p = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }
    return p;
}

int closestPrime(int number)
{
    int index = CautBin(arr, la, number);
    if (arr[index] == number || arr[index - 1] == number)
        return number;
    else
        if (abs(arr[index] - number) < abs(arr[index - 1] - number))
            return arr[index];
        else
            return arr[index - 1];
}

int main()
{
    fin >> C >> n;
    sieve();
    if (C == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            fin >> nr;
            if (nr == 0)
                v[i] = 2;
            else
                if (nr == 1)
                    v[i] = 1;
                else
                    if (!prime[nr])
                        v[i] = 0;
                    else {
                        aux = closestPrime(nr);
                        v[i] = (nr > aux ? nr - aux : aux - nr);
                    }
            suma += v[i];
        }
        fout << suma;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        fin >> nr;
        if (nr == 0) {
            ++fr[2];
            v[i] = 2;
        }
        else
            if (nr == 1) {
                ++fr[1];
                v[i] = 1;
            }
            else
                if (!prime[nr]) {
                    ++fr[0];
                    v[i] = 0;
                }
                else {
                    aux = closestPrime(nr);
                    ++fr[(nr > aux ? nr - aux : aux - nr)];
                    v[i] = (nr > aux ? nr - aux : aux - nr);
                }
    }
    fin >> Q;
    for (int q = 1; q <= Q; ++q)
    {
        int i, x, p, cost;
        fin >> i >> x >> p;
        aux = closestPrime(x);
        cost = (x > aux ? x - aux : aux - x);
        --fr[v[i]];
        ++fr[cost];
        v[i] = cost;
        int cmin = 0;
        nr = 0;
        for (int c = 0; c < 58; ++c)
            if (fr[c])
            {
                if (nr + fr[c] < p) {
                    cmin += fr[c] * c;
                    nr += fr[c];
                }
                else
                    if (nr + fr[c] == p)
                    {
                        cmin += fr[c] * c;
                        break;
                    }
                    else
                    {
                        int diff = fr[c];
                        cmin += fr[c] * c;
                        cmin -= c * (nr + diff - p);
                        break;
                    }
            }
        fout << cmin << '\n';
    }
    return 0;
}