#include <bits/stdc++.h>

#define all(a) begin(a), end(a)
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x,y)

using namespace std ;
using ll = long long;

const char nl = '\n', sp = ' ';
const ll INF = 1e18 +16;

void solve(){
    // iterative solution
    int n , weight;
    cin >> n >> weight;

    int w [n] , v [n] , sum = 0;
    for (int i = 0 ; i < n ; i ++){
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    ll dp [n][sum +1];
    
    fill(dp[0] , dp[0] + sum +1 , INF);
    dp[0][0] = 0 , dp[0][v[0]] = w[0];
    
    for (int i = 1 ; i < n ; i ++){
        for (int j = 0 ; j <= sum ; j ++){
            dp[i][j] = dp[i -1][j];
            if (v[i] <= j)
                dp[i][j] = min(dp[i][j] , dp[i -1][j - v[i]] + w[i]);
        }
    }
    
    for (int val = sum ; val >= 0 ; val --){
        if (dp[n -1][val] <= weight){
            cout << val;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../in.txt" , "r" , stdin);
    freopen("../out.txt" , "w" , stdout);
#endif
    solve();
    return 0;
}
