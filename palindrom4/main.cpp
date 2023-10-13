#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL

ifstream fin("palindrom.in");
ofstream fout("palindrom.out");

int op,n;
char nr[55];
int a[50005], s = 0;

int main() { 
    fin >> op >> n;
    for (int i = 1 ; i <= n ; ++i){
        fin >> nr;
        int lennr = strlen(nr) - 1, st = 0, dr = lennr, len = 0, lenmax;
        for (int i = 0 ; i <= lennr ; ++i){
            st = i, dr = lennr;
            while (nr[st] == nr[dr]) {
                st++;
                dr--;
            }
            if (st < dr)
                continue;
            else {
                lenmax = lennr - i;
                break;
            }
        }
        s += lennr  - lenmax;
        a[i] = lennr - lenmax;
    }    
    if (op == 1)
        fout << s;
    else {
        fin >> s;
        queue<int> q;
        int lenmax = 0;
        int sum = 0;
        for (int i = 1 ; i <= n ; ++i) {
            q.push(a[i]);
            sum += a[i];
            while (!q.empty() && sum > s) {
                sum -= q.front();
                q.pop();
            }
            if (q.size() >= 1 && q.size() > lenmax)
                lenmax = q.size();
        }
        fout << lenmax;
    }
    return 0;
}