#include <cctype>
inline void Alphanum (char s[], char cuv[][21], int& n, int num [], int& m)
{
    n = m = 0;
    for (int i = 0; s[i]; ) {
        if (std::isalpha (s[i])) {
            int k = 0;
            while (std::isalpha (s[i]) && s[i])
                cuv[n][k ++] = s[i], ++ i;
            ++ n;
        }
        else if (std::isdigit (s[i])) {
           while (std::isdigit (s[i]) && s[i])
               num[m] = num[m] * 10 + (s[i] - '0'), ++ i;
           ++ m;
        }
        else ++ i;
    }
}
