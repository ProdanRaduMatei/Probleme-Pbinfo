    #include <iostream>
    #include <fstream>

    using namespace std;

    ifstream fin("unice.in");
    ofstream fout("unice.out");

    int main()
    {
        int n, v[100] = {0}, a, m = 0;
        fin >> n;
        for (int i = 1; i <= n; ++i) {
            fin >> a;
            ++v[a];
            if (a > m)
                m = a;
        }
        for (int i = 0; i <= m; ++i)
            if (v[i] == 1)
                fout << i << " ";
        return 0;
    }
