#include <iostream>
#include <climits>

int n, m, a[10000], b[10000];

int main() {
    int max = INT_MIN;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
        if (b[i] > max)
            max = b[i];
    }
    bool ok = false;
    for (int i = 0; i < n; i++)
        if (a[i] > max)
        std::cout << a[i] << " ", ok = true;
    if (ok == false)
        std::cout << "NU EXISTA";
    return 0;
}