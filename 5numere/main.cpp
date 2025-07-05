#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int v[6], s;
    cin >> v[1] >> v[2] >> v[3] >> v[4] >> v[5];
    sort(v + 1, v + 1 + 5);
    s = v[5] + v[4] + v[3];
    cout << s;
    return 0;
}
