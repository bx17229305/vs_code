#include "bits/stdc++.h"
#include <iostream>
using namespace std;
using ll = long long;
const int N = 3e3 + 10;
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

ll a[N];
ll ps[N];
ll smx[N], pmx[N];
void solve()
{
    cin >> n;
    rp(i, 1, n)
    {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    smx[n + 1] = 0;
    rp(k, 1, n - 2)
    {
        ll res = 0;
        pr(i, n, 1)
        {
            if (n - i + 1 < k)
                smx[i] = 0;
            else
                smx[i] = max(smx[i + 1], ps[i + k - 1] - ps[i - 1]);
        }
        rp(i, 1, n)
        {
            if (i - k >= 0)
                pmx[i] = max(pmx[i - 1], ps[i] - ps[i - k]);
            else
                pmx[i] = 0;
        }
        rp(i, 1, n)
        {
            res = max(res, max(pmx[i - 1], smx[i + 1]) - a[i]);
        }
        cout << res << " ";
    }
    cout << max(ps[n] - a[1] - a[1], ps[n - 1] - a[n]) << " 0\n";
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