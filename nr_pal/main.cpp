#include <stdio.h>
#include <stdlib.h>
static int numPalindrome(int num);
static int constructPalindrome(int palPrefix, int numLength);
int main(void)
{
    FILE* fin = fopen("nr_pal.in", "r");
    FILE* fout = fopen("nr_pal.out", "w");
    int a = 0, b = 0, n = 0;
    fscanf(fin, "%d", &n);
    while (n-- > 0) {
        fscanf(fin, "%d %d", &a, &b);
        fprintf(fout, "%d\n", numPalindrome(b) - numPalindrome(a-1));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
static int numPalindrome(int num)
{
    int numLength = 0, palLength = 0, palPrefix = 0, temp = 0;
    register int i = 0;
    for (numLength = 0, temp = num; temp != 0; temp /= 10)
        numLength++;
    palLength = (numLength + 1) / 2;
    palPrefix = num;
    for (i = 0; i < numLength - palLength; i++)
        palPrefix /= 10;
    if (constructPalindrome(palPrefix, numLength) > num)
        palPrefix--;
    palPrefix *= 2;
    if (numLength & 1) {
        int adjustment = 1;
        for (i = 1; i < palLength; i++)
            adjustment *= 10;
        palPrefix -= (palPrefix/2 - adjustment + 1);
    } else {
        int adjustment = 1;
        for (i = 0; i < palLength; i++)
            adjustment *= 10;
        palPrefix += (adjustment - 1 - palPrefix/2);
    }
    return palPrefix;
}
static int constructPalindrome(int palPrefix, int numLength)
{
    int front = palPrefix, back = 0;
    if (numLength & 1)
        palPrefix /= 10;
    while (palPrefix != 0) {
        int digit = palPrefix % 10;
        palPrefix /= 10;
        back  = back * 10 + digit;
        front *= 10;
    }
    return front + back;
}
