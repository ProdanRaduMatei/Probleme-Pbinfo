#include <fstream>
#include <climits>

using namespace std;

ifstream cin("robot.in");
ofstream cout("robot.out");

short cerinta;
int n, lungime, latime, fr[10001], mini = INT_MAX;

void read() {
    cin >> cerinta;
    cin >> n;
    int nr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> latime >> lungime;
        if (lungime < latime)
            swap(lungime, latime);
        int cod = lungime * 100 + latime;
        if (!fr[cod])
            nr++;
        fr[cod]++;
    }
    if (cerinta == 1)
        cout << nr;
    else {
        for (int i = 1; i <= 10000; i++)
            if (mini > fr[i] && fr[i])
                mini = fr[i];
        cout << mini;
    }
}

int main() {
    read();
}