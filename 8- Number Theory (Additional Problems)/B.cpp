#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

map<char, int> mp;
map<pair<int, int>, int> classes;
int want[6];

void solve() {
    int h, w;
    cin >> h >> w;
    int g = gcd(h, w);
    vector<vector<int> > grid(h, vector(w, 0));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            char x;
            cin >> x;
            grid[i][j] = mp[x];
        }

    auto get_class = [](int i, int j) {
        return classes[{min(i, j), max(i, j)}];
    };

    bool ans = false;
    for (int wid = 1; wid <= w; wid++) {
        for (int j = 0; j <= w - wid; j++) {
            vector<vector<int> > seen(g, vector(6, 0));
            for (int i = 0; i < h; i++) {
                if (grid[i][j] == grid[i][j + wid - 1]) continue;
                int c = get_class(grid[i][j], grid[i][j + wid - 1]);
                seen[i % g][c] = 1;
            }

            for (int res = 0; res < g; res++)
                for (int c = 0; c < 6; c++) {
                    if (!seen[res][c]) continue;
                    int x = (res - wid % g + 1 + g) % g;
                    ans |= seen[x][want[c]];
                }
        }
    }

    cout << (ans ? "possible" : "impossible");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    int c = 0;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++) classes[{i, j}] = c++;

    for (auto [p, cc] : classes) {
        auto [i, j] = p;
        vector<int> rem;
        for (int k = 0; k < 4; k++)
            if (k != i && k != j) rem.push_back(k);

        want[cc] = classes[{rem[0], rem[1]}];
    }
    mp['r'] = 0;
    mp['g'] = 1;
    mp['b'] = 2;
    mp['w'] = 3;
    // cin >>t;
    while (t--) solve();
}
