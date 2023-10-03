#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

ifstream fin("betisoare1.in");
ofstream fout("betisoare1.out");

int main(void) {
    int n, ones = 0, zeroes = 0, crt = 0, maxlen = INT_MIN;
    char c, prev = '2';
    fin >> n;
    while(n--) {
        fin >> c;
        if (c == prev)
            crt++;
        else {
            if (crt > maxlen) {
                maxlen = crt;
                if (prev == '0') {
                    ones = 0;
                    zeroes = 1;
                }
                else if (prev == '1') {
                    ones = 1;
                    zeroes = 0;
                }
            }
            else if (crt == maxlen) {
                if (prev == '0')
                    zeroes++;
                else if (prev == '1')
                    ones++;
            }
            crt = 1;
        }
        prev = c;
    }
    if (crt > maxlen) {
        maxlen = crt;
        if (prev == '0') {
            zeroes = 1;
            ones = 0;
        }
        else if (prev == '1') {
            ones = 1;
            zeroes = 0;
        }
    }
    else if (crt == maxlen) {
        if (prev == '0')
            zeroes++;
        else if (prev == '1')
            ones++;
    }
    if (zeroes > ones)
        fout << 0 << ' ' << maxlen << endl << zeroes;
    else
        fout << 1 << ' ' << maxlen << endl << ones;
    return 0;
}