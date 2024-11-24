#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 3e6;

ull f[N + 1], ans[N + 1];

void pre() {
    for (int i = 1; i <= N; i++) f[i] = i;

    for (int i = 2; i <= N; i++)
        if (f[i] == i)
            for (int j = i; j <= N; j += i) f[j] -= f[j] / i;

    for (int i = 2; i <= N; i++) f[i] *= i, f[i] /= 2;

    for (int i = 1; i <= N; i++)
        for (int j = 2 * i; j <= N; j += i) ans[j] += j * f[j / i];
    for (int i = 1; i <= N; i++) ans[i] += ans[i - 1];
}

int tc = 1;

void solve() {
    int n;
    cin >> n;
    cout << "Case " << tc << ": " << ans[n] << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    int t;
    cin >> t;
    while (t--) solve(), tc++;
}
