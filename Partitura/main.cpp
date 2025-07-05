#include <cstdio>
#include <queue>
#include <cassert>
#include <climits>

using namespace std;

const int N_MAX = 300000, MAX_HEIGHT = 10000, MAX_LENGTH = 18;

int main() {
    freopen("partitura.in","r",stdin);
    freopen("partitura.out","w",stdout);

    int n;
    long long result = 0;
    priority_queue <long long int> sheet[MAX_LENGTH + 1];
    assert(scanf("%d", &n) == 1);
    assert(1 <= n && n <= N_MAX);
    for (int i = 1; i <= n; ++i) {
        int length, height;
        assert(scanf("%d %d", &length, &height) == 2);
        assert(1 <= height && height <= MAX_HEIGHT);
        assert(1 <= length && length <= MAX_LENGTH);
        sheet[length].push(height);
    }
    for (int i = MAX_LENGTH; i > 0; --i) {
        while (sheet[i].size() >= 2) {
            long long height1, height2;
            height1 = sheet[i].top();
            sheet[i].pop();
            height2 = sheet[i].top();
            sheet[i].pop();
            sheet[i - 1].push(height1 + height2);
        }
    }
    while (!sheet[0].empty()) {
        long long int height = sheet[0].top();
        assert(height * height <= LLONG_MAX - result);
        result += height * height;
        sheet[0].pop();
    }
    printf("%lld", result);
    return 0;
}