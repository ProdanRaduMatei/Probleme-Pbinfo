#include <bits/stdc++.h>

using namespace std;

ifstream fin("bug.in");
ofstream fout("bug.out");

string str, sol;
int T, ls, sb;
int bl[100001], P;
set<char>seg;

int main() {
    fin >> T;
    fin >> str;
    ls = str.size();
    bl[0] = ls;
    for (int i = ls - 1; i >= 0; --i) {
        seg.insert(str[i]);
        if (seg.size() == 10) {
            bl[++sb] = i;
            seg.clear();
        }
    }
    if (seg.size()>0) {
        for (int i = 1; i <= 9; ++i) {
            auto pos = seg.find(i + '0');
            if (pos == seg.end()) {
                sol.push_back(i + '0');
                break;
            }
        }
        if (sol.size() == 0) {
            sol.push_back('0' + 1);
            sol.push_back('0');
        }
        for (int i = sb; i >= 1; --i) {
            char ch = sol[sol.size() - 1];
            seg.clear();
            int ok = 0;
            for (int j = bl[i]; j < bl[i - 1] && !ok; ++j)
                if (str[j] == ch) {
                    for (int k = j + 1; k < bl[i - 1]; ++k)
                        seg.insert(str[k]);
                    for (char c = '0'; c <= '9'; ++c) {
                        auto pos = seg.find(c);
                        if (pos == seg.end()) {
                            sol.push_back(c);
                            break;
                        }
                    }
                    ok = 1;
                }
        }
        if (T == 2)
            fout << sol;
        else
            fout << sol.size();
    }
    else {
        sol.push_back('0' + 1);
        for (int i = sb; i >= 1; --i) {
            char ch = sol[sol.size() - 1];
            seg.clear();
            int ok = 0;
            for (int j = bl[i]; j < bl[i - 1] && !ok; ++j)
                if (str[j] == ch) {
                    for (int k = j + 1; k < bl[i - 1]; ++k)
                        seg.insert(str[k]);
                    for (char c = '0'; c <= '9'; ++c) {
                        auto pos = seg.find(c);
                        if (pos == seg.end()) {
                            sol.push_back(c);
                            break;
                        }
                    }
                    ok = 1;
                }
        }
        if (T == 2)
            fout << sol;
        else
            fout << sol.size();
    }
    return 0;
}