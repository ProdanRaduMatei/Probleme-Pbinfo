#include <iostream>
#include <fstream>

using namespace std;

#define NR 11

ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

int x[NR], n, p, k;

void afis(int k){
    for(int i = 1; i <= k; ++i)
        fout << x[i] << " ";
    fout << endl;
}
bool valid(int k){
    if(k == 1)
        return true;
    if(x[k] > x[k - 1])
        return true;
    return false;
}
void backtracking(int k){
    for(int i = 1; i <= n; ++i)
    {
        x[k] = i;
        if(valid(k))
        {
            afis(k);
            backtracking(k + 1);
        }
    }
}

int main()
{
    fin >> n;
    backtracking(1);
    return 0;
}
