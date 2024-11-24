#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const char el = '\n', sp = ' ';

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> primes, p(n + 1), lpf(n + 1);
    for (int i = 2; i <= n; i++)
        if (!p[i]) {
            primes.push_back(i);
            lpf[i] = i;
            for (int j = 2 * i; j <= n; j += i) p[j] = 1, lpf[j] = i;
        }

    auto ask = [](int x) {
        cout << "? " << x << endl;
        int res;
        cin >> res;
        return res;
    };

    vector<int> cnt(n + 1);
    cnt[1] = 1;
    for (int i : primes) cnt[i] = ask(i);

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        vector<int> facs;
        int tmp = i;
        while (tmp != 1) {
            int pr = lpf[tmp];
            while (lpf[tmp] == pr) tmp /= pr;
            facs.push_back(pr);
        }

        for (int mask = 0; mask < 1 << facs.size(); mask++) {
            int d = 1, c = 1;
            for (int j = 0; j < facs.size(); j++)
                if (mask >> j & 1) d *= facs[j], c *= cnt[facs[j]];
            if (__popcount(mask) & 1)
                ans[i] -= c * i / d;
            else
                ans[i] += c * i / d;
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) cout << ans[i] << sp;
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
