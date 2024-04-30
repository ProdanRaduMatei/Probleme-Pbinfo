#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> memorizedActs(20);
long long fib[88] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903, 2971215073, 4807526976, 7778742049, 12586269025, 20365011074, 32951280099, 53316291173, 86267571272, 139583862445, 225851433717, 365435296162, 591286729879, 956722026041, 1548008755920, 2504730781961, 4052739537881, 6557470319842, 10610209857723, 17167680177565, 27777890035288, 44945570212853, 72723460248141, 117669030460994, 190392490709135, 308061521170129, 498454011879264, 806515533049393, 1304969544928657, 2111485077978050, 3416454622906707, 5527939700884757, 8944394323791464, 14472334024676221, 23416728348467685, 37889062373143906, 61305790721611591, 99194853094755497, 160500643816367088, 259695496911122585, 420196140727489673, 679891637638612258};

string generateLines(int N, long long P, long long L)
{
    if (L == 0)
        return "";
    if (N <= 20)
    {
        string actN = memorizedActs[N - 1];
        return actN.substr(P - 1, L);
    }
    if (N == 1)
        return string(L, 'A');
    else if (N == 2)
        return string(L, 'D');
    long long lenN_2 = fib[N - 2];
    long long lenN_1 = fib[N - 1];

    if (P <= lenN_2)
    {
        if (P + L <= lenN_2)
            return generateLines(N - 2, P, L);
        else
        {
            string prefixN_2 = generateLines(N - 2, P, lenN_2 - P + 1);
            string prefixN_1 = generateLines(N - 1, 1, L - (lenN_2 - P + 1)).substr(0, lenN_1);
            return prefixN_2 + prefixN_1;
        }
    }
    else
        return generateLines(N - 1, P - lenN_2, L);
}

int main()
{
    ifstream fin("teatru.in");
    ofstream fout("teatru.out");
    int N;
    long long P, L;
    fin >> N >> P >> L;
    memorizedActs[0] = "A";
    memorizedActs[1] = "D";
    for (int i = 2; i < 20; ++i)
        memorizedActs[i] = memorizedActs[i - 2] + memorizedActs[i - 1];
    string result;
    if (N <= 20)
        result = memorizedActs[N - 1].substr(P - 1, L);
    else
        result = generateLines(N, P, L);
    fout << result << '\n';
    return 0;
}