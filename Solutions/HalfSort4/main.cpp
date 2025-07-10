#include <fstream>

using namespace std;

ifstream cin("halfsort4.in");
ofstream cout("halfsort4.out");

int main()
{
    int i, j, n, v[1001];
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if ((v[i] < 0 && v[j] < 0 && v[i] > v[j]) || (v[i] > 0 && v[j] > 0 && v[i] < v[j]))
        swap(v[i], v[j]);
    for (i = 1; i <= n; i++)
        cout << v[i] << " ";
    return 0;
}