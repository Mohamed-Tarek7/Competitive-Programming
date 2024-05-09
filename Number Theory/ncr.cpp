 
const int N = 1e6+10;
int fact[N], invfact[N];
void pre()
{
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL*fact[i-1]*i%mod;
        invfact[i] = mpow(fact[i], mod-2, mod);
    }
}
 
int nCr(int n, int r)
{
    if (r > n) return 0;
    return 1LL*fact[n]*invfact[r]%mod*invfact[n-r]%mod;
}
