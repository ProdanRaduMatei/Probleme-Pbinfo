#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, v[4];
    cin >> n;
    v[1] = n % 10;
    v[2] = n / 10 % 10;
    v[3] = n / 100 % 10;
    sort(v + 1, v + 1 + 3);
    cout << v[1] << " " << v[2] << " " << v[3];
    return 0;
}
