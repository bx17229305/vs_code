#include <iostream>
#include <algorithm>
using namespace std;
using ll = unsigned long long;

ll k, b, c, v;

// 统计满足 kx + b <= upper 的非负整数x的数量
ll count_x(ll upper) {
    if (b > upper) return 0;
    ll max_x = (upper - b) / k;
    if (max_x < 0) return 0;
    return max_x + 1; // x从0到max_x
}

void solve() {
    cin >> k >> b >> c >> v;
    ll res = 0;
    ll prefix = 0; // 已确定的高位前缀

    for (int i = 63; i >= 0; --i) {
        int bit_v = (v >> i) & 1;
        int bit_c = (c >> i) & 1;
        ll mask = 1ULL << i;

        // 尝试将当前位设为0或1
        for (int bit = 0; bit <= 1; ++bit) {
            ll new_prefix = prefix | (bit << i);
            ll px = k * new_prefix + b;
            if ((px ^ c) > v) continue; // 超出限制，跳过

            // 当前位异或结果是否严格小于v的对应位？
            if ((bit ^ bit_c) < bit_v) {
                // 后面可以任取，直接统计
                ll upper = new_prefix | ((1ULL << i) - 1);
                res += count_x(upper) - count_x(new_prefix - 1);
            } else {
                // 需要进一步限制后面的位
                prefix = new_prefix;
                break;
            }
        }
    }

    // 检查最终prefix是否满足条件
    if ((k * prefix + b ^ c) <= v) {
        res += count_x(prefix) - count_x(prefix - 1);
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}