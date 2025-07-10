#include <bits/stdc++.h>
using namespace std;

ifstream fin ("lowmem1.in");
ofstream fout ("lowmem1.out");

int k;

int main()
{
    fin >> k;
    deque<int> dq;
    long long sum = 0, summax = LLONG_MIN;
    int summax_ind = 1;
    int x;
    for (int i = 1; i <= k; ++i)
    {
        fin >> x;
        dq.push_back(x);
        sum += x;
    }
    for (int i = k+1; fin >> x; ++i)
    {
        sum += x;
        sum -= dq.front();
        dq.push_back(x);
        dq.pop_front();
        if (sum > summax)
        {
            summax = sum;
            summax_ind = i-k+1;
        }
    }
    fin.close();
    fin.open("lowmem1.in");
    fin >> k;
    for (int i = 1; i < summax_ind; ++i)
        fin >> x;
    fout << summax << '\n';
    for (int i = summax_ind; i < summax_ind + k; ++i)
    {
        fin >> x;
        fout << x << ' ';
    }
}