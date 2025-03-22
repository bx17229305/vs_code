#include "bits/stdc++.h"
#include <iostream>
using namespace std;
#define int long long
using ll = long long;
const int N = 1e6 + 10;
int mod = 1e9 + 7;
int n, m, k, p;
#define get cin >>
#define ex cout <<
#define rep(i, j, k) for (int i = j; i <= k; i++)
#define per(i, j, k) for (int i = j; i >= k; i--)
int inv2 = (mod + 1) / 2;

int f[N], g[N];

int inv(int n)
{
    ll base = n;
    ll res = 1;
    int q = p - 2;
    while (q)
    {
        if (q & 1)
            res = res * base % p;
        base = base * base % p;
        q >>= 1;
    }
    return res;
}

void prepare(int n)
{
    f[0] = 1;
    rep(i, 1, n)
        f[i] = f[i - 1] * i % p;
    g[0] = 1;
    rep(i, 1, n)
        g[i] = inv(f[i]);
}

int C(int n, int m)
{
    if (n < m)
        return 0;
    if (m == 0)
        return 1;
    return f[n] * g[m] * g[n - m] % p;
}

int lucas(int n, int m)
{
    if (n < m)
        return 0;
    if (m == 0)
        return 1;
    return lucas(n / p, m / p) * C(n % p, m % p) % p;
}

void solve()
{
    get n >> m >> p;
    prepare(n + m);
    int res = lucas(n + m, m);
    ex res << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    get T;
    while (T--)
    {
        solve();
    }
    return 0;
}