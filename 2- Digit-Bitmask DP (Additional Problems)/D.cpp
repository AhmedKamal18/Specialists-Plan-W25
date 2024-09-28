#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 16;
const ll inf = 1e18;
int n;
ll a[N][N], cost[1 << N];

void pre(int n) {
    for (int mask = 0; mask < 1 << n; mask++) {
        cost[mask] = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                for (int j = i + 1; j < n; j++) 
                    if (mask & (1 << j))
                         cost[mask] += a[i][j];
    }
}

ll dp[1 << N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    pre(n);
    dp[0] = 0;
    for (int mask = 1; mask < 1 << n; mask++) {
        ll res = -inf;
        for (int s = mask; s; s = (s - 1) & mask)
            res = max(res, cost[s] + dp[mask ^ s]);
        dp[mask] = res;
    }
    cout << dp[(1 << n) - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
