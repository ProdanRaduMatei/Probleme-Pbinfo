#include <iostream>

struct numar{
    int val;
    long long sumdiv;
}v[1000];
int n, total;

long long div(int x){
    long long sum = 0;
    for (int d = 1; d * d <= x; d++)
        if (x % d == 0) {
            sum += d;
            if (d * d < x)
                sum += x / d;
        }
    return sum;
}

int main(void) {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i].val;
        v[i].sumdiv = div(v[i].val);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i].sumdiv == v[j].sumdiv)
                total++;
    std::cout << total;
}