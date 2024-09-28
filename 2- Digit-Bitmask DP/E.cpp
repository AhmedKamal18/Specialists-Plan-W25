#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 10;

int n, m;
vector<int> s;
ll memo[N][N];

ll dp(int idx, int prv) {
    if (idx == n) return 1;
    if (memo[idx][prv] != -1) return memo[idx][prv];
    ll res = 0;
    for (int i = 0; i < m; i++)
        if (abs(s[i] - s[prv]) <= 2) res += dp(idx + 1, i);
    return memo[idx][prv] = res;
}

int tc = 1;

void solve() {
    cin >> m >> n;
    s = vector(m, 0);
    for (int &x: s) cin >> x;
    memset(memo, -1, sizeof memo);
    ll res = 0;
    for (int i = 0; i < m; i++) res += dp(1, i);

    cout << "Case " << tc << ": " << res << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve(), tc++;
}
