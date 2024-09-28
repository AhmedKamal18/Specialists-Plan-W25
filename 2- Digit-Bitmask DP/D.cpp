#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> a, b;
ll dp[2][2][2][20];

ll go(int down, int up, int lz, int i) {
    if (i == a.size()) return 1;
    ll &ans = dp[down][up][lz][i];
    if (ans != -1) return ans;
    ans = 0;
    int lo = (down ? a[i] : 0), hi = (up ? b[i] : 9);
    for (int d = lo; d <= hi; d++) {
        ll p = (lz && d == 0 ? 1 : d);
        ans = max(ans, p * go(down && d == lo, up && d == hi, lz && d == 0, i + 1));
    }
    return ans;
}

string s;
void trace(int down, int up, int lz, int i) {
    if (i == a.size()) return;
    int lo = (down ? a[i] : 0), hi = (up ? b[i] : 9);
    ll ans = 0, x = 0;
    for (int d = lo; d <= hi; d++) {
        ll p = (lz && d == 0 ? 1 : d);
        ll nxt = p * go(down && d == lo, up && d == hi, lz && d == 0, i + 1);
        if (nxt >= ans) ans = nxt, x = d;
    }
    if (!lz || x != 0) s += char(x + '0');
    trace(down && x == lo, up && x == hi, lz && x == 0, i + 1);
}

void solve() {
    ll l, r;
    cin >> l >> r;
    while (l) a.push_back(l % 10), l /= 10;
    while (r) b.push_back(r % 10), r /= 10;
    while (a.size() < b.size()) a.push_back(0);
    reverse(begin(a), end(a));
    reverse(begin(b), end(b));
    memset(dp, -1, sizeof dp);

    trace(1, 1, 1, 0);
    cout << s << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
