#include "bits/stdc++.h"
#include <iostream>
using namespace std;
#define int long long
using ll = long long;
const int N = 1e6 + 10;
int mod = 1e9 + 7;
int n, m, k;
int inv2 = (mod + 1) / 2;
#define get cin >>
#define ex cout <<
#define rp(i, j, k) for (int i = j; i <= k; i++)
#define pr(i, j, k) for (int i = j; i >= k; i--)
#define mild (r - l) / 2 + l
#define paras int L, int R, int l, int r, int i
#define ld i << 1
#define rd i << 1 | 1
#define vi vector<int>
#define vl vector<ll>
#define pb push_back

int a[N], f[N];

void solve()
{
    cin >> n;
    rp(i, 1, n)
    {
        cin >> a[i];
    }
    rp(i, 1, n)
    {
        f[i] = f[i - 1] + a[i];
        if (i >= 2)
            f[i] = max(f[i - 2], f[i]);
        if (i >= 3)
            f[i] = max(f[i - 3], f[i]);
    }
    cout << f[n] << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    get T;
    while (T--)
    {
        solve();
    }
    return 0;
}