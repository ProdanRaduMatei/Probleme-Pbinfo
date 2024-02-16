#include <iostream>
#include <fstream>

using namespace std;

int v[10000], q;

static void binary_search(int x)
{
    int left = 0, right = q - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (x == v[mid])
            return;
        else
        {
            if (x < v[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    v[left] = x;
    if (left == q)
        q++;
}

int main()
{
    int n, x, i;
    ifstream fin("gogosi.in");
    ofstream fout("gogosi.out");
    fin >> n;
    for (i = 0; i < n; i++)
    {
        fin >> x;
        binary_search(x);
    }
    fout << q;
    return 0;
}