#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <cmath>

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL

ifstream cin("pietricele.in");
ofstream cout("pietricele.out");

int op, n, k;
int v[26];
char s[200005];

void solve1() {
    long long maxi = 0, sum = 0; 
    k = n - k + 1; 
    for (int i = 0; i < n; ++i) { 
        sum += v[s[i] - 'a']; 
        if (i >= k) 
            sum -= v[s[i - k] - 'a']; 
        maxi = max(maxi, sum); 
    } 
    cout << maxi; 
}

void solve2() {
    long long st = 1, dr = INT64_MAX, mini = 0; 
    while (st <= dr) { 
        long long mij = (st + dr) / 2; 
        long long sum = 0, raft = 0; 
        for (int i = 0; i < n; ++i) { 
            sum += v[s[i] - 'a']; 
            if (sum >= mij) { 
                ++raft; 
                sum = 0; 
            } 
        } 
        if (raft >= k) { 
            mini = mij; 
            st = mij + 1; 
        } 
        else  
            dr = mij - 1;
    } 
    cout << mini;
}

int main(){
    cin >> op >> n >> k;
    cin >> s;
    for (int i = 0 ; i < 26 ; ++i)
        cin >> v[i];
    if (op == 1)
        solve1();
    else
        solve2();
    return 0;
}