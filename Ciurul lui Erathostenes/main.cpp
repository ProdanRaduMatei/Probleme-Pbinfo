#include <iostream>
using namespace std;

int main() {
    bool ciur[1000001] = { 0 };
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
        ciur[i] = 1;
    for (int i = 2; i * i <= n; i++)
        if (ciur[i])
            for (int j = i * i; j <= n; j += i)
                ciur[j] = 0;
    for (int i = 2; i <= n; i++)
        if (ciur[i])
            cout << i << " ";
    return 0;
}