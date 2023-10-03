#include <fstream>
#include <stack>
#define ll long long
using namespace std;

ifstream cin("izi.in");
ofstream cout("izi.out");

long long t, n, task, x, y, add;
stack <long long> v;
long long mars[1000001], k;

int main() {
    cin >> t;
    while (t) {
        cin >> task;
        if (!task) {
            cin >> x;
            v.push(x);
            k++;
        }
        else if (task == 1) {
            cin >> x >> y >> add;
            mars[x - 1] -= add;
            mars[y] += add;
        }
        else if (task == 2) {
            mars[k - 1] += mars[k];
            mars[k] = 0;
            k--;
            v.pop();
        }
        cout << v.top() + mars[k] << "\n";
        t--;
    }
}