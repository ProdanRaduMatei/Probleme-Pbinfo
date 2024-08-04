#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate_combinations(const vector<char>& letters, int n) {
    int size = letters.size();
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) 
        indices[i] = i;
    while (true) {
        for (int i = 0; i < n; ++i)
            cout << letters[indices[i]];
        cout << endl;
        int i;
        for (i = n - 1; i >= 0; --i)
            if (indices[i] != i + size - n)
                break;
        if (i < 0)
            break;
        ++indices[i];
        for (int j = i + 1; j < n; ++j)
            indices[j] = indices[j - 1] + 1;
    }
}

int main() {
    char a, b;
    int n;
    cin >> a >> b >> n;
    vector<char> letters;
    for (char c = a; c <= b; ++c)
        letters.push_back(c);
    generate_combinations(letters, n);
    return 0;
}