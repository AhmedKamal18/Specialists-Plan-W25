#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1000;

int twos[N][N], fives[N][N], memo_twos[N][N], memo_fives[N][N];

int n;

int dp_twos(int i, int j) {
    if (i == n - 1 && j == n - 1) return twos[i][j];
    if (memo_twos[i][j] != -1) return memo_twos[i][j];
    int res = 1e9;
    if (i + 1 < n) res = twos[i][j] + dp_twos(i + 1, j);
    if (j + 1 < n) res = min(res, twos[i][j] + dp_twos(i, j + 1));
    return memo_twos[i][j] = res;
}

int dp_fives(int i, int j) {
    if (i == n - 1 && j == n - 1) return fives[i][j];
    if (memo_fives[i][j] != -1) return memo_fives[i][j];
    int res = 1e9;
    if (i + 1 < n) res = fives[i][j] + dp_fives(i + 1, j);
    if (j + 1 < n) res = min(res, fives[i][j] + dp_fives(i, j + 1));
    return memo_fives[i][j] = res;
}

string res;

void trace_twos(int i, int j) {
    if (i == n - 1 && j == n - 1) return;
    if (i + 1 < n && dp_twos(i, j) == twos[i][j] + dp_twos(i + 1, j))
        res.push_back('D'), trace_twos(i + 1, j);
    else
        res.push_back('R'), trace_twos(i, j + 1);
}

void trace_fives(int i, int j) {
    if (i == n - 1 && j == n - 1) return;
    if (i + 1 < n && dp_fives(i, j) == fives[i][j] + dp_fives(i + 1, j))
        res.push_back('D'), trace_fives(i + 1, j);
    else
        res.push_back('R'), trace_fives(i, j + 1);
}

void solve() {
    cin >> n;
    int zr = -1, zc = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 0) {
                twos[i][j] = fives[i][j] = 1;
                zr = i, zc = j;
                continue;
            }
            int pw = 0;
            while (x % 2 == 0) pw++, x /= 2;
            twos[i][j] = pw;
            pw = 0;
            while (x % 5 == 0) pw++, x /= 5;
            fives[i][j] = pw;
        }

    memset(memo_twos, -1, sizeof memo_twos);
    memset(memo_fives, -1, sizeof memo_fives);
    int ans = 0;
    if (zr != -1 && zc != -1 && min(dp_twos(0, 0), dp_fives(0, 0)) > 1) {
        ans = 1;
        int dx = zc, dy = zr;
        while (dx--) res.push_back('R');
        while (dy--) res.push_back('D');
        dx = n - 1 - zc, dy = n - 1 - zr;
        while (dx--) res.push_back('R');
        while (dy--) res.push_back('D');
    } else {
        ans = min(dp_twos(0, 0), dp_fives(0, 0));
        if (dp_twos(0, 0) < dp_fives(0, 0))
            trace_twos(0, 0);
        else
            trace_fives(0, 0);
    }
    cout << ans << el;
    cout << res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
