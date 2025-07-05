#include <iostream>

using namespace std;

int main()
{
    int n, x, k;   int i, j;
    cin >> n;
    long long v[n];
    for (i = 0; i < n; ++i)
        cin >> v[i];
    i = 0;  j = n-1;  k = 0;
    while (i < j)
    {
        if (v[i] == v[j])
            i++,  j--;
        else if (v[i] < v[j])
        {
            v[i+1] = v[i] + v[i+1];
            v[i] = -1;
            k++;  i++;
        }
        else
        {
            v[j-1] = v[j] + v[j-1];
            v[j] = -1;
            k++;  j--;
        }
    }
    cout << k;
    return 0;
}