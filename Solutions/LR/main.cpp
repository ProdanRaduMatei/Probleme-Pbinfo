#include <iostream>

using namespace std;

int main(){
    int n, cate = 0;
    cin >> n;
    int v[n], min[n], max[n], i;
    for (i = 0; i < n; ++i)
        cin >> v[i];
    max[0] = v[0];
    for (i = 1; i < n; ++i)
        if (v[i] < max[i - 1])
            max[i] = max[i - 1];
        else
            max[i] = v[i];
    min[n - 1] = v[n - 1];
    for (i = n - 2; i >= 0; --i)
        if (v[i] > min[i + 1])
            min[i] = min[i + 1];
        else
            min[i] = v[i];
    for (i = 1; i < n - 1; ++i)
        if (max[i - 1] <= v[i] && v[i] <= min[i + 1])
            cate++;
    cout << cate;
    return 0;
}