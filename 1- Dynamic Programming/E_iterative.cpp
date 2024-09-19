#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e3;

int curr[N], nxt[N];;
string grid[N];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> grid[i];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j] == '*') {
                nxt[j] = 0;
                continue;
            }
            if (i == n - 1 && j == n - 1) {
                nxt[j] = 1;
                continue;
            }
            int res = 0;
            // move down
            if (i + 1 < n) res = curr[j]; // i + 1, j
            // move right
            if (j + 1 < n) res += nxt[j + 1], res %= mod; // i, j + 1
            nxt[j] = res;
        }
        swap(curr, nxt);
    }
    cout << curr[0];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
