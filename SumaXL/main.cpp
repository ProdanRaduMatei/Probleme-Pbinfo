#include <fstream>

using namespace std;

ifstream fin ("sumaxl.in");
ofstream fout ("sumaxl.out");

int main() {
    int mare_sz, mic, i, count, suma;
    fin >> mare_sz;
    int v[101];
    for (i = 0; i < 101 - mare_sz; ++i)
        v[i] = 0;
    for (; i < 101; ++i)
        fin >> v[i];
    fin >> mic;
    count = 0;
    i = 100;
    while (mic || count) {
        suma = mic % 10 + v[i] + count;
        v[i] = suma % 10;
        count = suma / 10;
        i--;
        mic /= 10;
    }
    i = 0;
    while (v[i] == 0)
        i++;
    for (; i < 101; ++i)
        fout << v[i];
    fin.close();
    fout.close();
    return 0;
}