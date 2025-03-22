#include "bits/stdc++.h"
#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
int n, t, m, k;
int a[N];
const int P = 20;
int st[N][P + 1], dep[N];
int cnt;
int h[N];
int stk[N];
int isk[N];
int fa[N];
int dfn[N];
int tag;
int id;
struct Edge
{
    int v, nx;
} e[N * 2];

void add(int u, int v)
{
    e[++cnt] = {v, h[u]};
    h[u] = cnt;
}

void dfs1(int u, int f)
{
    fa[u] = f;
    dep[u] = dep[f] + 1;
    st[u][0] = f;
    dfn[u] = ++id;
    for (int i = 1; i <= P; i++)
    {
        st[u][i] = st[st[u][i - 1]][i - 1];
    }

    for (int ei = h[u]; ei; ei = e[ei].nx)
    {
        int v = e[ei].v;
        if (v == f)
            continue;
        dfs1(v, u);
    }
}

int getlca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b);
    for (int i = P; i >= 0; i--)
    {
        if (dep[st[a][i]] >= dep[b])
            a = st[a][i];
    }
    if (a == b)
        return a;
    for (int i = P; i >= 0; i--)
    {
        if (st[a][i] != st[b][i])
        {
            a = st[a][i];
            b = st[b][i];
        }
    }
    return st[a][0];
}

bool cmp(int a, int b)
{
    return dfn[a] < dfn[b];
}

void build()
{
    cnt = 0;
    int tp = 0;
    sort(a, a + k, cmp);
    stk[++tp] = 1;
    if (a[0] != 1)
        stk[++tp] = a[0];
    for (int i = 1; i < k; i++)
    {
        int lca = getlca(a[i], stk[tp]);
        if (lca == stk[tp])
            stk[++tp] = a[i];
        else
        {
            while (tp > 1 && dep[stk[tp - 1]] >= dep[lca])
            {
                add(stk[tp - 1], stk[tp]);
                tp--;
            }
            if (stk[tp] != lca)
            {
                add(lca, stk[tp]);
                stk[tp] = lca;
                stk[++tp] = a[i];
            }
        }
    }
    while (tp > 1)
    {
        add(stk[tp - 1], stk[tp]);
        tp--;
    }
}

int dfs(int u, int f)
{
    int sum = 0;
    if (isk[u])
    {
        for (int ei = h[u]; ei; ei = e[ei].nx)
        {
            int v = e[ei].v;
            if (v == f)
                continue;
            sum += dfs(v, u);
            if (isk[u] && isk[v] && fa[v] == u)
                tag = 0;
            if (isk[v])
                sum++;
            isk[v] = 0;
        }
    }
    else
    {
        int c = 0;
        for (int ei = h[u]; ei; ei = e[ei].nx)
        {
            int v = e[ei].v;
            if (v == f)
                continue;
            if (isk[u] && isk[v] && fa[v] == u)
                tag = 0;
            sum += dfs(v, u);
            if (isk[v])
                c++;
            isk[v] = 0;
        }
        if (c > 1)
            sum++;
    }
    h[u] = 0;
    return sum;
}

void solve()
{
    cin >> n;
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dep[0] = 0;
    for (int i = 0; i <= P; i++)
    {
        st[0][i] = 0;
    }
    dfs1(1, 0);
    int q;
    cin >> q;
    memset(h, 0, sizeof h);
    while (q--)
    {
        cin >> k;
        isk[1] = 0;
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &a[i]);
            isk[a[i]] = 1;
        }
        build();
        tag = 1;
        int res = dfs(1, 0);
        if (!tag)
            cout << -1 << "\n";
        else
            cout << res << "\n";
    }
}

int main()
{

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}