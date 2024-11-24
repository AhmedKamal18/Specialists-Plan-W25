#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e6 + 1;

ll phi[N + 1], ans[N + 1];

void pre() {
    for (int i = 1; i <= N; i++) phi[i] = i;
    for (int i = 2; i <= N; i++)
        if (phi[i] == i)
            for (int j = i; j <= N; j += i) phi[j] -= phi[j] / i;
    for (int i = 1; i <= N; i++)
        for (int j = 2 * i; j <= N; j += i) ans[j] += i * phi[j / i];
    for (int i = 1; i <= N; i++) ans[i] += ans[i - 1];
}

void solve(int n) { cout << ans[n] << el; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        solve(n);
    }
}
