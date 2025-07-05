#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <numeric>

const std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317};

const int MOD = 1e9 + 9;

int lgpow(int a, int b)
{
    int answer = (b >= 0);
    while (b > 0)
    {
        if (b % 2 == 1)
            answer = (int64_t)answer * a % MOD;
        b /= 2;
        a = (int64_t)a * a % MOD;
    }
    return answer;
}

int solveBothUnknown(int N, int M, const std::vector<int> &phi)
{
    int answer = 1;
    for (int i = 2; i <= M; i++)
    {
        answer += 2 * phi[i];
        if (answer >= MOD)
            answer -= MOD;
    }
    answer = (int64_t)answer * N % MOD * (N - 1) % MOD * lgpow(2, MOD - 2) % MOD * lgpow(M, N - 2) % MOD;
    return answer;
}

int solveRest(int R, int M, const std::vector<int> &V, const std::vector<int> &phi)
{
    if (V.empty())
        return 0;
    int answerFixed = 0, answerPaired = 0;
    std::vector<int> fr(*max_element(V.begin(), V.end()) + 1);
    for (int i = 0; i < (int)V.size(); i++)
    {
        std::vector<int> primeFactors;
        int tmp = V[i];
        for (const int &prime : primes)
        {
            if (tmp % prime == 0)
            {
                primeFactors.push_back(prime);
                while (tmp % prime == 0)
                    tmp /= prime;
            }
            if (tmp == 1)
                break;
        }
        if (tmp > 1)
            primeFactors.push_back(tmp);
        int count = 0, countCoprime = 0;
        for (int mask = 1; mask < (1 << (int)primeFactors.size()); mask++)
        {
            int value = 1, card = 0;
            for (int i = 0; i < (int)primeFactors.size(); i++)
                if ((mask & (1 << i)) > 0)
                {
                    value = value * primeFactors[i];
                    card++;
                }
            count += fr[value] % MOD * (card % 2 == 1 ? 1 : -1);
            if (count >= MOD)
                count -= MOD;
            countCoprime += (M / value) * (card % 2 == 1 ? 1 : -1);
            if (countCoprime >= MOD)
                countCoprime -= MOD;
            fr[value]++;
        }
        answerPaired += M - countCoprime;
        if (answerPaired >= MOD)
            answerPaired -= MOD;
        answerFixed += i - count;
        if (answerFixed >= MOD)
            answerFixed -= MOD;
    }
    answerFixed = (int64_t)answerFixed * lgpow(M, R) % MOD;
    answerPaired = (int64_t)answerPaired * lgpow(M, R - 1) % MOD * R % MOD;
    return (answerFixed + answerPaired) % MOD;
}

int main()
{
    assert(freopen("countall.in", "r", stdin));
    assert(freopen("countall.out", "w", stdout));

    int N, M; std::cin >> N >> M;
    std::vector<int> V(N), fixedValues;
    for (int &x : V)
    {
        std::cin >> x;
        if (x > 0)
            fixedValues.push_back(x);
    }
    std::vector<int> phi(M + 1);
    std::iota(phi.begin(), phi.end(), -1);
    for (int i = 2; i <= M; i++)
        for (int j = 2 * i; j <= M; j += i)
            phi[j] -= phi[i];
    int R = N - (int)fixedValues.size();
    std::cout << (solveBothUnknown(R, M, phi) + solveRest(R, M, fixedValues, phi)) % MOD << "\n";
    return 0;
}