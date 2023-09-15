#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("multimi2.in");
ofstream fout("multimi2.out");

int n;
int p1, m1, p2, m2;

int main()
{
    fin >> n;
    fin >> m1 >> p1 >> m2 >> p2;
    if (n == 1) {
        if (p1 > p2) {
            if (p2 + m2 - 1 < p1) {
                for (int i=p2; i<=p2 + m2 - 1; i++)
                    fout << i << " ";
                for (int i=p1; i<=p1 + m1 - 1; i++)
                    fout << i << " ";
            }
            else {
            for (int i=p2; i<=p1-1; i++)
                fout << i << " ";
            for (int i=p1; i<=p1 + m1 - 1; i++)
                fout << i << " ";
            for (int i=p1 + m1; i<=p2+m2-1; i++)
                fout << i << " ";
            }
        }
        else {
            if (p1 + m1 - 1 < p2) {
                for (int i=p1; i<=p1 + m1 - 1; i++)
                    fout << i << " ";
                for (int i=p2; i<=p2 + m2 - 1; i++)
                    fout << i << " ";
            }
            else {
                for (int i=p1; i<=p2-1; i++)
                    fout << i << " ";
                for (int i=p2; i<=p2 + m2 - 1; i++)
                    fout << i << " ";
                for (int i=p2 + m2; i<=p1+m1-1; i++)
                    fout << i << " ";
            }
        }
    }
    else {
        bool valid = 0;
        if (p1 > p2) {
            if (p2 + m2 - 1 >= p1) {
                if (p2 + m2 - 1 <= p1 + m1 - 1)
                    for (int i=p1; i<=p2 + m2 - 1; i++)
                        fout << i << " ";
                else {
                    for (int i=p1; i<=p1 + m1 - 1; i++)
                        fout << i << " ";
                }
                valid = true;
            }
        }
        else {
            if (p2 > p1) {
                if (p1 + m1 - 1 >= p2) {
                    if (p1 + m1 - 1 <= p2 + m2 - 1)
                        for (int i=p2; i<=p1 + m1 - 1; i++)
                            fout << i << " ";
                    else {
                        for (int i=p2; i<=p2 + m2 - 1; i++)
                            fout << i << " ";
                    }
                    valid = true;
                }
            }
            else {
            if (p1 == p2) {
                if (m1 > m2) {
                    for (int i=p1; i<=p1+m2; i++)
                        fout << i;
                    valid = true;
                    }
                    else {
                        for (int i=p1; i<=p1+m1; i++)
                            fout << i;
                        valid = true;
                    }
                }
            }
        }
        if (valid == false) {
            fout << -1;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
