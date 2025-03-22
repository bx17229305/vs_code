#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int n, q, k;
int st[N], dfn[N], siz[N], fa[N], top[N], bigson[N],dep[N],stk[N], id;
int head[N], nex[N<<1], to[N<<1], cnt;
int res;

void add(int u, int v) {
    nex[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

void dfs1(int u, int f) {
    fa[u] = f;
    dfn[u] = ++id;
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    int w = 0;
    for (int ei = head[u]; ei; ei = nex[ei]) {
        int v = to[ei];
        if (v != f) {
            dfs1(v, u);
            siz[u] += siz[v];
            if (siz[v] > w) {
                bigson[u] = v;
                w = siz[v];
            }
        }
    }
}

void dfs2(int u, int h) {
    top[u] = h;
    if (bigson[u] != -1) dfs2(bigson[u], h);
    for (int ei = head[u]; ei; ei = nex[ei]) {
        int v = to[ei];
        if (v != fa[u] && v != bigson[u]) dfs2(v, v);
    }
}

int LCA(int a, int b) {
    while (top[a] != top[b]) {
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        a = fa[top[a]];
    }
    return dep[a] < dep[b] ? a : b;
}

void create() {
    sort(st + 1, st + k + 1, [](int a, int b) { return dfn[a] < dfn[b]; });
    int tp = 0;
    stk[++tp] = 1;
    for (int i = 1; i <= k; i++) {
        if (st[i] == 1) continue;
        int lca = LCA(st[i], stk[tp]);
        if (lca != stk[tp]) {
            while (tp > 1 && dep[stk[tp - 1]] >= dep[lca]) {
                add(stk[tp], stk[tp - 1]);
                tp--;
            }
            if (stk[tp - 1] != lca) {
                add(lca, stk[tp]);
                stk[tp] = lca;
            } else {
                add(stk[tp], stk[tp - 1]);
                tp--;
            }
        }
        stk[++tp] = st[i];
    }
    while (tp > 1) {
        add(stk[tp], stk[tp - 1]);
        tp--;
    }
}

int dp(int u) {
    int sum = 0;
    for (int ei = head[u]; ei; ei = nex[ei]) {
        int v = to[ei];
        sum += dp(v);
    }
    if (siz[u]) {
        res += sum;
        return 1;
    } else {
        if (sum > 1) {
            res++;
            return 0;
        }
        return sum;
    }
}

void cle1() {
    cnt = 0;
    fill(head, head + n + 1, 0);
}

void solve() {
    cin >> n;
    cle1();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    cin >> q;
    while (q--) {
        cin >> k;
        siz[1] = 0;
        for (int i = 1; i <= k; i++) {
            cin >> st[i];
            siz[st[i]] = 1;
        }
        bool tag = true;
        for (int i = 1; i <= k; i++) {
            if (siz[fa[st[i]]]) {
                cout << -1 << endl;
                tag = false;
                break;
            }
        }
        if (tag) {
            sort(st + 1, st + k + 1, [](int a, int b) { return dfn[a] < dfn[b]; });
            create();
            res = 0;
            dp(1);
            cout << res << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}