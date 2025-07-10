int DivImpar(int a, int b)
{
    int r = a % b;
    while(r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    while (b%2==0) b/=2;
    return b;
}
