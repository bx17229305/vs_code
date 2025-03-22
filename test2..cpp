
#include "bits/stdc++.h"
#include <iostream>
using namespace std;
#define int long long
using ll = long long;
const int N = 100;
int mod = 1e9 + 7;
int n, m, k;
#define get cin >>
#define ex cout <<
#define rep(i, j, k) for (int i = j; i <= k; i++)
#define per(i, j, k) for (int i = j; i >= k; i--)
#define pb push_back
int inv2 = (mod + 1) / 2;

struct Node
{
    int requ, i;
    bool operator<(const Node &o) const
    {
        return requ > o.requ;
    }
};

void solve()
{
    get n >> m;
    vector<int> a(m + 1);
    vector<int> diff(n + 1);
    vector<vector<int>> c(n + 1, vector<int>(m + 1));
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    rep(i, 1, m)
    {
        get a[i];
    }
    rep(i, 1, n)
    {
        rep(j, 1, m)
            get b[i][j];
        rep(j, 1, m)
            get c[i][j];
    }

    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            diff[i] += a[j] < b[i][j];
        }
    }
    queue<int> q;
    vector<priority_queue<Node>> heap(m + 1);
    rep(i, 1, n)
    {
        if (diff[i] == 0)
            q.push(i);
        else
        {
            rep(j, 1, m)
            {
                heap[j].push({b[i][j], i});
            }
        }
    }

    int cnt = 0;
    while (q.size())
    {
        int siz = q.size();
        cnt += siz;
        while (siz--)
        {
            int u = q.front();
            q.pop();
            rep(j, 1, m)
                a[j] += c[u][j];
        }
        rep(j, 1, m)
        {
            auto &pq = heap[j];
            while (pq.size() and pq.top().requ <= a[j])
            {
                if (--diff[pq.top().i] == 0)
                    q.push(pq.top().i);
                pq.pop();
            }
        }
    }
    if (cnt == n)
        ex "YES";
    else
        ex "NO";
    ex "\n";
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